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
#define PRODUCT_ID      0xAA17
#define DEVICE_VER      0x0001
#define MANUFACTURER    ZhaQian
#define PRODUCT         Jane_v2_ce_slot

#define MATRIX_ROWS 6
#define MATRIX_COLS 17

#define MATRIX_ROW_PINS { B0, B1, B2, B3, D7, F0 }
#define MATRIX_COL_PINS { D0, D6, D4, D5, D3, D2, D1, B4, B5, B6, C6, C7, F7, F6, F5, F4, F1 }
#define UNUSED_PINS

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

// #define QMK_KEYS_PER_SCAN 12
// #define FORCE_NKRO

