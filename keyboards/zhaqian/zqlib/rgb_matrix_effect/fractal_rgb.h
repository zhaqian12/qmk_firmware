#ifdef RGB_MATRIX_EFFECT_FRACTAL_RGB
RGB_MATRIX_EFFECT(FRACTAL_RGB)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

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


#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
