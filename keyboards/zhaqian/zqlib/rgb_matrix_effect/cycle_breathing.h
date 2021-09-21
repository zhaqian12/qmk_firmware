#ifdef RGB_MATRIX_EFFECT_CYCLE_BREATHING
RGB_MATRIX_EFFECT(CYCLE_BREATHING)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

uint8_t is_breathing_highest = 1;
uint8_t is_breathing_lowest = 1;
uint8_t hue_index = 0;
uint8_t val_index = 0;
uint8_t hue_stepper = 0;

bool CYCLE_BREATHING(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    HSV      hsv  = rgb_matrix_config.hsv;
    uint16_t time = g_rgb_timer * (rgb_matrix_config.speed / 8) / 256;
    hsv.v         = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
    if (is_breathing_lowest){
        val_index = hsv.v;
        hue_index = hue_stepper;
        hue_stepper += 8;
        is_breathing_lowest ^= 1;
    } else {
        if (hsv.v >= val_index && is_breathing_highest) {
            is_breathing_highest ^= 1;
        } else {
            if (hsv.v <= 0 && !is_breathing_highest) {
                is_breathing_highest ^= 1;
                is_breathing_lowest  ^= 1;
            }
        }
    }
    hsv.h = hue_index;
    RGB rgb       = hsv_to_rgb(hsv);
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
