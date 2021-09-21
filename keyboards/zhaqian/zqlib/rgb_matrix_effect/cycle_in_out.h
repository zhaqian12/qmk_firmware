#ifdef RGB_MATRIX_EFFECT_CYCLE_IN_OUT
RGB_MATRIX_EFFECT(CYCLE_IN_OUT)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV CYCLE_IN_OUT_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint8_t time) {
    hsv.h = 3 * dist / 2 - time;
    return hsv;
}

bool CYCLE_IN_OUT(effect_params_t* params) { return effect_runner_dx_dy_dist(params, &CYCLE_IN_OUT_math); }

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
