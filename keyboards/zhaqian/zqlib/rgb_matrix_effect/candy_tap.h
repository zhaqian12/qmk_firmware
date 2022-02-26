#ifdef RGB_MATRIX_EFFECT_CANDY_TAP
RGB_MATRIX_EFFECT(CANDY_TAP)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

HSV CANDY_TAP_math(HSV hsv, uint16_t offset) {
	hsv.v = scale8(255 - offset, hsv.v);
	hsv.h = mod8(scale16by8(g_rgb_timer, add8(rgb_matrix_config.speed >> 5, 1)), 255);
	return hsv;
}

bool CANDY_TAP(effect_params_t* params) { return effect_runner_reactive(params, &CANDY_TAP_math); }

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
