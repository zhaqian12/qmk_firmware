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

#define MATRIX_ROWS 6
#define MATRIX_COLS 15

#define MATRIX_ROW_PINS { A1, A2, A3, A4, A5, B9}
#define MATRIX_COL_PINS { A15, B3, B4, B5, B6, B7, B8, A6, A7, B13, B14, B12, B15, A8, A9 }

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

// #define FORCE_NKRO

#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN A10
#define RGBLED_NUM 2
#define DRIVER_LED_TOTAL RGBLED_NUM
#define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 2
#define WS2812_DMA_STREAM STM32_DMA1_STREAM5
#define WS2812_DMA_CHANNEL 5
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#ifdef RGB_MATRIX_CUSTOM_KB
#define ENABLE_RGB_MATRIX_CYCLE_BANDVAL
#define ENABLE_RGB_MATRIX_CYCLE_BREATHING
#define ENABLE_RGB_MATRIX_CYCLE_DOWN_UP
#endif
#endif

#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { B11 }
#define ENCODERS_PAD_B { B10 }
#define ENCODER_RESOLUTION 4
#endif

#ifdef DYNAMIC_RGB_INDICATORS_ENABLE
#define ENABLE_RGB_INDICATORS_ANIMATIONS
#endif
