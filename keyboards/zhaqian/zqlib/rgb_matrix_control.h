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
 * please enable RGB_MATRIX_CONTROL in rules.mk,
 */

#ifndef ZQ_EEPROM_ADDR
#define ZQ_EEPROM_ADDR VIA_EEPROM_CUSTOM_CONFIG_ADDR
#endif

#ifndef VIA_EEPROM_CUSTOM_CONFIG_SIZE
#define VIA_EEPROM_CUSTOM_CONFIG_SIZE 6
#endif

void rgb_matrix_control_init(void);                                     // init rgb control information from eeprom
void underglow_rgb_toggle(void);                                        // rgb toggle for underglow rgb light
void key_backlight_rgb_toggle(void);                                    // rgb toggle for key rgb backlight
#ifdef LOGO_RGB_MATRIX_CONTROL_ENABLE
void logo_rgb_toggle(void);
#endif




