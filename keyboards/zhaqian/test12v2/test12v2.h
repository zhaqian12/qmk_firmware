/* Copyright 2020 zvecr <git@zvecr.com>
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
	K00, K01, K02, K03, K04, \
	K10, K11, K12, K13, K14, \
	K20, K21, K22, K23, K24  \
) { \
	{ K00,   K01,   K02,   K03,   K04 }, \
	{ K10,   K11,   K12,   K13,   K14 }, \
	{ K20,   K21,   K22,   K23,   K24 }  \
}


//custom keycodes
enum custom_keycodes {
#ifdef ALT_TAB_MARCO_ENABLE
#ifdef VIA_ENABLE
    ATR = USER00,			//alt_shift_tab
#else
    ATR = SAFE_RANGE,
#endif
    ATF,					//alt_tab
#endif
#if defined RGB_MATRIX_CONTROL_ENABLE && !defined RGB_MATRIX_CONTROL_REV2_ENABLE
	UGLRGBTog,				//rgb toggle for underglow rgb light
	KBLRGBTog,				//rgb toggle for key rgb backlight
#endif
#ifdef UNDERGLOW_RGB_MATRIX_ENABLE
	UGLFIXEDRGBMODF,		//underglow light fixed and only changes rgb effects of backlight
    UGLFIXEDRGBMODR,
#endif
};


