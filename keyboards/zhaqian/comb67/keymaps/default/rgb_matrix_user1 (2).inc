RGB_MATRIX_EFFECT(MYEFFECT1)
RGB_MATRIX_EFFECT(MYEFFECT2)
RGB_MATRIX_EFFECT(MYEFFECT3)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool MYEFFECT1(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    HSV      hsv  = rgb_matrix_config.hsv;
    uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
    hsv.v         = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
    RGB rgb       = rgb_matrix_hsv_to_rgb(hsv);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

typedef HSV (*z_f)(HSV hsv, uint8_t i, uint8_t time);

bool effect_runner_mi(effect_params_t* params, z_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint8_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 4);
    for (uint8_t i = 0; i < 15; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        RGB rgb = rgb_matrix_hsv_to_rgb(effect_func(rgb_matrix_config.hsv, i, time));
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

static HSV CYCLE_LEFT_RIGHT_math(HSV hsv, uint8_t i, uint8_t time) {
    hsv.h = g_led_config.point[i].x - time;
    return hsv;
}

bool MYEFFECT2(effect_params_t* params) { return effect_runner_mi(params, &CYCLE_LEFT_RIGHT_math); }

bool MYEFFECT3(effect_params_t* params) { return effect_runner_mi(params, &CYCLE_)}

#endif