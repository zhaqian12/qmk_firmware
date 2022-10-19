/* Copyright 2021 ZhaQian
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "zq46.h"

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
    {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, NO_LED},
        {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, NO_LED},
        {24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, NO_LED},
        {36, 37, 38, 39, NO_LED, NO_LED, 40, NO_LED, 41, 42, 43, 44, 45}
    }, {
        {0, 8}, {17, 8}, {34, 8}, {51, 8}, {68, 8}, {85, 8}, {101, 8}, {118, 8}, {135, 8}, {152, 8}, {169, 8}, {190, 8},
        {2, 24}, {21, 24}, {38, 24}, {55, 24}, {72, 24}, {89, 24}, {106, 24}, {123, 24}, {139, 24}, {156, 24}, {173, 24}, {192, 24},
        {6, 40}, {30, 40}, {46, 40}, {63, 40}, {80, 40}, {97, 40}, {114, 40}, {131, 40}, {148, 40}, {165, 40}, {184, 40}, {205, 40},
        {2, 55}, {21, 55}, {40, 55}, {70, 55}, {112, 55}, {146, 55}, {167, 55}, {188, 55}, {205, 55}, {222, 55},
        {150, 64}, {75, 64}, {0, 43}, {0, 21}, {75, 0}, {150, 0}, {224, 21}, {224, 43},
        {188, 64}, {156, 64}, {97, 64}, {55, 64}, {18, 64},
        {18, 0}, {53, 0}, {97, 0}, {156, 0}, {188, 0}
    }, {
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        8, 8, 8, 8, 8, 8, 8, 8,
        2, 2, 2, 2, 2,
        2, 2, 2, 2, 2
    }
};

void rgb_matrix_indicators_kb(void) {
    HSV hsv = {0, 255, rgb_matrix_get_val()};
    RGB rgb = hsv_to_rgb(hsv);
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = 46; i < 8; i ++) {
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
}

#endif
