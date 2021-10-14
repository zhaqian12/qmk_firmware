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

#include "zq980mini.h"

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
{
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16},
    {17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33},
    {34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, NO_LED, 46, 47, 48, 49},
    {50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, NO_LED, 61, 62, 63, 64, 65},
    {66, 67, 68, NO_LED, NO_LED, 69, NO_LED, NO_LED, NO_LED, 70, 71, NO_LED, 72, 73, 74, 75, 76},
}, {
    {0, 10}, {13, 10}, {26, 10}, {38, 10}, {51, 10}, {64, 10}, {77, 10}, {90, 10}, {102, 10}, {115, 10}, {128, 10}, {141, 10}, {154, 10}, {173, 10}, {195, 10}, {208, 10}, {221, 10},
    {3, 21}, {19, 21}, {32, 21}, {45, 21}, {58, 21}, {70, 21}, {83, 21}, {96, 21}, {109, 21}, {122, 21}, {134, 21}, {147, 21}, {160, 21}, {176, 21}, {195, 21}, {208, 21}, {221, 21},
    {5, 32}, {22, 32}, {35, 32}, {48, 32}, {61, 32}, {74, 32}, {86, 32}, {99, 32}, {112, 32}, {125, 32}, {138, 32}, {150, 32}, {171, 32}, {195, 32}, {208, 32}, {221, 32},
    {8, 43}, {29, 43}, {42, 43}, {54, 43}, {67, 43}, {80, 43}, {93, 43}, {106, 43}, {118, 43}, {131, 43}, {144, 43}, {162, 43}, {181, 46}, {195, 43}, {208, 43}, {221, 43},
    {2, 54}, {18, 54}, {34, 54}, {82, 54}, {130, 54}, {146, 54}, {165, 57}, {178, 57}, {190, 57}, {205, 54}, {218, 54},
    {215, 64}, {194, 64}, {162, 64}, {133, 64}, {104, 64}, {71, 64}, {43, 64}, {7, 64},
    {8, 0}, {41, 0}, {68, 0}, {105, 0}, {125, 0}, {163, 0}, {197, 0}, {218, 0},
}, {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
}};

void rgb_matrix_indicators_kb(void) {
// COLOR RED RGB VALUE
    HSV hsv = {0, 255, rgb_matrix_get_val()};
    RGB rgb = hsv_to_rgb(hsv);
// caps_lock indicator
    if (host_keyboard_led_state().caps_lock) {
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
        case UGRGBMODF:
            if (record->event.pressed) {
                underglow_rgb_mode_step();
            }
            return false;
        case UGRGBMODR:
            if (record->event.pressed) {
               underglow_rgb_mode_step_reverse();
            }
            return false;
#endif
    }
    return process_record_user(keycode, record);
};
