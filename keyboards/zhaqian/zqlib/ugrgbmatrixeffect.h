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
 * please enable UNDERGLOW_RGB_MATRIX_ENABLE in rules.mk,
 */

#ifndef ZQ_EEPROM_ADDR
#define ZQ_EEPROM_ADDR VIA_EEPROM_CUSTOM_CONFIG_ADDR
#endif

#ifndef VIA_EEPROM_CUSTOM_CONFIG_SIZE
#define VIA_EEPROM_CUSTOM_CONFIG_SIZE 6
#endif

void underglow_rgb_matrix_init(void);                                       // init underglow rgb matrix effect mode from eeprom
void underglow_rgb_mode_step(void);                                             // underglow rgb matrix effect mode step

#ifdef UG_RGB_MATRIX_ANIMATIONS                                             // enable all underglow rgb matrix effect
#define UG_RGB_MATRIX_BREATHING
#define UG_RGB_MATRIX_CYCLEBREATHING
#define UG_RGB_MATRIX_CYCLEBANDVAL
#define UG_RGB_MATRIX_CYCLEBANDPINWHEELVAL
#define UG_RGB_MATRIX_CYCLEALL
#define UG_RGB_MATRIX_CYCLELEFTRIGHT
#define UG_RGB_MATRIX_CYCLEUPDOWN
#define UG_RGB_MATRIX_CYCLEOUTIN
#define UG_RGB_MATRIX_RAINBOWPINWHEEL
#define UG_RGB_MATRIX_CYCLESPIRAL
#endif

#ifdef UG_RGB_MATRIX_BREATHING
void Breathing(void);                                                     // Breathing effect for underglow rgb light
#endif

#ifdef UG_RGB_MATRIX_CYCLEBREATHING
void CycleBreathing(void);                                                  // CycleBreathing effect for underglow rgb light
#endif

#ifdef UG_RGB_MATRIX_CYCLEBANDVAL
void CycleBandVal(void);                                                    // CycleBandVal effect for effect for underglow rgb light
#endif

#ifdef UG_RGB_MATRIX_CYCLEBANDPINWHEELVAL
void CycleBandPinwheelVal(void);                                            // CycleBandPinwheelVal effect for underglow rgb light
#endif

#ifdef UG_RGB_MATRIX_CYCLEALL
void CycleAll(void);                                                        // CycleAll effect for effect for underglow rgb light
#endif

#ifdef UG_RGB_MATRIX_CYCLELEFTRIGHT
void CycleLeftRight(void);                                                  // CycleLeftRight effect for effect for underglow rgb light
#endif

#ifdef UG_RGB_MATRIX_CYCLEUPDOWN
void CycleUpDown(void);                                                     // CycleUpDown effect for effect for underglow rgb light
#endif

#ifdef UG_RGB_MATRIX_CYCLEOUTIN
void CycleOutIn(void);                                                      // CycleOutIn effect for effect for underglow rgb light
#endif

#ifdef UG_RGB_MATRIX_RAINBOWPINWHEEL
void RainbowPinwheel(void);                                                 // RainbowPinwheel effect for effect for underglow rgb light
#endif

#ifdef UG_RGB_MATRIX_CYCLESPIRAL
void CycleSpiral(void);                                                     // CycleSpiral effect for effect for underglow rgb light
#endif




