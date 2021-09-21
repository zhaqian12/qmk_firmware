#ifdef RGB_MATRIX_EFFECT_REACTIVE_MULTINEXUS_RGB
RGB_MATRIX_EFFECT(REACTIVE_MULTINEXUS_RGB)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV REACTIVE_NEXUS_RGB_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick - dist;
    if (effect > 255) effect = 255;
    if (dist > 72) effect = 255;
    if ((dx > 8 || dx < -8) && (dy > 8 || dy < -8)) effect = 255;
    hsv.v = qadd8(hsv.v, 255 - effect);
	hsv.h = hsv.h + dx + dy + dy / 4;
    return hsv;
}

bool REACTIVE_MULTINEXUS_RGB(effect_params_t* params) { return effect_runner_reactive_splash(0, params, &REACTIVE_NEXUS_RGB_math); }

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
