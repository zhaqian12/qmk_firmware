#ifdef ENABLE_RGB_MATRIX_MOTION_POINT
RGB_MATRIX_EFFECT(MOTION_POINT)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static float motion_point_progress = 0;
static float motion_point_hue = 0;
HSV MOTION_POINT_math(HSV hsv, uint8_t i, uint8_t col, uint8_t row) {
    double t = (1 + sin(motion_point_progress)) / 2.f;
    float distance = fabs(col - t * (27));
    if(distance > 2) {
        hsv.v = 0;
        return hsv;
    }
    if(t <= 0.0005 || t >= 0.9995)
    {
        motion_point_hue = rand() % 255;
    }
    hsv.h = motion_point_hue;
    return hsv;
}

bool MOTION_POINT(effect_params_t* params) {
    motion_point_progress += rgb_matrix_config.speed / 20000.0;
    return effect_runner_col_row(params, &MOTION_POINT_math);
}

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
