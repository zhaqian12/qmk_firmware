#ifdef ENABLE_RGB_MATRIX_LIGHTNING
RGB_MATRIX_EFFECT(LIGHTNING)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV lightning = {0, 0, 0};

HSV LIGHTNING_math(HSV hsv, uint8_t i, uint8_t time) {
    lightning.v = ((rand() % 1000)) > (1000 - rgb_matrix_config.speed) ?  hsv.v : lightning.v > 0 ?  lightning.v / (1 + 20 / 60.0) : 0;
    if(lightning.v == 0)
        lightning.h = rand() % 255;
    return lightning;
}

bool LIGHTNING(effect_params_t* params) {
    return effect_runner_i(params, &LIGHTNING_math);
}

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
