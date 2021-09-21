#ifdef RGB_MATRIX_EFFECT_CYCLE_REACTIVE_MULTINEXUS
RGB_MATRIX_EFFECT(CYCLE_REACTIVE_MULTINEXUS)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV CYCLE_REACTIVE_NEXUS_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick, uint8_t time) {
    uint16_t effect = tick - dist;
    if (effect > 255) effect = 255;
    if (dist > 72) effect = 255;
    if ((dx > 8 || dx < -8) && (dy > 8 || dy < -8)) effect = 255;
    hsv.v = qadd8(hsv.v, 255 - effect);
    hsv.h = time + dy / 4;
    return hsv;
}

bool CYCLE_REACTIVE_MULTINEXUS(effect_params_t* params) { return effect_runner_reactive_s(0, params, &CYCLE_REACTIVE_NEXUS_math); }

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
