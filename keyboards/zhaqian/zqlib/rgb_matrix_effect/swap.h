#ifdef ENABLE_RGB_MATRIX_SWAP
RGB_MATRIX_EFFECT(SWAP)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static double swap_time = 0.0;
static double swap_progress = 0;
static uint8_t swap_hue1 = 0, swap_hue2 = 127;
static uint8_t dir = 0, old_dir = 0;
HSV SWAP_math(HSV hsv, uint8_t i, uint8_t col, uint8_t row) {
    float x = dir ? swap_progress : 1 - swap_progress;
    hsv.h = (col+1) <= x * (28+1) ? swap_hue1 : swap_hue2;
    return hsv;
}

bool SWAP(effect_params_t* params) {
    swap_time += rgb_matrix_config.speed / 40000.0;
    float whole;
    swap_progress = modff(swap_time, &whole);
    dir = (int) whole % 2;
    if(old_dir == 0 && dir == 1)
    {
        swap_hue1 = rand()%255;
    }
    else if(old_dir == 1 && dir == 0)
    {
        swap_hue2 = rand()%255;
    }

    old_dir = dir;
    return effect_runner_col_row(params, &SWAP_math);
}




#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
