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

#include "zq67.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
{
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14},
    {15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29},
    {30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, NO_LED, 43},
    {44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, NO_LED, 55, 56, 57},
    {58, 59, 60, NO_LED, NO_LED, 61, NO_LED, NO_LED, NO_LED, 62, 63, NO_LED, 64, 65, 66},
}, {
    {0, 8}, {15, 8}, {30, 8}, {45, 8}, {60, 8}, {75, 8}, {90, 8}, {105, 8}, {119, 8}, {134, 8}, {149, 8}, {164, 8}, {179, 8}, {202, 8}, {224, 8},
    {4, 20}, {22, 20}, {37, 20}, {52, 20}, {67, 20}, {82, 20}, {97, 20}, {112, 20}, {127, 20}, {142, 20}, {157, 20}, {172, 20}, {187, 20}, {205, 20}, {224, 20},
    {6, 32}, {26, 32}, {41, 32}, {56, 32}, {71, 32}, {86, 32}, {101, 32}, {116, 32}, {131, 32}, {146, 32}, {161, 32}, {175, 32}, {200, 32}, {224, 32},
    {9, 45}, {34, 45}, {49, 45}, {63, 45}, {78, 45}, {93, 45}, {108, 45}, {123, 45}, {138, 45}, {153, 45}, {168, 45}, {189, 45}, {209, 45}, {224, 45},
    {2, 57}, {21, 57}, {39, 57}, {95, 57}, {151, 57}, {170, 57}, {190, 57}, {205, 57}, {220, 57},
    {218, 64}, {190, 64}, {167, 64}, {139, 64}, {91, 64}, {62, 64}, {33, 64}, {7, 64},
    {5, 0}, {32, 0}, {64, 0}, {94, 0}, {127, 0}, {162, 0}, {181, 0}, {218, 0},

}, {
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 4,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 4,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 4,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 4,
    1, 1, 1, 1, 1, 1, 4, 4, 4,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
}
};
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
