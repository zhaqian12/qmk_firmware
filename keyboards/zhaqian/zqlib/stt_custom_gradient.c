/*
A QMK effect for creating customizable RGB gradients right from the keyboard. Tested on the Drop Alt, should work on CTRL as well.

Created by /u/SirTimmyTimbit. No longer maintained. 
Please visit https://github.com/SirTimmyTimbit/customizable-gradient-effect-for-drop-alt

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

extern HSV stt_gradient_0;
extern HSV stt_gradient_100;
extern bool stt_reflected_gradient;

static HSV STT_INTERPOLATE_HSV(float step, HSV gradient_0, HSV gradient_100) {
    uint8_t cw, ccw;
    HSV color;

    cw = (gradient_0.h >= gradient_100.h) ? 255 + gradient_100.h - gradient_0.h : gradient_100.h - gradient_0.h;  // Hue range is 0 to 255.
    ccw = (gradient_0.h >= gradient_100.h) ? gradient_0.h - gradient_100.h : 255 + gradient_0.h - gradient_100.h;

    if( cw < ccw ) { // going clockwise
        color.h = gradient_0.h + (uint8_t)(step * cw);
    } else { // Going counter clockwise
        color.h = gradient_0.h - (uint8_t)(step * ccw);
    }

    color.s = gradient_0.s + step * (gradient_100.s - gradient_0.s);

    // Scale V with global RGB Matrix's V, so users can still control overall brightness with RGB_VAI & RGB_VAD0
    color.v = round((gradient_0.v + step * (gradient_100.v - gradient_0.v)) * ((float)rgb_matrix_config.hsv.v / 255));

    return color;
}

static HSV STT_CUSTOM_GRADIENT_math(uint8_t led_x, uint8_t min_x, uint8_t max_x) {
    float step = (float)led_x / (max_x - min_x);
    float mid_gradient_pos = 0.5;

    if( stt_reflected_gradient ) {
        if( step <= mid_gradient_pos ) {
            return STT_INTERPOLATE_HSV(step * (1/mid_gradient_pos), stt_gradient_0, stt_gradient_100);
        } else {
            return STT_INTERPOLATE_HSV((step - mid_gradient_pos) * (1/(1-mid_gradient_pos)), stt_gradient_100, stt_gradient_0);
        }

    } else {
        return STT_INTERPOLATE_HSV(step, stt_gradient_0, stt_gradient_100);
    }
}

static bool STT_CUSTOM_GRADIENT(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t min_x = 0;  // X coordinate of the left-most LED
    uint8_t max_x = 224; // X coordinate of the right-most LED

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();

        HSV hsv_orig = STT_CUSTOM_GRADIENT_math(g_led_config.point[i].x, min_x, max_x);
        RGB rgb = hsv_to_rgb(hsv_orig);

        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }

    return led_max < DRIVER_LED_TOTAL;
}