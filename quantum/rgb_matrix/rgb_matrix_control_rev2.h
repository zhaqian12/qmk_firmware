/* Copyright 2021 zhaiqian
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

#include "quantum.h"

/*
 * if you want to use these functions,
 * please enable RGB_MATRIX_CONTROL_REV2 in rules.mk,
 */

// define the address of rgb control variables to store in eeprom (use EECONFIG_KEYBOARD)
#define EECONFIG_RGBCONTROL  (uint8_t *)15

void rgb_matrix_control_init(void);
void rgb_matrix_control_sw(void);
bool process_rgbcontrol(const uint16_t keycode, const keyrecord_t *record);
