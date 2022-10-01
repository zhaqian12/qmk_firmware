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

#define MATRIX_ROWS 4
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS { B7, D2, D3, D5 }
#define MATRIX_COL_PINS { B4, B5, B6, C6, C7, F0 }

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#define FORCE_NKRO

#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN F6
#define RGBLED_NUM 18
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#endif

#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A {B1, B3}
#define ENCODERS_PAD_B {B0, B2}
#define ENCODER_RESOLUTIONS {4, 2}
#ifdef ENCODER_TRIGGER_ENABLE
#define ENCODER_PAD_A_KEY_POS {4, 0}, {5, 1}
#define ENCODER_PAD_B_KEY_POS {3, 0}, {5, 0}
#endif
#endif

#ifdef OLED_ENABLE
#define OLED_BRIGHTNESS 100
#define OLED_TIMEOUT 120000
#define OLED_FONT_HEIGHT 8
#define OLED_FONT_WIDTH 6
#define OLED_FONT_H "zfont.c"
#endif

#ifdef RGB_MATRIX_CONTROL_ENABLE
#define RGB_MATRIX_CONTROL_SWITCH_ENABLE
#endif

#ifdef OPENRGB_ENABLE
#define OPENRGB_DIRECT_MODE_USE_UNIVERSAL_BRIGHTNESS
#endif

#ifdef RADIAL_CONTROLLER_ENABLE
#define RADIAL_CONTROLLER_ROTATION_CONTINUE_BUTTON_ENABLE
#endif

#ifdef JOYSTICK_TRIGGER_ENABLE
#define JOYSTICK_AXES_X_PIN {D7}
#define JOYSTICK_AXES_Y_PIN {D6}
#define JOYSTICK_AXES_PX_KEY_POS {0, 0}
#define JOYSTICK_AXES_NX_KEY_POS {5, 3}
#define JOYSTICK_AXES_PY_KEY_POS {0, 1}
#define JOYSTICK_AXES_NY_KEY_POS {0, 2}
#endif

#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT
#define NO_ACTION_FUNCTION
#define NO_MUSIC_MODE

