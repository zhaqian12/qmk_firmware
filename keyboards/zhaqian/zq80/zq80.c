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

#include "zq80.h"

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = { 
{
    {22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8},
    {37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23},
    {52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38},
    {65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, NO_LED, 53, NO_LED},
    {78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, NO_LED, 67, 66, NO_LED},
    {87, 86, 85, NO_LED, NO_LED, 84, NO_LED, NO_LED, NO_LED, 83, 82, NO_LED, 81, 80, 79},
}, {
    {224, 43}, {150, 64}, {75, 64}, {0, 43}, {0, 21}, {75, 0}, {150, 0}, {224, 43},
    {212, 5}, {195, 5}, {178,5}, {164, 5}, {150, 5}, {136, 5}, {119, 5}, {105, 5}, {91, 5}, {77, 5}, {59, 5}, {45, 5}, {31, 5}, {17, 5}, {0, 5},
    {212, 18}, {188, 18}, {168, 18}, {154, 18}, {140, 18}, {126, 18}, {112, 18}, {98, 18}, {84, 18}, {70, 18}, {56, 18}, {42, 18}, {28, 18}, {14, 18}, {0, 18},
    {212, 28}, {192, 28}, {175, 28}, {161, 28}, {147, 28}, {133, 28}, {119, 28}, {105, 28}, {91, 28}, {77, 28}, {63, 28}, {49, 28}, {35, 28}, {21, 28}, {3, 28},
    {186, 38}, {164, 38}, {150, 38}, {136, 38}, {122, 38}, {108, 38}, {94, 38}, {80, 38}, {66, 38}, {52, 38}, {38, 38}, {24, 38}, {5, 38},
    {195, 48}, {177, 48}, {158, 48}, {144, 48}, {130, 48}, {116, 48}, {102, 48}, {88, 48}, {74, 48}, {59, 48}, {45, 48}, {31, 48}, {9, 48},
    {209, 58}, {195, 58}, {181, 58}, {160, 58}, {144, 58}, {89, 58}, {34, 58}, {18, 58}, {2, 58},
    {10, 64}, {49, 64}, {80, 64}, {132, 64}, {171, 64}, {198, 64}, {202, 32},
    {208, 0}, {170, 0}, {132, 0}, {82, 0}, {41, 0}, {9, 0}, {12, 32},
}, {
    8, 8, 8, 8, 8, 8, 8, 8,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4,
    2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2,
}};
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

#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_indicators_kb(void) {
    HSV hsv = {0, 255, rgb_matrix_get_val()};
    RGB rgb = hsv_to_rgb(hsv);
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = 0; i < 8; i ++)
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
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
#ifdef LOGO_RGB_MATRIX_CONTROL_ENABLE
        case LOGORGBTog:
            if (record->event.pressed) {
                logo_rgb_toggle();
            }
            return false;
#endif
#endif
#ifdef UNDERGLOW_RGB_MATRIX_ENABLE
        case LGUGRGBMODF:
            if (record->event.pressed) {
                underglow_rgb_mode_step();
            }
            return false;
        case LGUGRGBMODR:
            if (record->event.pressed) {
               underglow_rgb_mode_step_reverse();
            }
            return false;
#endif
    }
    return process_record_user(keycode, record);
};
