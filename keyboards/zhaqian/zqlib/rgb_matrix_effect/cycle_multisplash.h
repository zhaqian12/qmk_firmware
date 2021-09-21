#ifdef RGB_MATRIX_EFFECT_CYCLE_MULTISPLASH
RGB_MATRIX_EFFECT(CYCLE_MULTISPLASH)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

HSV CYCLE_SPLASH_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick, uint8_t time) {
    uint16_t effect = tick - dist;
    if (effect > 255) effect = 255;
    hsv.v = qadd8(hsv.v, 255 - effect);
	hsv.h = time;
    return hsv;
}

bool CYCLE_MULTISPLASH(effect_params_t* params) { return effect_runner_reactive_s(0, params, &CYCLE_SPLASH_math); }

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
