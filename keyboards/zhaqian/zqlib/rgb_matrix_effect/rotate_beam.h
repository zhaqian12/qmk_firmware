#if defined(ENABLE_RGB_MATRIX_ROTATE_BEAM_PENDULUM) || defined(ENABLE_RGB_MATRIX_ROTATE_BEAM_WIPERS)

#ifdef ENABLE_RGB_MATRIX_ROTATE_BEAM_PENDULUM
RGB_MATRIX_EFFECT(ROTATE_BEAM_PENDULUM)
#endif

#ifdef ENABLE_RGB_MATRIX_ROTATE_BEAM_WIPERS
RGB_MATRIX_EFFECT(ROTATE_BEAM_WIPERS)
#endif

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static float pointx = 0;
static double rotate_beam_progress = 0;
static uint8_t rotate_beam_hue_step = 0;

void ROTATE_BEAM_update(void) {
    pointx = 0.5 * (1 + cos(rotate_beam_progress));
    rotate_beam_progress += rgb_matrix_config.speed / 5000.0;
    rotate_beam_hue_step ++;
}

#ifdef ENABLE_RGB_MATRIX_ROTATE_BEAM_PENDULUM
HSV ROTATE_BEAM_PENDULUM_math(HSV hsv, uint8_t i, uint8_t col, uint8_t row) {
    float x = pointx * 27;
    float distance = fabs((x - 13.5) * (0 - row) - (13.5 - col) * 7.0) / sqrt(pow(x - 13.5, 2) + pow(7.0, 2));
    hsv.v = hsv.v - hsv.v * pow(distance / 17 , distance < 2 ? 1 : 0.02);
    hsv.h = rotate_beam_hue_step;
    return hsv;
}

bool ROTATE_BEAM_PENDULUM(effect_params_t* params) {
    ROTATE_BEAM_update();
    return effect_runner_col_row(params, &ROTATE_BEAM_PENDULUM_math);
}
#endif

#ifdef ENABLE_RGB_MATRIX_ROTATE_BEAM_WIPERS
HSV ROTATE_BEAM_WIPERS_math(HSV hsv, uint8_t i, uint8_t col, uint8_t row) {
    float x = pointx * 27;
    float distance = fabs((13.5 - x) * (0 - row) - (x - col) * 7.0) / sqrt(pow(13.5 - x, 2) + pow(7.0, 2));
    hsv.v = hsv.v - hsv.v * pow(distance / 17 , distance < 2 ? 1 : 0.02);
    hsv.h = rotate_beam_hue_step;
    return hsv;
}

bool ROTATE_BEAM_WIPERS(effect_params_t* params) {
    ROTATE_BEAM_update();
    return effect_runner_col_row(params, &ROTATE_BEAM_WIPERS_math);
}
#endif

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
