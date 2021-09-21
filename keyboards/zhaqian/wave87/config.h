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

/* USB Device descriptor parameter */
#define VENDOR_ID       0x00AA
#define PRODUCT_ID      0xAA0B
#define DEVICE_VER      0x0001
#define MANUFACTURER    ZhaQian
#define PRODUCT         wave87
#define DESCRIPTION     Keyboard

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 17

/* key matrix pins */
#define MATRIX_ROW_PINS { D2, D1, D0, B2, D6, D4 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B0, F0, F1, C6, B6, B5, B4, D7, C7, B3, D3, D5 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 1

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 4
#define FORCE_NKRO

#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN B7
#define RGBLED_NUM 3
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 220
#define RGB_DISABLE_WHEN_USB_SUSPENDED true
#define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define DISABLE_RGB_MATRIX_BAND_SAT
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
#define DISABLE_RGB_MATRIX_DUAL_BEACON
#define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define DISABLE_RGB_MATRIX_HUE_BREATHING
#define DISABLE_RGB_MATRIX_HUE_PENDULUM
#define DISABLE_RGB_MATRIX_HUE_WAVE
#endif

#ifdef RGB_MATRIX_CUSTOM_KB
#define RGB_MATRIX_EFFECT_CYCLE_BREATHING
#define RGB_MATRIX_EFFECT_CYCLE_IN_OUT
#define RGB_MATRIX_EFFECT_KITT_RGB
#endif
