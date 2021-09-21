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
#define PRODUCT_ID      0xAAAC
#define DEVICE_VER      0x0001
#define MANUFACTURER    ZhaQian
#define PRODUCT         Winry 16CC
#define DESCRIPTION     Keyboard

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 16

/* key matrix pins */
#define MATRIX_ROW_PINS { F4 }
#define MATRIX_COL_PINS { F0, B1, B2, B7, F6, E6, D3, D5, F7, F5, B4, D4, C6, B6, B5, D6 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 4
#define FORCE_NKRO

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


#define RGB_DI_PIN B3
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS

#define RGBLED_NUM 8
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LIMIT_VAL 150
#endif

#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN B3
#define RGBLED_NUM 8
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_DISABLE_WHEN_USB_SUSPENDED true
#define RGB_MATRIX_CENTER {112, 32}
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
#endif

#define DYNAMIC_KEYMAP_MACRO_COUNT 16


