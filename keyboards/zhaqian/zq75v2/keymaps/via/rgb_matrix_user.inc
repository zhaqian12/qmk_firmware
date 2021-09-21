RGB_MATRIX_EFFECT(FPS_CYCLE)
RGB_MATRIX_EFFECT(FPS_BREATHING)
RGB_MATRIX_EFFECT(MOBA_CYCLE)
RGB_MATRIX_EFFECT(MOBA_BREATHING)
RGB_MATRIX_EFFECT(CANDY_TAP)
RGB_MATRIX_EFFECT(CANDY_NEXUS)
RGB_MATRIX_EFFECT(FRACTAL)
RGB_MATRIX_EFFECT(FRACTAL_RGB)
RGB_MATRIX_EFFECT(kitt_effect)
RGB_MATRIX_EFFECT(CYCLE_BREATHING)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

typedef HSV (*fps_f)(HSV hsv, uint8_t i, uint8_t time);

bool effect_runner_FPS(effect_params_t* params, fps_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t time = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed / 4, 1));
    for (uint8_t i = led_min; i <= led_max; i++) {
        if (i == 41 || (i >= 53 && i <= 55) || i == 69 || i == 80 || (i >= 75 && i <= 77) || (i >= 81 && i <= 98)){
            RGB_MATRIX_TEST_LED_FLAGS();
            RGB rgb = rgb_matrix_hsv_to_rgb(effect_func(rgb_matrix_config.hsv, i, time));
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        } else{
            rgb_matrix_set_color(i, 0, 0, 0);
        }  
    }
    return led_max < DRIVER_LED_TOTAL;
}

static HSV FPS_CYCLE_math(HSV hsv, uint8_t i, uint8_t time) {
    hsv.h = g_led_config.point[i].x - time;
    return hsv;
}

bool FPS_CYCLE(effect_params_t* params) { return effect_runner_FPS(params, &FPS_CYCLE_math); }

static HSV FPS_math(HSV hsv, uint8_t i, uint8_t time) {
    hsv.h = time;
    return hsv;
}

bool FPS_BREATHING(effect_params_t* params) { return effect_runner_FPS(params, &FPS_math); }

bool effect_runner_MOBA(effect_params_t* params, fps_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t time = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed / 4, 1));
    for (uint8_t i = led_min; i <= led_max; i++) {
        if ((i >= 39 && i <= 42) || (i >= 52 && i <= 53) || (i >= 81 && i <= 98)){
            RGB_MATRIX_TEST_LED_FLAGS();
            RGB rgb = rgb_matrix_hsv_to_rgb(effect_func(rgb_matrix_config.hsv, i, time));
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        } else{
            rgb_matrix_set_color(i, 0, 0, 0);
        }  
    }
    return led_max < DRIVER_LED_TOTAL;
}

bool MOBA_CYCLE(effect_params_t* params) { return effect_runner_MOBA(params, &FPS_CYCLE_math); }

bool MOBA_BREATHING(effect_params_t* params) { return effect_runner_MOBA(params, &FPS_math); }

static bool CANDY_TAP(effect_params_t* params) {
	HSV CANDY_TAP_math(HSV hsv, uint16_t offset) {
		hsv.v = scale8(255 - offset, hsv.v);
		hsv.h = mod8(scale16by8(g_rgb_timer, add8(rgb_matrix_config.speed >> 5, 1)), 255);
		return hsv;
	}
	return effect_runner_reactive(params, &CANDY_TAP_math);
}

static bool CANDY_NEXUS(effect_params_t* params) {
	HSV CANDY_NEXUS_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
		uint16_t effect = tick - dist;
		if (effect > 255) effect = 255;
		if (dist > 72) effect = 255;
		if ((dx > 8 || dx < -8) && (dy > 8 || dy < -8)) effect = 255;
		hsv.v = qadd8(hsv.v, 255 - effect);
		hsv.h = mod8(scale16by8(g_rgb_timer, add8(rgb_matrix_config.speed >> 5, 1)), 255) + dy / 4;
		return hsv;
	}
	return effect_runner_reactive_splash(0, params, &CANDY_NEXUS_math);
}

