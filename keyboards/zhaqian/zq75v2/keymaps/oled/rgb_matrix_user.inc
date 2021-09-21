RGB_MATRIX_EFFECT(CYCLE_BREATHING)
RGB_MATRIX_EFFECT(CYCLE_BANDVAL)
RGB_MATRIX_EFFECT(CYCLE_BAND_PINWHEEL_SAT)
RGB_MATRIX_EFFECT(CYCLE_BAND_PINWHEEL_VAL)
RGB_MATRIX_EFFECT(CYCLE_BAND_SPIRAL_SAT)
RGB_MATRIX_EFFECT(CYCLE_BAND_SPIRAL_VAL)
RGB_MATRIX_EFFECT(CYCLE_RIGHT_LEFT)
RGB_MATRIX_EFFECT(CYCLE_DOWN_UP)
RGB_MATRIX_EFFECT(FRACTAL)
RGB_MATRIX_EFFECT(FRACTAL_RGB)
RGB_MATRIX_EFFECT(KITT_EFFECT)
RGB_MATRIX_EFFECT(FPS_BREATHING)
RGB_MATRIX_EFFECT(MOBA_BREATHING)
RGB_MATRIX_EFFECT(CANDY_TAP)
RGB_MATRIX_EFFECT(CYCLE_REACTIVE_WIDE)
RGB_MATRIX_EFFECT(CYCLE_REACTIVE_MULTIWIDE)
RGB_MATRIX_EFFECT(CYCLE_REACTIVE_MULTICROSS)
RGB_MATRIX_EFFECT(CYCLE_REACTIVE_MULTINEXUS)
RGB_MATRIX_EFFECT(CYCLE_MULTISPLASH)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

typedef HSV (*fps_f)(HSV hsv, uint8_t i, uint8_t time);

typedef HSV (*cb_f)(HSV hsv, uint8_t time);

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

bool effect_runner_FPScb(effect_params_t* params, cb_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
	uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
    HSV hsv  = effect_func(rgb_matrix_config.hsv, time);
    hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
    RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
		if (i == 41 || (i >= 53 && i <= 55) || i == 69 || i == 80 || (i >= 75 && i <= 77) || (i >= 81 && i <= 98)){
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

static HSV FPS_math(HSV hsv, uint8_t time) {
    hsv.h = time;
    return hsv;
}

bool FPS_BREATHING(effect_params_t* params) { return effect_runner_FPScb(params, &FPS_math); }

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

bool effect_runner_MOBAcb(effect_params_t* params, cb_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
	uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
    HSV hsv  = effect_func(rgb_matrix_config.hsv, time);
    hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
    RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
		if ((i >= 39 && i <= 42) || (i >= 52 && i <= 53) || (i >= 81 && i <= 98)){
            RGB_MATRIX_TEST_LED_FLAGS();
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        } else{
            rgb_matrix_set_color(i, 0, 0, 0);
        }  
    }
    return led_max < DRIVER_LED_TOTAL;
}

bool MOBA_CYCLE(effect_params_t* params) { return effect_runner_MOBA(params, &FPS_CYCLE_math); }

bool MOBA_BREATHING(effect_params_t* params) { return effect_runner_MOBAcb(params, &FPS_math); }

static bool CANDY_TAP(effect_params_t* params) {
	HSV CANDY_TAP_math(HSV hsv, uint16_t offset) {
		hsv.v = scale8(255 - offset, hsv.v);
		hsv.h = mod8(scale16by8(g_rgb_timer, add8(rgb_matrix_config.speed >> 5, 1)), 255);
		return hsv;
	}
	return effect_runner_reactive(params, &CANDY_TAP_math);
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

bool KITT_EFFECT(effect_params_t* params) {

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

static HSV CYCLE_BANDVAL_math(HSV hsv, uint8_t i, uint8_t time) {
    int16_t v = hsv.v - abs(scale8(g_led_config.point[i].x, 228) + 28 - time) * 8;
    hsv.v     = scale8(v < 0 ? 0 : v, hsv.v);
	hsv.h = time;
    return hsv;
}

bool CYCLE_BANDVAL(effect_params_t* params) { return effect_runner_i(params, &CYCLE_BANDVAL_math); }

static HSV CYCLE_BAND_PINWHEEL_SAT_math(HSV hsv, int16_t dx, int16_t dy, uint8_t time) {
    hsv.s = scale8(hsv.s - time - atan2_8(dy, dx) * 3, hsv.s);
	hsv.h = time;
    return hsv;
}

bool CYCLE_BAND_PINWHEEL_SAT(effect_params_t* params) { return effect_runner_dx_dy(params, &CYCLE_BAND_PINWHEEL_SAT_math); }

static HSV CYCLE_BAND_PINWHEEL_VAL_math(HSV hsv, int16_t dx, int16_t dy, uint8_t time) {
    hsv.v = scale8(hsv.v - time - atan2_8(dy, dx) * 3, hsv.v);
	hsv.h = time;
    return hsv;
}

bool CYCLE_BAND_PINWHEEL_VAL(effect_params_t* params) { return effect_runner_dx_dy(params, &CYCLE_BAND_PINWHEEL_VAL_math); }

static HSV CYCLE_BAND_SPIRAL_SAT_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint8_t time) {
    hsv.s = scale8(hsv.s + dist - time - atan2_8(dy, dx), hsv.s);
	hsv.h = time;
    return hsv;
}

bool CYCLE_BAND_SPIRAL_SAT(effect_params_t* params) { return effect_runner_dx_dy_dist(params, &CYCLE_BAND_SPIRAL_SAT_math); }

static HSV CYCLE_BAND_SPIRAL_VAL_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint8_t time) {
    hsv.v = scale8(hsv.v + dist - time - atan2_8(dy, dx), hsv.v);
	hsv.h = time;
    return hsv;
}

bool CYCLE_BAND_SPIRAL_VAL(effect_params_t* params) { return effect_runner_dx_dy_dist(params, &CYCLE_BAND_SPIRAL_VAL_math); }

static HSV CYCLE_RIGHT_LEFT_math(HSV hsv, uint8_t i, uint8_t time) {
    hsv.h = 224 - g_led_config.point[i].x - time;
    return hsv;
}

bool CYCLE_RIGHT_LEFT(effect_params_t* params) { return effect_runner_i(params, &CYCLE_RIGHT_LEFT_math); }

static HSV CYCLE_DOWN_UP_math(HSV hsv, uint8_t i, uint8_t time) {
    hsv.h = 64 - g_led_config.point[i].y - time;
    return hsv;
}

bool CYCLE_DOWN_UP(effect_params_t* params) { return effect_runner_i(params, &CYCLE_DOWN_UP_math); }

static HSV CYCLE_REACTIVE_WIDE_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick, uint8_t time) {
    uint16_t effect = tick + dist * 5;
    if (effect > 255) effect = 255;
    hsv.v = qadd8(hsv.v, 255 - effect);
	hsv.h = time;
    return hsv;
}

