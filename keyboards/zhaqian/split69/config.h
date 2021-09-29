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
#define PRODUCT_ID      0xAAAB
#define DEVICE_VER      0x0001
#define MANUFACTURER    ZhaQian
#define PRODUCT         split69
#define DESCRIPTION     SPLIT 69

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 9

/* key matrix pins */
#define MATRIX_ROW_PINS { B0, B1, E6, F0, F1 }                  //LEFT
#define MATRIX_COL_PINS { F4, F7, F6, F5, D4, D6, D7, C7, B4 }
#define MATRIX_ROW_PINS_RIGHT { F0, F1, F4, F5, F6 }
#define MATRIX_COL_PINS_RIGHT { D4, D6, D7, B4, B5, B6, C6, C7, D3 }

#define USE_SERIAL
#define SELECT_SOFT_SERIAL_SPEED 1
#define SOFT_SERIAL_PIN D2

#define MASTER_RIGHT

#define SPLIT_USB_DETECT
#define SPLIT_MODS_ENABLE
#define SPLIT_USB_TIMEOUT 1000

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGB_DI_PIN B7 //LEFT
// #define RGB_DI_PIN B3 //RIGHT

#ifdef RGB_DI_PIN
#define RGBLIGHT_SPLIT
#define RGBLED_NUM 21
#define RGBLED_SPLIT { 9, 12 }
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LIMIT_VAL 200
#endif

#ifdef RGB_MATRIX_ENABLE
#define RGBLED_NUM 21
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_DISABLE_WHEN_USB_SUSPENDED false
#define RGB_MATRIX_SPLIT { 9, 12 }
#define SPLIT_TRANSPORT_MIRROR
#endif

#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { B2 }
#define ENCODERS_PAD_B { B3 }
#define ENCODER_RESOLUTION 3
#endif

#ifdef VIA_ENABLE
#define DYNAMIC_KEYMAP_LAYER_COUNT 3
#endif

#ifdef OLED_DRIVER_ENABLE
#define OLED_DISPLAY_128X64
#define OLED_FONT_HEIGHT 8
#define OLED_FONT_WIDTH 6
#define OLED_FONT_H "././zfont.c"
#endif

