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
#define PRODUCT_ID      0xAA0A
#define DEVICE_VER      0x0001
#define MANUFACTURER    ZhaQian
#define PRODUCT         zq11800
#define DESCRIPTION     Keyboard

/* key matrix size */
#define MATRIX_ROWS 7
#define MATRIX_COLS 15

/* key matrix pins */
#define MATRIX_ROW_PINS { B2, E6, B7, D0, D1, D2, D3 }
#define MATRIX_COL_PINS { F1, F4, F5, F6, F7, D4, D6, D7, B4, B5, B6, C6, C7, D5, B3 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 1

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define USB_POLLING_INTERVAL_MS 2
#define QMK_KEYS_PER_SCAN 4
#define FORCE_NKRO

#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN F0
#define RGBLED_NUM 98
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_DISABLE_WHEN_USB_SUSPENDED true
#define RGB_MATRIX_CENTER {106, 32}
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
#endif

#ifdef RGB_MATRIX_CUSTOM_KB
#define RGB_MATRIX_EFFECT_CYCLE_BREATHING
#define RGB_MATRIX_EFFECT_CYCLE_IN_OUT
#define RGB_MATRIX_EFFECT_FRACTAL_RGB
#define RGB_MATRIX_EFFECT_CANDY_TAP
#define RGB_MATRIX_EFFECT_KITT_RGB
#define RGB_MATRIX_EFFECT_REACTIVE_MULTICROSS_RGB
#define RGB_MATRIX_EFFECT_REACTIVE_MULTINEXUS_RGB
#define RGB_MATRIX_EFFECT_REACTIVE_MULTIWIDE_RGB
#endif

#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { B1 }
#define ENCODERS_PAD_B { B0 }
#define ENCODER_RESOLUTION 2
#endif

#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT

#ifdef VIAL_ENABLE
#define VIAL_KEYBOARD_UID {0xD0, 0xFE, 0x76, 0xEE, 0x9B, 0x44, 0x25, 0x84}
#ifdef VIAL_ENCODERS_ENABLE
#define VIAL_ENCODER_DEFAULT {KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU}
#define VIAL_ENCODER_KEYCODE_DELAY 10
#endif
#endif