uint8_t jsf8(void) { // Bob Jenkin's fast prng
	static uint8_t a = 161, b = 62, c = 21, d = 97, t;
	t = a - ((b << 1)|(b >> 7));
	a = b ^ ((c << 4)|(c >> 4));
	b = c + d; c = d + t;
	return d = t + a;
}

uint32_t f_timer = 0;

uint8_t halfArray[6][4];
uint8_t fullArray[12][4];
uint8_t halfbottom[3];
uint8_t fullbottom[6];
uint8_t displArray[54];

static bool FRACTAL(effect_params_t* params) {
	uint16_t f_speed = (400 / rgb_matrix_config.speed) * 127;

	if (f_timer > g_rgb_timer) return false;

	if (params->init) srand(g_rgb_timer);

	HSV hsv = rgb_matrix_config.hsv;
	RGB rgb = hsv_to_rgb(hsv);
	RGB_MATRIX_USE_LIMITS(led_min, led_max);
	for (int j = led_min; j < led_max; j++) {
		int i = j > 41 ? j + 1 : j;
		if (displArray[i]) rgb_matrix_set_color(j, rgb.r, rgb.g, rgb.b);
		else rgb_matrix_set_color(j, 0x00, 0x00, 0x00);
	}

	if (led_max == DRIVER_LED_TOTAL) {
		f_timer = g_rgb_timer + f_speed;

		// move columns
		for (uint8_t col = 5; col > 0; col--) {
			for (uint8_t row = 0; row < 4; row++) {
				halfArray[col][row] = halfArray[col-1][row];
			}
		}
		//bottom
		for (uint8_t col = 2; col > 0; col--) {
			halfbottom[col] = halfbottom[col-1];
		}

		// random fill first column
		for (uint8_t row = 0; row < 4; row++) {
			halfArray[0][row] = rand() % 2;
		}
		// bottom
		halfbottom[0] = rand() % 2;

		// transfer to big array
		for (uint8_t col = 0; col < 6; col++) {
			for (uint8_t row = 0; row < 4; row++){
				fullArray[5 - col][row] = halfArray[col][row];
				fullArray[6 + col][row] = halfArray[col][row];
			}
		}
		//bottom
		for (uint8_t col = 0; col < 3; col++){
			fullbottom[2 - col] = halfbottom[col];
			fullbottom[3 + col] = halfbottom[col];
		}

		// transfer to matrix array
		uint8_t k = 0;
		for (uint8_t row = 0; row < 4; row++) {
			for (uint8_t col = 0; col < 12; col++) {
				displArray[k] = fullArray[col][row];
				k++;
			}
		}
		//bottom
		uint8_t l = 48;
		for (uint8_t col = 0; col < 6; col++) {
			displArray[l] = fullbottom[col];
			l++;
		}
	}

	return led_max < DRIVER_LED_TOTAL;
}

uint32_t frgb_timer = 0;

uint8_t rgb_halfArray[6][4];
uint8_t rgb_fullArray[12][4];
uint8_t rgb_halfbottom[3];
uint8_t rgb_fullbottom[6];
uint8_t rgb_displArray[54];

