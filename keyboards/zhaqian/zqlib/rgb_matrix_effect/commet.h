#ifdef ENABLE_RGB_MATRIX_COMMET
RGB_MATRIX_EFFECT(COMMET)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static double commet_time = 0;
static double commet_progress = 0;

HSV COMMET_math(HSV hsv, uint8_t i, uint8_t col, uint8_t row) {
    float comet_size = 0.01 * 80 * 28;
    float position = commet_progress * 2 * 28;
    if(col > position)
    {
       hsv.v = 0;
       return hsv;
    }
    float distance = position - col;
    double value;
    if(distance > comet_size)
    {
        value = 0;
    }
    else if(distance == 0)
    {
        value = 1;
    }
    else
    {
        value = 1 - (distance / comet_size);
    }
    hsv.h = col * 10 - commet_time * 100;
    hsv.s= pow(value, 0.2) * rgb_matrix_config.hsv.s;
    hsv.v = pow(value, 3) * rgb_matrix_config.hsv.v;
    return hsv;
}


bool COMMET(effect_params_t* params) {
    commet_time += rgb_matrix_config.speed / 90000.0;
    float whole;
    commet_progress = modff(commet_time, &whole);
    return effect_runner_col_row(params, &COMMET_math);
}

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
