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

#include "zq67rev2.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
{
    {66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52},
    {51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37},
    {36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, NO_LED, 24, 23},
    {22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, NO_LED, 11, 10, 9},
    {8, 7, 6, NO_LED, NO_LED, 5, NO_LED, NO_LED, NO_LED, 4, 3, NO_LED, 2, 1, 0},
}, {
    {220, 64}, {205, 64}, {190, 64}, {170, 64}, {151, 64}, {95, 64}, {39, 64}, {21, 64}, {2, 64},
    {224, 48}, {209, 48}, {189, 48}, {168, 48}, {153, 48}, {138, 48}, {123, 48}, {108, 48}, {93, 48}, {78, 48}, {63, 48}, {49, 48}, {34, 48}, {9, 48},
    {224, 32}, {200, 32}, {175, 32}, {161, 32}, {146, 32}, {131, 32}, {116, 32}, {101, 32}, {86, 32}, {71, 32}, {56, 32}, {41, 32}, {26, 32}, {6, 32},
    {224, 16}, {205, 16}, {187, 16}, {172, 16}, {157, 16}, {142, 16}, {127, 16}, {112, 16}, {97, 16}, {82, 16}, {67, 16}, {52, 16}, {37, 16}, {22, 16}, {4, 16},
    {224, 0}, {202, 0}, {179, 0}, {164, 0}, {149, 0}, {134, 0}, {119, 0}, {105, 0}, {90, 0}, {75, 0}, {60, 0}, {45, 0}, {30, 0}, {15, 0}, {0, 0},
}, {
    4, 4, 4, 1, 1, 1, 1, 1, 1,
    4, 4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
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
