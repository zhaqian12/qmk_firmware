/* Copyright 2023 ZhaQian
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

#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
	{
        // Key Matrix to LED Index
		{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14},
		{15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29},
		{30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44},
		{45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59},
		{60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73},
		{74, 75, 76, NO_LED, NO_LED,77, 78, 79,NO_LED,NO_LED, 80, 81, 82, 83, 84},
        // Underglow (82 -> 102)
        // {81, 82, 83, 84, 85, 86, 87},
        // {88, NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,89},
        // {90, NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,91},
        // {92, NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,93},
        // {94, 95, 96, 97, 98, 99, 100},
	}, {
        // LED Index to Physical Position
		{7, 8},   {26, 8},  {41, 8},  {56, 8},  {71, 8},  {90, 8},  {105, 8},  {119, 8},  {134, 8},  {153, 8},  {168, 8},  {183, 8},  {198, 8},  {217, 8},  {230, 8},
		{7, 21},  {22, 21}, {37, 21}, {52, 21}, {67, 21}, {82, 21}, {97, 21},  {112, 21}, {127, 21}, {142, 21}, {157, 21}, {172, 21}, {187, 21}, {209, 21}, {230, 21},
		{11, 31}, {30, 31}, {45, 31}, {60, 31}, {75, 31}, {90, 31}, {105, 31}, {119, 31}, {134, 31}, {149, 31}, {164, 31}, {179, 31}, {194, 31}, {213, 31}, {230, 31},
		{13, 41}, {34, 41}, {49, 41}, {63, 41}, {78, 41}, {93, 41}, {108, 41}, {123, 41}, {138, 41}, {153, 41}, {168, 41}, {183, 41}, {198, 41}, {207, 41}, {230, 41},
		{15, 51}, {37, 51}, {52, 51}, {67, 51}, {82, 51}, {97, 51}, {112, 51}, {127, 51}, {142, 51}, {157, 51}, {172, 51}, {187, 51}, {202, 51}, {217, 51},
		{9, 62},  {28, 62}, {47, 62}, {77, 62}, {103, 62}, {114, 62}, {140, 62}, {157, 62}, {172, 62}, {187, 62}, {202, 62},{217, 62},
        // Underglow (82 -> 102)
		//    {15, 2}, {49, 2}, {78, 2}, {112, 2}, {142, 2}, {175, 2}, {205, 2},
        // {7, 10},                                                       {217, 10},
        // {7, 31},                                                       {217, 31},
        // {7, 51},                                                       {217, 51},
        //    {19, 56}, {56, 56}, {90, 56}, {119, 56}, {149, 56}, {179, 56}, {207, 56},

        {207, 56}, {179, 56},{149, 56},{119, 56},{90, 56},{56, 56},{19, 56}, {7, 51}, {7, 31},{7, 10},  {15, 2},{49, 2},{78, 2},{112, 2},{142, 2},{175, 2},{205, 2},{217, 10},{217, 31},{217, 51},

	}, {
        //Key matrix (0 -> 81)
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        // Underglow (82 -> 102)
         2, 2, 2, 2, 2, 2, 2,
        2,                  2,
        2,                  2,
        2,                  2,
         2, 2, 2, 2, 2, 2, 2,

	}
};

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }

    HSV hsv = {0, 255, rgb_matrix_get_val()};
    RGB rgb = hsv_to_rgb(hsv);
    switch(biton32(layer_state)) {
        case 1: rgb_matrix_set_color(1, rgb.r, rgb.g, rgb.b); break;
        case 2: rgb_matrix_set_color(2, rgb.r, rgb.g, rgb.b); break;
        case 3: rgb_matrix_set_color(3, rgb.r, rgb.g, rgb.b); break;
        case 4: rgb_matrix_set_color(4, rgb.r, rgb.g, rgb.b); break;
        case 5: rgb_matrix_set_color(5, rgb.r, rgb.g, rgb.b); break;
        case 6: rgb_matrix_set_color(6, rgb.r, rgb.g, rgb.b); break;
        default: break;
    }
    return true;
}


#endif
