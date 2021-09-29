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
#define PRODUCT_ID      0xAA03
#define DEVICE_VER      0x0001
#define MANUFACTURER    ZhaQian
#define PRODUCT         zq80
#define DESCRIPTION     Keyboard

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 15

/* key matrix pins */
#define MATRIX_ROW_PINS { F5, F6, F7, B6, B5, B7 }
#define MATRIX_COL_PINS { D0, D1, D2, D3, D4, D5, B4, D7, D6, F0, F1, F4, B0, B1, B2 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 1

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define FORCE_NKRO
#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 4

#ifdef RGBLIGHT_ENABLE
#define RGB_DI_PIN B3
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 102
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LIMIT_VAL 200
#endif

#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN B3
#define RGBLED_NUM 102
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_DISABLE_WHEN_USB_SUSPENDED true
#define RGB_MATRIX_CENTER {106, 32}
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
#endif

#ifdef RGB_MATRIX_CONTROL_ENABLE
#define LOGO_RGB_MATRIX_CONTROL_ENABLE
#endif

#ifdef UNDERGLOW_RGB_MATRIX_ENABLE
#define UG_RGB_MATRIX_ANIMATIONS
#endif

#ifdef RGB_MATRIX_CUSTOM_KB
#define RGB_MATRIX_EFFECT_FRACTAL_RGB
#define RGB_MATRIX_EFFECT_CANDY_TAP
#define RGB_MATRIX_EFFECT_REACTIVE_MULTICROSS_RGB
#define RGB_MATRIX_EFFECT_REACTIVE_MULTINEXUS_RGB
#define RGB_MATRIX_EFFECT_REACTIVE_MULTIWIDE_RGB
#endif

/* disable action features */
#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT
#define NO_ACTION_FUNCTION


