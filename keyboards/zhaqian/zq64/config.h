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

#pragma once

#include "config_common.h"

#define VENDOR_ID       0x00AA
#define PRODUCT_ID      0xAA0E
#define DEVICE_VER      0x0001
#define MANUFACTURER    ZhaQian
#define PRODUCT         zq64


#define MATRIX_ROWS 5
#define MATRIX_COLS 14

#define MATRIX_ROW_PINS { B15, A8, A9, B3, B10 }
#define MATRIX_COL_PINS { B12, B13, B14, A15, B4, B5, A2, A3, A4, A5, A6, A7, B0, B1}
#define UNUSED_PINS

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

// #define QMK_KEYS_PER_SCAN 12
// #define FORCE_NKRO

#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN A10
#define RGBLED_NUM 64
#define DRIVER_LED_TOTAL RGBLED_NUM
#define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 2
#define WS2812_DMA_STREAM STM32_DMA1_STREAM5
#define WS2812_DMA_CHANNEL 5
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_ANIMATION
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#ifdef RGB_MATRIX_CUSTOM_KB
#define RGB_MATRIX_CUSTOM_ANIMATION
#endif
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
#endif

#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { A0 }
#define ENCODERS_PAD_B { A1 }
#define ENCODER_RESOLUTION 4
#ifdef ENCODER_TRIGGER_ENABLE
#define ENCODER_PAD_A_KEY_POS {4, 4}
#define ENCODER_PAD_B_KEY_POS {3, 4}
#endif
#endif