typedef HSV (*rs_f)(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick, uint8_t time);

bool effect_runner_reactive_s(uint8_t start, effect_params_t* params, rs_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
	uint8_t time = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed / 4, 1));
    uint8_t count = g_last_hit_tracker.count;
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = rgb_matrix_config.hsv;
        hsv.v   = 0;
        for (uint8_t j = start; j < count; j++) {
            int16_t  dx   = g_led_config.point[i].x - g_last_hit_tracker.x[j];
            int16_t  dy   = g_led_config.point[i].y - g_last_hit_tracker.y[j];
            uint8_t  dist = sqrt16(dx * dx + dy * dy);
            uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(rgb_matrix_config.speed, 1));
            hsv           = effect_func(hsv, dx, dy, dist, tick, time);
        }
        hsv.v   = scale8(hsv.v, rgb_matrix_config.hsv.v);
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

bool CYCLE_REACTIVE_WIDE(effect_params_t* params) { return effect_runner_reactive_s(qsub8(g_last_hit_tracker.count, 1), params, &CYCLE_REACTIVE_WIDE_math); }

bool CYCLE_REACTIVE_MULTIWIDE(effect_params_t* params) { return effect_runner_reactive_s(0, params, &CYCLE_REACTIVE_WIDE_math); }

static HSV CYCLE_REACTIVE_CROSS_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick, uint8_t time) {
    uint16_t effect = tick + dist;
    dx              = dx < 0 ? dx * -1 : dx;
    dy              = dy < 0 ? dy * -1 : dy;
    dx              = dx * 16 > 255 ? 255 : dx * 16;
    dy              = dy * 16 > 255 ? 255 : dy * 16;
    effect += dx > dy ? dy : dx;
    if (effect > 255) effect = 255;
    hsv.v = qadd8(hsv.v, 255 - effect);
	hsv.h = time;
    return hsv;
}


bool CYCLE_REACTIVE_MULTICROSS(effect_params_t* params) { return effect_runner_reactive_s(0, params, &CYCLE_REACTIVE_CROSS_math); }

static HSV CYCLE_REACTIVE_NEXUS_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick, uint8_t time) {
    uint16_t effect = tick - dist;
    if (effect > 255) effect = 255;
    if (dist > 72) effect = 255;
    if ((dx > 8 || dx < -8) && (dy > 8 || dy < -8)) effect = 255;
    hsv.v = qadd8(hsv.v, 255 - effect);
    hsv.h = time + dy / 4;
    return hsv;
}

bool CYCLE_REACTIVE_MULTINEXUS(effect_params_t* params) { return effect_runner_reactive_s(0, params, &CYCLE_REACTIVE_NEXUS_math); }

HSV CYCLE_SPLASH_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick, uint8_t time) {
    uint16_t effect = tick - dist;
    if (effect > 255) effect = 255;
    hsv.v = qadd8(hsv.v, 255 - effect);
	hsv.h = time;
    return hsv;
}

bool CYCLE_MULTISPLASH(effect_params_t* params) { return effect_runner_reactive_s(0, params, &CYCLE_SPLASH_math); }

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
