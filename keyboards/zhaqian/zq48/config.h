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

#define VENDOR_ID       0x00AA
#define PRODUCT_ID      0xAA07
#define DEVICE_VER      0x0001
#define MANUFACTURER    ZhaQian
#define PRODUCT         zq48


#define MATRIX_ROWS 4
#define MATRIX_COLS 14

#define MATRIX_ROW_PINS { F7, F6, D7, D6 }
#define MATRIX_COL_PINS { D0, D1, D2, D3, D5, B4, F5, F4, F1, F0, B0, B1, B2, B3 }
#define UNUSED_PINS

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#define QMK_KEYS_PER_SCAN 12
#define FORCE_NKRO

#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN B7
#define RGBLED_NUM 58
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_CENTER {110, 34}
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_ANIMATION
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
#ifdef RGB_MATRIX_CUSTOM_KB
#define ENABLE_RGB_MATRIX_FRACTAL_RGB
#define ENABLE_RGB_MATRIX_CANDY_TAP
#define ENABLE_RGB_MATRIX_REACTIVE_MULTICROSS_RGB
#define ENABLE_RGB_MATRIX_REACTIVE_MULTINEXUS_RGB
#define ENABLE_RGB_MATRIX_REACTIVE_MULTIWIDE_RGB
#endif
#endif

#ifdef UNDERGLOW_RGB_MATRIX_ENABLE
#define UG_RGB_MATRIX_ANIMATIONS
#define UNDERGLOW_RGB_MATRIX_API_DISABLE
#endif

#ifdef OPENRGB_ENABLE
#define OPENRGB_DIRECT_MODE_USE_UNIVERSAL_BRIGHTNESS
#endif

#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT
#define NO_ACTION_FUNCTION
#define NO_MUSIC_MODE
