#ifdef RGB_MATRIX_EFFECT_CYCLE_RIGHT_LEFT
RGB_MATRIX_EFFECT(CYCLE_RIGHT_LEFT)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV CYCLE_RIGHT_LEFT_math(HSV hsv, uint8_t i, uint8_t time) {
    hsv.h = 224 - g_led_config.point[i].x - time;
    return hsv;
}

bool CYCLE_RIGHT_LEFT(effect_params_t* params) { return effect_runner_i(params, &CYCLE_RIGHT_LEFT_math); }

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
