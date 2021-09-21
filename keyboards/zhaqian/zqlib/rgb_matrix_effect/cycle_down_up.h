#ifdef RGB_MATRIX_EFFECT_CYCLE_DOWN_UP
RGB_MATRIX_EFFECT(CYCLE_DOWN_UP)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV CYCLE_DOWN_UP_math(HSV hsv, uint8_t i, uint8_t time) {
    hsv.h = 64 - g_led_config.point[i].y - time;
    return hsv;
}

bool CYCLE_DOWN_UP(effect_params_t* params) { return effect_runner_i(params, &CYCLE_DOWN_UP_math); }

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
