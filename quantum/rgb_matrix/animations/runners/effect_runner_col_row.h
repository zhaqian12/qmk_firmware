#pragma once

typedef HSV (*col_row_f)(HSV hsv, uint8_t i, uint8_t col, uint8_t row);

bool effect_runner_col_row(effect_params_t* params, col_row_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        uint8_t col = g_led_config.point[i].x / 8;
        uint8_t row = g_led_config.point[i].y / 8;
        RGB rgb = rgb_matrix_hsv_to_rgb(effect_func(rgb_matrix_config.hsv, i, col, row));
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

