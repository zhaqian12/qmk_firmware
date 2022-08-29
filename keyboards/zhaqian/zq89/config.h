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
#define MATRIX_COLS 17

#define MATRIX_ROW_PINS { A4, A5, A6, A7, B0, B10 }
#define MATRIX_COL_PINS { A0, A1, A2, A3, B1, B12, B13, B14, B15, A8, A10, A15, B3, B4, B6, B7, B8 }
#define UNUSED_PINS

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#define FORCE_NKRO

#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN B5
#define WS2812_PWM_DRIVER PWMD3
#define WS2812_PWM_CHANNEL 2
#define WS2812_PWM_PAL_MODE 2
#define WS2812_DMA_STREAM STM32_DMA1_STREAM2
#define WS2812_DMA_CHANNEL 5
#define RGBLED_NUM 4
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 250
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_ANIMATION
#ifdef RGB_MATRIX_CUSTOM_KB
#define ENABLE_RGB_MATRIX_CYCLE_BREATHING
#define ENABLE_RGB_MATRIX_KITT_RGB
#endif
#endif

#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { C13, C15 }
#define ENCODERS_PAD_B { B9, C14 }
#ifdef ENCODER_TRIGGER_ENABLE
#define ENCODER_PAD_A_KEY_POS {16, 2}, {16, 3}
#define ENCODER_PAD_B_KEY_POS {15, 2}, {13, 3}
#endif
#endif

#ifdef RADIAL_CONTROLLER_ENABLE
#define RADIAL_CONTROLLER_RESOLUTION 100
#define RADIAL_CONTROLLER_ROTATION_STEP 10
#define RADIAL_CONTROLLER_TIMER_DELAY 15
#define RADIAL_CONTROLLER_ROTATION_CONTINUE_BUTTON_ENABLE
#endif
