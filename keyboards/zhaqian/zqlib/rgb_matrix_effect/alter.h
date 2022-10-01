#if defined(ENABLE_RGB_MATRIX_CYCLE_ALTER) || defined (ENABLE_RGB_MATRIX_RAINBOW_ALTER)

#ifdef ENABLE_RGB_MATRIX_CYCLE_ALTER
RGB_MATRIX_EFFECT(CYCLE_ALTER)
#endif
#ifdef ENABLE_RGB_MATRIX_RAINBOW_ALTER
RGB_MATRIX_EFFECT(RAINBOW_ALTER)
#endif

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static uint8_t led_row_first[MATRIX_ROWS] = {0};
static uint8_t led_row_last[MATRIX_ROWS] = {0};
static uint8_t led_row_count[MATRIX_ROWS] = {0};

void ALTER_init(void) {
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        uint8_t x = 0;
        do {
            led_row_first[i] = g_led_config.matrix_co[i][x];
        }while (g_led_config.matrix_co[i][x] == NO_LED && ++x < MATRIX_COLS);
        x = MATRIX_COLS - 1;
        do {
            led_row_last[i] = g_led_config.matrix_co[i][x];
        }while (g_led_config.matrix_co[i][x] == NO_LED && --x >= 0);
        for (uint8_t j = 0; j < MATRIX_COLS; j++) {
            if (g_led_config.matrix_co[i][j] != NO_LED)
               led_row_count[i] ++;
        }
        if (led_row_last[i] < led_row_first[i]) {
            x = led_row_last[i];
            led_row_last[i] = led_row_first[i];
            led_row_first[i] = x;
        }
    }
}

uint8_t time_to_led_alter(uint8_t row, uint8_t time, uint8_t led_behind) {
	uint16_t led_time = led_row_count[row] * time;
    uint16_t step = 0;
    uint8_t led;
    if (row % 2 == 1) {
	    step = ((2 * led_row_count[row] + (led_time / 128)) - led_behind) % (2 * led_row_count[row]);
    } else{
        step = ((2 * led_row_count[row] + (led_time / 128)) - led_behind) % (2 * led_row_count[row]);
    }
	if (step < led_row_count[row]) {
		led = step;
	} else {
		led = led_row_count[row] - 1 - (step - led_row_count[row]);
	}
	return led;
}

HSV ALTER_math(HSV hsv, uint8_t i, uint8_t time) {
    uint8_t g = 0;
    uint8_t find = MATRIX_ROWS + 1;
    for (uint8_t k = 0; k < MATRIX_ROWS; k++) {
        for (uint8_t j = 0; j < MATRIX_COLS; j++) {
            if (i == g_led_config.matrix_co[k][j]) {
                if ((k % 2) == 1) {
                    if (i >= led_row_first[k] && i < led_row_first[k] + led_row_count[k]) {
                        g = i - led_row_first[k];
                        find = k;
                    }
                } else {
                    if (i <= led_row_last[k]  && i > led_row_last[k] -  led_row_count[k]) {
                        g = led_row_last[k] - i;
                        find = k;
                    }
                }
            }
        }
    }
    if (find < MATRIX_ROWS) {
        if (g == time_to_led_alter(find, time, 0)) {
            hsv.v = hsv.v;
        } else if (g == time_to_led_alter(find, time, 1)) {
            hsv.v = hsv.v / 2;
        } else if (g == time_to_led_alter(find, time, 2)) {
            hsv.v = hsv.v / 3;
        } else if (g == time_to_led_alter(find, time, 3)) {
            hsv.v = hsv.v / 4;
        } else if (g == time_to_led_alter(find, time, 4)) {
            hsv.v = hsv.v / 5;
        } else if (g == time_to_led_alter(find, time, 5)) {
            hsv.v = hsv.v / 6;
        } else if (g == time_to_led_alter(find, time, 6)) {
            hsv.v = hsv.v / 8;
        } else {
            hsv.v = 0;
        }
        return hsv;
    }
	return hsv;
}

#ifdef ENABLE_RGB_MATRIX_CYCLE_ALTER
HSV CYCLE_ALTER_math(HSV hsv, uint8_t i, uint8_t time) {
    HSV tmp = ALTER_math(hsv, i, time);
    tmp.h = time;
    return tmp;
}

bool CYCLE_ALTER(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint8_t time = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed / 6, 1));
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        RGB rgb = rgb_matrix_hsv_to_rgb(CYCLE_ALTER_math(rgb_matrix_config.hsv, i, time));
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}
#endif

#ifdef ENABLE_RGB_MATRIX_RAINBOW_ALTER
HSV RAINBOW_ALTER_math(HSV hsv, uint8_t i, uint8_t time) {
    HSV tmp = ALTER_math(hsv, i, time);
    tmp.h = g_led_config.point[i].x - time;
    return tmp;
}

bool RAINBOW_ALTER(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint8_t time = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed / 6, 1));
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        RGB rgb = rgb_matrix_hsv_to_rgb(RAINBOW_ALTER_math(rgb_matrix_config.hsv, i, time));
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}
#endif

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
