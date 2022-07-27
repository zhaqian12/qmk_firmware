#ifdef ENABLE_RGB_MATRIX_ROTATE_RAINBOW
RGB_MATRIX_EFFECT(ROTATE_RAINBOW)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static double rotate_rainbow_time = 1000.0;
static double cos_time = 0;
static double sin_time = 0;
static double cos_reverse_time = 0;
static double sin_reverse_time = 0;
static int frequency = 3;

HSV ROTATE_RAINBOW_math(HSV hsv, uint8_t i, uint8_t col, uint8_t row) {
    double c = cos_time;
    double s = sin_time;
    hsv.h = (int)(rotate_rainbow_time * 40 + 360 * (frequency * (row - 3.5) * c + (56 - fabs(col - 13.5)) * frequency * s) / 128.0) % 255;
    return hsv;
}

bool ROTATE_RAINBOW(effect_params_t* params) {
    rotate_rainbow_time += rgb_matrix_config.speed / 150000.0;
    cos_time = cos(rotate_rainbow_time);
    sin_time = sin(rotate_rainbow_time);
    cos_reverse_time = cos(-rotate_rainbow_time);
    sin_reverse_time = sin(-rotate_rainbow_time);
    return effect_runner_col_row(params, &ROTATE_RAINBOW_math);
}

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