static bool FRACTAL_RGB(effect_params_t* params) {
	uint16_t frgb_speed = (400 / rgb_matrix_config.speed) * 127;

	if (frgb_timer > g_rgb_timer) return false;

	if (params->init) srand(g_rgb_timer);

/*	HSV hsv  = rgb_matrix_config.hsv;
	hsv.h += frgb_timer;
	RGB rgb = hsv_to_rgb(hsv); */

	RGB_MATRIX_USE_LIMITS(led_min, led_max);
	for (int j = led_min; j < led_max; j++) {
		int i = j > 41 ? j + 1 : j;
		if (rgb_displArray[i]) {
			HSV hsv  = rgb_matrix_config.hsv;
			// hsv.h += g_led_config.point[i].x * 2 + g_rgb_timer/frgb_speed;
			hsv.h += g_led_config.point[i].x;
			RGB rgb = hsv_to_rgb(hsv);
			rgb_matrix_set_color(j, rgb.r, rgb.g, rgb.b);
		} else {
			rgb_matrix_set_color(j, 0x00, 0x00, 0x00);
		}
	}

	if (led_max == DRIVER_LED_TOTAL) {
		frgb_timer = g_rgb_timer + frgb_speed;

		// move columns
		for (uint8_t col = 5; col > 0; col--) {
			for (uint8_t row = 0; row < 4; row++) {
				rgb_halfArray[col][row] = rgb_halfArray[col-1][row];
			}
		}
		//bottom
		for (uint8_t col = 2; col > 0; col--) {
			rgb_halfbottom[col] = rgb_halfbottom[col-1];
		}

		// random fill first column
		for (uint8_t row = 0; row < 4; row++) {
			rgb_halfArray[0][row] = rand() % 2;
		}
		// bottom
		rgb_halfbottom[0] = rand() % 2;

		// transfer to big array
		for (uint8_t col = 0; col < 6; col++) {
			for (uint8_t row = 0; row < 4; row++){
				rgb_fullArray[5 - col][row] = rgb_halfArray[col][row];
				rgb_fullArray[6 + col][row] = rgb_halfArray[col][row];
			}
		}
		//bottom
		for (uint8_t col = 0; col < 3; col++){
			rgb_fullbottom[2 - col] = rgb_halfbottom[col];
			rgb_fullbottom[3 + col] = rgb_halfbottom[col];
		}

		// transfer to matrix array
		uint8_t k = 0;
		for (uint8_t row = 0; row < 4; row++) {
			for (uint8_t col = 0; col < 12; col++) {
					rgb_displArray[k] = rgb_fullArray[col][row];
					k++;
			}
		}
		//bottom
		uint8_t l = 48;
		for (uint8_t col = 0; col < 6; col++) {
			rgb_displArray[l] = rgb_fullbottom[col];
			l++;
		}
	}

	return led_max < DRIVER_LED_TOTAL;
}

typedef HSV (*snake_f)(HSV hsv, uint8_t i, uint8_t time);

bool effect_runner_s(effect_params_t* params, snake_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t time = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed / 16, 1));
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        RGB rgb = rgb_matrix_hsv_to_rgb(effect_func(rgb_matrix_config.hsv, i, time));
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

bool kitt_effect(effect_params_t* params) {

	static uint8_t k_led_count = 81;
	static uint8_t k_led_first = 0;

	uint8_t time_to_led(uint8_t time, uint8_t led_behind) {
		uint16_t led_time = k_led_count * time;
		uint16_t step = ((2 * k_led_count + (led_time / 128)) - led_behind) % (2 * k_led_count);
		uint8_t led;
		if (step < k_led_count) {
			led = step;
		} else {
			led = k_led_count - 1 - (step - k_led_count);
		}
		return led;
	}

	HSV kitt_effect_math(HSV hsv, uint8_t i, uint8_t time) {
		hsv.h = time;

		if (i >= k_led_first && i < k_led_first + k_led_count) {
			uint8_t j = i - k_led_first;
			if (j == time_to_led(time, 0)) {
				hsv.v = hsv.v;
			} else if (j == time_to_led(time, 1)) {
				hsv.v = hsv.v/2;
			} else if (j == time_to_led(time, 2)) {
				hsv.v = hsv.v/4;
			} else if (j == time_to_led(time, 3)) {
				hsv.v = hsv.v/8;
			} else {
				hsv.v = 0;
			}
		} else {
			hsv.v = 0;
		}
		return hsv;
	}

	return effect_runner_s(params, &kitt_effect_math);
}

typedef HSV (*cb_f)(HSV hsv, uint8_t time);

bool effect_runner_cb(effect_params_t* params, cb_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
	uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
    HSV hsv  = effect_func(rgb_matrix_config.hsv, time);
    hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
    RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
	
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

static HSV CYCLE_BREATHING_math(HSV hsv, uint8_t time) {
    hsv.h = time;
    return hsv;
}

bool CYCLE_BREATHING(effect_params_t* params) { return effect_runner_cb(params, &CYCLE_BREATHING_math); }

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
