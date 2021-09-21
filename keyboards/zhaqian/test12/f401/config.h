/* Copyright 2021 JasonRen(biu)
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

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 5

/* key matrix pins */
#define MATRIX_ROW_PINS { A0, A1, A2}
#define MATRIX_COL_PINS { A3, A4, A5, A6, A7 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW


#ifdef RGB_MATRIX_ENABLE
#    define RGB_DI_PIN B5
#    define RGBLED_NUM 16
#    define DRIVER_LED_TOTAL RGBLED_NUM
#define WS2812_PWM_DRIVER PWMD3
#define WS2812_PWM_CHANNEL 2
#define WS2812_PWM_PAL_MODE 2
#define WS2812_DMA_STREAM STM32_DMA1_STREAM2
#define WS2812_DMA_CHANNEL 5
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#    define RGB_DISABLE_WHEN_USB_SUSPENDED true
#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define RGBLIGHT_ANIMATIONS
#define RGB_MATRIX_CUSTOM_EFFECT_ANIMATION
#endif

#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { B1 }
#define ENCODERS_PAD_B { B3 }
#define ENCODER_RESOLUTIONS {4}
#endif

#ifdef OLED_DRIVER_ENABLE
#    define OLED_DISPLAY_128X64
#    define I2C_DRIVER I2CD1
#    define I2C1_TIMINGR_PRESC 0U
#    define I2C1_TIMINGR_SCLDEL 7U
#    define I2C1_TIMINGR_SDADEL 0U
#    define I2C1_TIMINGR_SCLH 38U
#    define I2C1_TIMINGR_SCLL 129U
#    define OLED_TIMEOUT 60000  // 60秒无操作关闭OLED
#    define OLED_FONT_HEIGHT 8
#    define OLED_FONT_WIDTH 6
#    define OLED_FONT_H "../../nfont.c"
#endif

