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

// define the address of rgb control variables to store in eeprom (use EECONFIG_KEYBOARD)
#define EECONFIG_UGRGBTOG  (uint8_t *)15
#define EECONFIG_KRGBTOG  (uint8_t *)16
#ifdef LOGO_RGB_MATRIX_CONTROL_ENABLE
#define EECONFIG_LGRGBTOG  (uint8_t *)17
#endif

void rgb_matrix_control_init(void);                                     // init rgb control information from eeprom
void underglow_rgb_toggle(void);                                        // rgb toggle for underglow rgb light
void key_backlight_rgb_toggle(void);                                    // rgb toggle for key rgb backlight
#ifdef LOGO_RGB_MATRIX_CONTROL_ENABLE
void logo_rgb_toggle(void);
#endif

bool process_rgbcontrol(const uint16_t keycode, const keyrecord_t *record);


