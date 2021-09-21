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


/* RGN Matrix */
#ifdef RGB_MATRIX_ENABLE

#    define RGB_DI_PIN C13
#    define RGBLED_NUM 100
#    define DRIVER_LED_TOTAL RGBLED_NUM

#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180
#    define RGBLIGHT_VAL_STEP 18
#    define RGB_DISABLE_WHEN_USB_SUSPENDED true
#    define RGB_MATRIX_CENTER { 32, 96 }
#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define RGBLIGHT_ANIMATIONS

#endif


#ifdef RGBLIGHT_ENABLE

#    define RGB_DI_PIN C13
#    define RGBLED_NUM 100
#    define DRIVER_LED_TOTAL RGBLED_NUM
#    define RGBLIGHT_ANIMATIONS

#endif


#define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 5
#define DYNAMIC_KEYMAP_LAYER_COUNT 32
#define DYNAMIC_KEYMAP_MACRO_COUNT 20
#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 10240
