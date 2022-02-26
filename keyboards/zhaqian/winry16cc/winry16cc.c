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

#include "winry16cc.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
{
    {NO_LED,NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
}, {
    {160, 0}, {200, 20}, {200, 40}, {160, 60},
    {80, 60}, {20, 60}, {20, 20}, {80, 0},
}, {
    2, 2, 2, 2, 2, 2, 2, 2,
}
};

void rgb_matrix_indicators_kb(void) {
//  layers indicators
    switch(biton32(layer_state)) {
        case 1: rgb_matrix_set_color(0, 0, 0, 255); break;
        case 2: rgb_matrix_set_color(0, 0, 255, 0); break;
        case 3: rgb_matrix_set_color(0, 255, 0, 0); break;
        default: break;
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


