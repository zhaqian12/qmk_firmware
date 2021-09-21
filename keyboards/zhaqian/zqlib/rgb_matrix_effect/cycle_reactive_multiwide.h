#ifdef RGB_MATRIX_EFFECT_CYCLE_REACTIVE_MULTIWIDE
RGB_MATRIX_EFFECT(CYCLE_REACTIVE_MULTIWIDE)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV CYCLE_REACTIVE_WIDE_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick, uint8_t time) {
    uint16_t effect = tick + dist * 5;
    if (effect > 255) effect = 255;
    hsv.v = qadd8(hsv.v, 255 - effect);
	hsv.h = time;
    return hsv;
}

bool CYCLE_REACTIVE_MULTIWIDE(effect_params_t* params) { return effect_runner_reactive_s(0, params, &CYCLE_REACTIVE_WIDE_math); }

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
