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

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x5001
#define DEVICE_VER      0x0001
#define MANUFACTURER    JL-K16e4
#define PRODUCT         JL-K16E4


#define MATRIX_ROWS 7
#define MATRIX_COLS 7

#define MATRIX_ROW_PINS {  B5,B6,B7,B8,B9,A3,C14}
#define MATRIX_COL_PINS {  B12,B13,B14,B15,A8,A10,B3}
#define UNUSED_PINS

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#define QMK_KEYS_PER_SCAN 12
#define FORCE_NKRO



#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { B0, A6 , A4, A1 }
#define ENCODERS_PAD_B { A7, A5 , A2, A0 }
#define ENCODER_RESOLUTION 4
#ifdef ENCODER_TRIGGER_ENABLE
#define ENCODER_PAD_A_KEY_POS {6, 2},{6, 3},{1, 5}
#define ENCODER_PAD_B_KEY_POS {5, 2},{5, 3},{0, 5}
#endif
#endif



#ifdef RADIAL_CONTROLLER_ENABLE
#define RADIAL_CONTROLLER_RESOLUTION 100
#define RADIAL_CONTROLLER_ROTATION_STEP 10
#define RADIAL_CONTROLLER_TIMER_DELAY 15
#define RADIAL_CONTROLLER_ROTATION_CONTINUE_BUTTON_ENABLE
#endif

#define RGB_DI_PIN B4
#ifdef RGB_DI_PIN 
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 16
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif

