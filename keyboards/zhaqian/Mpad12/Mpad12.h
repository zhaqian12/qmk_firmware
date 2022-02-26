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

#pragma once

#include "quantum.h"

#define LAYOUT( \
	     K01, K02,           \
	     K11, K12, K13, K14, \
	     K21, K22, K23, K24, \
	K30, K31, K32, K33, K34  \
) { \
	{ KC_NO, K01,   K02,   KC_NO, KC_NO }, \
	{ KC_NO, K11,   K12,   K13,   K14 }, \
	{ KC_NO, K21,   K22,   K23,   K24 }, \
	{ K30,   K31,   K32,   K33,   K34 }  \
}

enum custom_keycodes {
#ifdef ALT_TAB_MARCO_ENABLE
#ifdef VIA_ENABLE
    ATR = USER00,			//alt_shift_tab
#else
    ATR = SAFE_RANGE,		//alt_shift_tab
#endif
    ATF,					//alt_tab
#endif
#ifdef RGB_MATRIX_CONTROL_ENABLE
	RGB_CTRL_SW,
#endif
};

