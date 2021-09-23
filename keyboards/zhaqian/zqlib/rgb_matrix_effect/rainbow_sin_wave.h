#ifdef RGB_MATRIX_EFFECT_RAINBOW_SIN_WAVE
RGB_MATRIX_EFFECT(RAINBOW_SIN_WAVE)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV RAINBOW_SIN_WAVE_math(HSV hsv, uint8_t i, uint8_t time) {
    int16_t y = sin8(2 * (g_led_config.point[i].x - time)) / 6 ;
    hsv.v = abs(g_led_config.point[i].y - y) >= 10 ? 0 : hsv.v;
	hsv.h = g_led_config.point[i].x - time;
    return hsv;
}

bool RAINBOW_SIN_WAVE(effect_params_t* params) { return effect_runner_i(params, &RAINBOW_SIN_WAVE_math); }

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
