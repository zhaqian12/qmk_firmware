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

#include "config_common.h"

#define MATRIX_ROWS 4
#define MATRIX_COLS 14

#define MATRIX_ROW_PINS { B3, B4, B9, B8 }
#define MATRIX_COL_PINS { B14, B13, B12, B0, A7, A6, A5, A4, A3, A2, A1, A0, B15, B7 }

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#define FORCE_NKRO

#ifdef RGB_MATRIX_ENABLE
#define RGBLED_NUM 66
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_ANIMATION
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
#ifdef RGB_MATRIX_CUSTOM_KB
#define RGB_MATRIX_CUSTOM_ANIMATION
#endif
#ifdef UNDERGLOW_RGB_MATRIX_ENABLE
#define UG_RGB_MATRIX_ANIMATIONS
#endif
#endif

#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { B5 }
#define ENCODERS_PAD_B { B6 }
#define ENCODER_RESOLUTION 4
#ifdef ENCODER_TRIGGER_ENABLE
#define ENCODER_PAD_A_KEY_POS {12, 1}
#define ENCODER_PAD_B_KEY_POS {12, 2}
#endif
#endif

#ifdef VIA_ENABLE
#define DYNAMIC_KEYMAP_LAYER_COUNT 6
#define DYNAMIC_KEYMAP_MACRO_COUNT 15
#endif

#ifdef OPENRGB_ENABLE
#define OPENRGB_DIRECT_MODE_USE_UNIVERSAL_BRIGHTNESS
#endif

#ifdef DYNAMIC_RGB_INDICATORS_ENABLE
#define ENABLE_RGB_INDICATORS_ANIMATIONS
#endif
