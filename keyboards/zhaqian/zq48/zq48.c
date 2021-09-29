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

#include "zq48.h"

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
{
    { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13},
    {14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, NO_LED, 25, 26},
    {27, 28, 29, 30, 31, 32, 33, 34, 35, 36, NO_LED, 37, 38, 39},
    {40, 41, NO_LED, NO_LED, 42, NO_LED, NO_LED, NO_LED, 43, 44, NO_LED, 45, 46, 47},
}, {
    {0, 8}, {17, 8}, {33, 8}, {50, 8}, {66, 8}, {83, 8}, {100, 8}, {116, 8}, {133, 8}, {149, 8}, {166, 8}, {183, 8}, {199, 8}, {220, 8},
    {2, 24}, {21, 24}, {37, 24}, {54, 24}, {71, 24}, {87, 24}, {104, 24}, {120, 24}, {137, 24}, {153, 24}, {170, 24}, {193, 24}, {220, 24},
    {6, 40}, {29, 40}, {46, 40}, {62, 40}, {79, 40}, {95, 40}, {112, 40}, {129, 40}, {145, 40}, {162, 40}, {180, 40}, {201, 46}, {220, 40},
    {2, 55}, {21, 55}, {81, 55}, {141, 55}, {160, 55}, {183, 60}, {199, 60}, {216, 60},
    {212, 64}, {171, 64}, {97, 64}, {54, 64}, {1, 64},
    {9, 0}, {63, 0}, {112, 0}, {162, 0}, {212, 0},
}, {
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 4,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 4,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 4, 4,
    1, 1, 1, 1, 1, 4, 4, 4,
    2, 2, 2, 2, 2,
    2, 2, 2, 2, 2,
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
