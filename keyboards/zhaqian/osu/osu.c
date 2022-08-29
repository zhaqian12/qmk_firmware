/* Copyright 2022 ZhaQian
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

#include "osu.h"

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
    {
        {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
        {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED}
    }, {
        {0, 64}, {44, 64}, {88, 64}, {132, 64}, {176, 64}, {220, 64},
        {220, 0}, {176, 0}, {132, 0}, {88, 0}, {44, 0}, {0, 0}
    }, {
        2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2
    }
};

#endif
