#ifdef RGB_MATRIX_EFFECT_CYCLE_BANDVAL
RGB_MATRIX_EFFECT(CYCLE_BANDVAL)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV CYCLE_BANDVAL_math(HSV hsv, uint8_t i, uint8_t time) {
    int16_t v = hsv.v - abs(scale8(g_led_config.point[i].x, 228) + 28 - time) * 8;
    hsv.v     = scale8(v < 0 ? 0 : v, hsv.v);
	hsv.h = time;
    return hsv;
}

bool CYCLE_BANDVAL(effect_params_t* params) { return effect_runner_i(params, &CYCLE_BANDVAL_math); }

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
