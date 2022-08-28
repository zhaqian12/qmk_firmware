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
#define PRODUCT_ID      0xAA12
#define DEVICE_VER      0x0001
#define MANUFACTURER    ZhaQian
#define PRODUCT         osu


#define DIRECT_PINS { \
    {B12, B13, B14, A15, B3, B4, B5}, \
    {B6, B8, B7} \
}
#define UNUSED_PINS

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#define QMK_KEYS_PER_SCAN 12
#define FORCE_NKRO

#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN B10
#define WS2812_PWM_DRIVER PWMD2
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 1
#define WS2812_DMA_STREAM STM32_DMA1_STREAM7
#define WS2812_DMA_CHANNEL 3
#define RGBLED_NUM 12
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_CENTER {110, 34}
#define RGB_MATRIX_ANIMATION
#endif


