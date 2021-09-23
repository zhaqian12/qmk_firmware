#ifdef RGB_MATRIX_EFFECT_KITT_RGB
RGB_MATRIX_EFFECT(KITT_RGB)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static uint8_t k_led_count = DRIVER_LED_TOTAL - 1;
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

bool KITT_RGB(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint8_t time = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed / 4, 1)) / 6;
    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            k_led_count = i + 1;
            break;
        }
        RGB rgb = rgb_matrix_hsv_to_rgb(kitt_effect_math(rgb_matrix_config.hsv, i, time));
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
