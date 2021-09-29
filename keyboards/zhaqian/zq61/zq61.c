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

#include "zq61.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
    {
        {62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49},
        {48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35},
        {34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, NO_LED, 22},
        {21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, NO_LED, 10, NO_LED},
        {9, 8, 7, 6, NO_LED, 5, NO_LED, 4, NO_LED, 3, 2, NO_LED, 1, 0},
    }, {
        {222, 58}, {202, 58}, {182, 58}, {162, 58}, {132, 58}, {102, 58}, {72, 58}, {42, 58}, {22, 58}, {2, 58},
        {210, 45}, {180, 45}, {164, 45}, {148, 45}, {132, 45}, {116, 45}, {100, 45}, {84, 45}, {68, 45}, {52, 45}, {36, 45}, {10, 45},
        {214, 32}, {188, 32}, {172, 32}, {156, 32}, {140, 32}, {124, 32}, {108, 32}, {92, 32}, {76, 32}, {60, 32}, {44, 32}, {28, 32}, {6, 32},
        {220, 20}, {200, 20}, {184, 20}, {168, 20}, {152, 20}, {136, 20}, {120, 20}, {104, 20}, {88, 20}, {72, 20}, {56, 20}, {40, 20}, {24, 20}, {4, 20},
        {216, 8}, {192, 8}, {176, 8}, {160, 8}, {144, 8}, {128, 8}, {112, 8}, {96, 8}, {80, 8}, {64, 8}, {48, 8}, {32, 8}, {16, 8}, {0, 8},
        {15, 0}, {42, 0}, {68, 0}, {91, 0}, {118, 0}, {148, 0}, {182, 0}, {212, 0},
        {212, 64}, {180,64}, {150, 64}, {120, 64}, {92, 64},  {66, 64}, {40, 64}, {16, 64},
    }, {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2,
    }
};

void rgb_matrix_indicators_kb(void) {
    if (host_keyboard_led_state().caps_lock) {
        HSV hsv = {0, 255, rgb_matrix_get_val()};
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(34, rgb.r, rgb.g, rgb.b);
    }
}
#endif

#ifdef RGB_DISABLE_WHEN_USB_SUSPENDED
void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}
#endif


bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
#ifdef RGB_MATRIX_CONTROL_ENABLE
        case UGLRGBTog:
            if (record->event.pressed) {
                underglow_rgb_toggle();
            }
            return false;
        case KBLRGBTog:
            if (record->event.pressed) {
                key_backlight_rgb_toggle();
            }
            return false;
#endif
#ifdef UNDERGLOW_RGB_MATRIX_ENABLE
        case UGLFIXEDRGBMODF:
            if (record->event.pressed) {
               underglow_rgb_mode_step();
            }
            return false;
        case UGLFIXEDRGBMODR:
            if (record->event.pressed) {
               underglow_rgb_mode_step_reverse();
            }
            return false;
#endif
    }
    return process_record_user(keycode, record);
};



