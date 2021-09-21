#ifdef RGB_MATRIX_EFFECT_LIGHTNING
RGB_MATRIX_EFFECT(LIGHTNING)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
uint8_t hue_stepper = 0;
bool LIGHTNING(effect_params_t* params) {
    HSV      hsv  = rgb_matrix_config.hsv;
    uint8_t time = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed / 8, 1));
    hue_stepper_l += 8;
    hsv.h = hue_stepper_l;
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        int16_t v = hsv.v - abs(scale8(g_led_config.point[i].y, 64) - time) * 4;
        hsv.v     = scale8(v < 0 ? 0 : v, hsv.v);
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
