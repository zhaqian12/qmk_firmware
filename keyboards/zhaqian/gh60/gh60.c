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

#include "gh60.h"

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
	{
		{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, NO_LED, 13},
		{14, NO_LED, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27},
		{28, NO_LED, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, NO_LED},
		{NO_LED, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, NO_LED, 52, NO_LED},
		{53, 54, NO_LED, 55, NO_LED, NO_LED, 56, NO_LED, NO_LED, NO_LED, 57, 58, NO_LED, 59, 60},
	}, {
		{7, 3}, {22, 3}, {37, 3}, {52, 3}, {67, 3}, {82, 3}, {97, 3}, {112, 3}, {127, 3}, {142, 3}, {157, 3}, {172, 3}, {187, 3}, {209, 3},
		{11, 16}, {30, 16}, {45, 16}, {60, 16}, {75, 16}, {90, 16}, {105, 16}, {119, 16}, {134, 16}, {149, 16}, {164, 16}, {179, 16}, {194, 16}, {213, 16},
		{13, 29}, {34, 29}, {49, 29}, {63, 29}, {78, 29}, {93, 29}, {108, 29}, {123, 29}, {138, 29}, {153, 29}, {168, 29}, {183, 29}, {207, 29},
		{17, 41}, {41, 41}, {56, 41}, {71, 41}, {86, 41}, {101, 41}, {116, 41}, {131, 41}, {146, 41}, {161, 41}, {175, 41}, {203, 41},
		{9, 54}, {28, 54}, {47, 54}, {103, 54}, {159, 54}, {177, 54}, {196, 54}, {215, 54},
	}, {
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4,
	}
};

#endif
