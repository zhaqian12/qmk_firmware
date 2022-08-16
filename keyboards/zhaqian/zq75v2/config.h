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
#define PRODUCT_ID      0xAA01
#define DEVICE_VER      0x0001
#define MANUFACTURER    ZhaQian

#define PRODUCT         剳牵的ZQ75V2pro


#define MATRIX_ROWS 6
#define MATRIX_COLS 15

#define MATRIX_ROW_PINS { B4, B3, B2, A0, B7, D2 }
#define MATRIX_COL_PINS { F2, F3, F4, F5, F6, F7, A1, A2, D6, D5, D4, D3, F1, F0, B5 }
#define UNUSED_PINS


#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#define QMK_KEYS_PER_SCAN 12
#define FORCE_NKRO

#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN C6
#define RGBLED_NUM 99
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_CENTER {106, 32}

#define RGB_MATRIX_ANIMATION
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
#ifdef RGB_MATRIX_CUSTOM_KB
#define RGB_MATRIX_CUSTOM_ANIMATION
#endif
#endif

#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { B0 }
#define ENCODERS_PAD_B { B1 }

#define ENCODER_RESOLUTION 4
#ifdef ENCODER_TRIGGER_ENABLE
#define ENCODER_PAD_A_KEY_POS {14, 3}
#define ENCODER_PAD_B_KEY_POS {13, 3}
#endif
#endif

#ifdef VIA_ENABLE
#define DYNAMIC_KEYMAP_LAYER_COUNT 11
#endif


#ifdef OLED_ENABLE
#define OLED_DISPLAY_128X64
#define OLED_TIMEOUT 100000
#define OLED_FONT_HEIGHT 8
#define OLED_FONT_WIDTH 6
#define OLED_FONT_H "zfont.c"
#endif

#ifdef ALT_TAB_MARCO_ENABLE
#define ALT_TAB_MARCO_DELAY 1200
#endif

#ifdef OPENRGB_ENABLE
#define OPENRGB_DIRECT_MODE_USE_UNIVERSAL_BRIGHTNESS
#endif

#ifdef RADIAL_CONTROLLER_ENABLE
#define RADIAL_CONTROLLER_RESOLUTION 100
#define RADIAL_CONTROLLER_ROTATION_STEP 10
#define RADIAL_CONTROLLER_TIMER_DELAY 15
#define RADIAL_CONTROLLER_ROTATION_CONTINUE_BUTTON_ENABLE
#endif

#ifdef UNDERGLOW_RGB_MATRIX_ENABLE
#define UG_RGB_MATRIX_ANIMATIONS
#define UG_RGB_MATRIX_WPM_ANIMATIONS
#define UNDERGLOW_RGB_MATRIX_API_DISABLE
#endif

#ifdef RGB_INDICATORS_ENABLE
#define RGB_INDICATOR_CAPS_LOCK_LED {56}
#define CAPS_LOCK_STATIC_HSV {0, 255, 200}
// #define RGB_INDICATOR_NUM_LOCK_LED {14}
// #define NUM_LOCK_STATIC_HSV {120, 255, 200}
#define RGB_INDICATORS_BREATHING
#define RGB_INDICATORS_CYCLEBREATHING
#define RGB_INDICATORS_CYCLEALL
#endif


