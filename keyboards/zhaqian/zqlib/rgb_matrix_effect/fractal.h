#ifdef RGB_MATRIX_EFFECT_FRACTAL
RGB_MATRIX_EFFECT(FRACTAL)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static uint32_t f_timer = 0;

static uint8_t halfArray[6][4];
static uint8_t fullArray[12][4];
static uint8_t halfbottom[3];
static uint8_t fullbottom[6];
static uint8_t displArray[54];

bool FRACTAL(effect_params_t* params) {
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

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
