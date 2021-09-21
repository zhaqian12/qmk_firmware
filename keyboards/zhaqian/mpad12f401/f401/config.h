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
#define MATRIX_ROWS 4
#define MATRIX_COLS 5


#define MATRIX_ROW_PINS { A0,  A1,  A2,  A3}
#define MATRIX_COL_PINS { A4,  A5,  A6, A7,  A8}

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW


/* RGN Matrix */
#ifdef RGB_MATRIX_ENABLE

#    define RGB_DI_PIN B5
#    define RGBLED_NUM 18
#    define DRIVER_LED_TOTAL RGBLED_NUM


#define WS2812_PWM_DRIVER PWMD3  // default: PWMD2
#define WS2812_PWM_CHANNEL 2  // default: 2
#define WS2812_PWM_PAL_MODE 2  // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 2
#define WS2812_DMA_STREAM STM32_DMA1_STREAM2  // DMA Stream for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.
#define WS2812_DMA_CHANNEL 5  // DMA Channel for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.


#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#    define RGBLIGHT_VAL_STEP 15
#    define RGB_DISABLE_WHEN_USB_SUSPENDED true
#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define RGBLIGHT_ANIMATIONS

// #    define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_RGB

#endif


#ifdef RGBLIGHT_ENABLE

#    define RGB_DI_PIN B5
#    define RGBLED_NUM 18
#    define DRIVER_LED_TOTAL RGBLED_NUM
#    define RGBLIGHT_LIMIT_VAL 200
#    define RGBLIGHT_SLEEP

#define WS2812_PWM_DRIVER PWMD3  // default: PWMD2
#define WS2812_PWM_CHANNEL 2  // default: 2
#define WS2812_PWM_PAL_MODE 2  // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 2
#define WS2812_DMA_STREAM STM32_DMA1_STREAM2  // DMA Stream for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.
#define WS2812_DMA_CHANNEL 5  // DMA Channel for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.



// #    define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_RGB

#endif



#ifdef ENCODER_ENABLE

#define ENCODERS_PAD_A { A9  }
#define ENCODERS_PAD_B { A10 }

#define ENCODER_RESOLUTIONS { 4}

#endif

#ifdef JOYSTICK_ENABLE
#define JOYSTICK_BUTTON_COUNT 0
#define JOYSTICK_AXES_COUNT 2
#endif

#ifdef OLED_DRIVER_ENABLE

#    define I2C_DRIVER I2CD2

#    define I2C2_SCL_BANK	GPIOB
#    define I2C2_SCL 0
#    define I2C2_SDA_BANK GPIOB
#    define I2C2_SDA 1

#define OLED_DISPLAY_128X64
#define OLED_TIMEOUT 100000
#define OLED_FONT_HEIGHT 8
#define OLED_FONT_WIDTH 6
#define OLED_FONT_H "nfont.c"
#endif


#ifdef VIAL_ENABLE
#define VIAL_KEYBOARD_UID {0x35, 0x3E, 0x0D, 0xE8, 0xBF, 0x71, 0x4C, 0xAF}
#ifdef VIAL_ENCODERS_ENABLE
#define VIAL_ENCODER_KEYCODE_DELAY 10
#endif
#endif
