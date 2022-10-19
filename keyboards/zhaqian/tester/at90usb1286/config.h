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

#include "config_common.h"

#define MATRIX_ROW_PINS { B4, B3, B2 }
#define MATRIX_COL_PINS { F2, F3, F4, F5, F6 }

#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN F7
#endif

#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { B1 }
#define ENCODERS_PAD_B { B5 }
#define ENCODER_RESOLUTIONS { 4 }
#ifdef ENCODER_TRIGGER_ENABLE
#define ENCODER_PAD_A_KEY_POS {4, 1}
#define ENCODER_PAD_B_KEY_POS {4, 2}
#endif
#endif

#ifdef UNDERGLOW_RGB_MATRIX_ENABLE
#define UG_RGB_MATRIX_ANIMATIONS
#define UG_RGB_MATRIX_WPM_ANIMATIONS
#define UNDERGLOW_RGB_MATRIX_API_DISABLE
#endif

#ifdef OPENRGB_ENABLE
#define OPENRGB_DIRECT_MODE_USE_UNIVERSAL_BRIGHTNESS
#endif

