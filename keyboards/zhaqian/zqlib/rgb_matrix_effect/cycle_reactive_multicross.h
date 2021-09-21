#ifdef RGB_MATRIX_EFFECT_CYCLE_REACTIVE_MULTICROSS
RGB_MATRIX_EFFECT(CYCLE_REACTIVE_MULTICROSS)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV CYCLE_REACTIVE_CROSS_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick, uint8_t time) {
    uint16_t effect = tick + dist;
    dx              = dx < 0 ? dx * -1 : dx;
    dy              = dy < 0 ? dy * -1 : dy;
    dx              = dx * 16 > 255 ? 255 : dx * 16;
    dy              = dy * 16 > 255 ? 255 : dy * 16;
    effect += dx > dy ? dy : dx;
    if (effect > 255) effect = 255;
    hsv.v = qadd8(hsv.v, 255 - effect);
	hsv.h = time;
    return hsv;
}

bool CYCLE_REACTIVE_MULTICROSS(effect_params_t* params) { return effect_runner_reactive_s(0, params, &CYCLE_REACTIVE_CROSS_math); }

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
