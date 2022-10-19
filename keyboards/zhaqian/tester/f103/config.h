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

#define MATRIX_COL_PINS { A9, A0, B15, B14, B13 }
#define MATRIX_ROW_PINS { A10, B6, C14 }

#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN B3
#define WS2812_PWM_DRIVER PWMD2
#define WS2812_PWM_CHANNEL 2
#define WS2812_PWM_PAL_MODE 2
#define WS2812_DMA_STREAM STM32_DMA1_STREAM2
#define WS2812_DMA_CHANNEL 2
#endif

#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { B1 }
#define ENCODERS_PAD_B { B3 }
#define ENCODER_RESOLUTIONS { 4 }
#ifdef ENCODER_TRIGGER_ENABLE
#define ENCODER_PAD_A_KEY_POS {4, 1}
#define ENCODER_PAD_B_KEY_POS {4, 2}
#endif
#endif

#ifdef UNDERGLOW_RGB_MATRIX_ENABLE
#undef UG_RGB_MATRIX_ANIMATIONS
#define UG_RGB_MATRIX_CYCLEOUTIN
#undef UG_RGB_MATRIX_WPM_ANIMATIONS
#endif
// #define DEBUG_EEPROM_OUTPUT
#define DEBUG_MATRIX_SCAN_RATE

#define SERIAL_DRIVER SD2
#define SD1_TX_PIN A2
#define SD1_RX_PIN A3