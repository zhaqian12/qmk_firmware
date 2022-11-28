#if defined(ENABLE_RGB_MATRIX_STATIC_BREATHING_CIRCLE) || defined(ENABLE_RGB_MATRIX_CYCLE_BREATHING_CIRCLE)

#ifdef ENABLE_RGB_MATRIX_STATIC_BREATHING_CIRCLE
RGB_MATRIX_EFFECT(STATIC_BREATHING_CIRCLE)
#endif

#ifdef ENABLE_RGB_MATRIX_CYCLE_BREATHING_CIRCLE
RGB_MATRIX_EFFECT(CYCLE_BREATHING_CIRCLE)
#endif

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static uint32_t time = 0;
static uint16_t progress = 0;

HSV BREATHING_CIRCLE_math(HSV hsv, uint8_t x, uint8_t y)
{
    uint16_t distance = sqrt(pow(500 - x * 1000 / 27, 2) + pow(500 - y * 1000 / 15, 2));
    distance = distance >= 1000 ? 1000 : distance;
    if(distance > progress || distance < progress - 238) {
        hsv.v = 0;
    }
    return hsv;
}

void BREATHING_CIRCLE_update(void) {
    time += scale16by8(500, qadd8(rgb_matrix_config.speed / 2, 1));
    progress = 350 * (1 + sin(time / 10000.0));
}

#ifdef ENABLE_RGB_MATRIX_STATIC_BREATHING_CIRCLE
HSV STATIC_BREATHING_CIRCLE_math(HSV hsv, uint8_t i, uint8_t col, uint8_t row) {
    return BREATHING_CIRCLE_math(hsv, col, row);
}

bool STATIC_BREATHING_CIRCLE(effect_params_t* params) {
    BREATHING_CIRCLE_update();
    return effect_runner_col_row(params, &STATIC_BREATHING_CIRCLE_math);
}
#endif

#ifdef ENABLE_RGB_MATRIX_CYCLE_BREATHING_CIRCLE
static uint8_t hue_step = 0;
HSV CYCLE_BREATHING_CIRCLE_math(HSV hsv, uint8_t i, uint8_t col, uint8_t row) {

    hsv = BREATHING_CIRCLE_math(hsv, col, row);
    if (progress <= 0) {
        hue_step += 8;
    }
    hsv.h = hue_step;
    return hsv;
}

bool CYCLE_BREATHING_CIRCLE(effect_params_t* params) {
    BREATHING_CIRCLE_update();
    return effect_runner_col_row(params, &CYCLE_BREATHING_CIRCLE_math);
}
#endif

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
