#if defined(ENABLE_RGB_MATRIX_STATIC_ZIGZAG) || defined(ENABLE_RGB_MATRIX_RAINBOW_ZIGZAG)

#ifdef ENABLE_RGB_MATRIX_STATIC_ZIGZAG
RGB_MATRIX_EFFECT(STATIC_ZIGZAG)
#endif

#ifdef ENABLE_RGB_MATRIX_RAINBOW_ZIGZAG
RGB_MATRIX_EFFECT(RAINBOW_ZIGZAG)
#endif

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static double zigzag_time = 0.0;
static double zigzag_progress = 0.0;

void ZIGZAG_update(void) {
    zigzag_time += rgb_matrix_config.speed / 200000.0;
    zigzag_progress = 2*(zigzag_time-(long)zigzag_time);
}

HSV ZIGZAG_math(HSV hsv, uint8_t i, uint8_t col, uint8_t row, uint8_t index) {
    float current_led_position = ((int) col % 2 == 0 ? row : 8 - row - 1 ) + col * 8;
    float current_led_percent = current_led_position/224.0;
    if(current_led_percent < zigzag_progress)
    {
        float distance = pow(current_led_percent / zigzag_progress, 3);
        if (index == 1)
            hsv.h = distance*360. -100.*zigzag_time;
        hsv.v *= distance;
        return hsv;
    }
    else
    {
        hsv.v = 0;
        return hsv;
    }
}

#ifdef ENABLE_RGB_MATRIX_STATIC_ZIGZAG
HSV STATIC_ZIGZAG_math(HSV hsv, uint8_t i, uint8_t col, uint8_t row) {
    return ZIGZAG_math(hsv, i, col, row, 0);
}

bool STATIC_ZIGZAG(effect_params_t* params) {
    ZIGZAG_update();
    return effect_runner_col_row(params, &STATIC_ZIGZAG_math);
}
#endif

#ifdef ENABLE_RGB_MATRIX_RAINBOW_ZIGZAG
HSV RAINBOW_ZIGZAG_math(HSV hsv, uint8_t i, uint8_t col, uint8_t row) {
    return ZIGZAG_math(hsv, i, col, row, 1);
}

bool RAINBOW_ZIGZAG(effect_params_t* params) {
    ZIGZAG_update();
    return effect_runner_col_row(params, &RAINBOW_ZIGZAG_math);
}
#endif

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
