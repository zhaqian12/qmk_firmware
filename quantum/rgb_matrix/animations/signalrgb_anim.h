#ifdef SIGNALRGB_ENABLE
RGB_MATRIX_EFFECT(SIGNALRGB)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool SIGNALRGB(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i,
                            signalrgb_colors[i].r,
                            signalrgb_colors[i].g, 
                            signalrgb_colors[i].b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#    endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif