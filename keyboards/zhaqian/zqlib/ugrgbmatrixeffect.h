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
 * define UG_RGB_MATRIX_ANIMATIONS in config.h to enable all common effect
 * define UG_RGB_MATRIX_WPM_ANIMATIONS in config.h to enable all wpm effect (needs WPM_ENABLE)
 */

// define the address of rgb control variables to store in eeprom (use EECONFIG_KEYBOARD)
#define EECONFIG_UNDERGLOWRGB (uint8_t *)18

void underglow_rgb_matrix_init(void);                                       // init underglow rgb matrix effect mode from eeprom
void underglow_rgb_mode_step(void);                                         // underglow rgb matrix effect mode step
void underglow_rgb_mode_step_reverse(void);                                 // nderglow rgb matrix effect mode step reverse

bool process_underglowrgb(const uint16_t keycode, const keyrecord_t *record);

#ifdef UG_RGB_MATRIX_ANIMATIONS                                             // enable all underglow rgb matrix effect(11)
#define UG_RGB_MATRIX_BREATHING
#define UG_RGB_MATRIX_CYCLEBREATHING
#define UG_RGB_MATRIX_CYCLEBANDVAL
#define UG_RGB_MATRIX_CYCLEBANDPINWHEELVAL
#define UG_RGB_MATRIX_CYCLEALL
#define UG_RGB_MATRIX_CYCLELEFTRIGHT
#define UG_RGB_MATRIX_CYCLEUPDOWN
#define UG_RGB_MATRIX_CYCLEOUTIN
#define UG_RGB_MATRIX_CYCLEINOUT
#define UG_RGB_MATRIX_RAINBOWPINWHEEL
#define UG_RGB_MATRIX_CYCLESPIRAL
#endif

                                                       
#if defined UG_RGB_MATRIX_WPM_ANIMATIONS && defined WPM_ENABLE                  // effects need wpm enable(5)
#define UG_RGB_MATRIX_WPMCYCLELEFTRIGHT
#define UG_RGB_MATRIX_WPMRAINBOWPINWHEEL
#define UG_RGB_MATRIX_WPMCYCLEBREATHING
#define UG_RGB_MATRIX_WPMCYCLESPIRAL
#define UG_RGB_MATRIX_WPMCYCLEINOUT
#endif

#ifdef UG_RGB_MATRIX_BREATHING
void Breathing(void);                                                       // Breathing effect for underglow rgb light
#endif

#ifdef UG_RGB_MATRIX_CYCLEBREATHING
void CycleBreathing(void);                                                  // CycleBreathing effect for underglow rgb light
#endif

#ifdef UG_RGB_MATRIX_CYCLEBANDVAL
void CycleBandVal(void);                                                    // CycleBandVal effect for underglow rgb light
#endif

#ifdef UG_RGB_MATRIX_CYCLEBANDPINWHEELVAL
void CycleBandPinwheelVal(void);                                            // CycleBandPinwheelVal effect for underglow rgb light
#endif

#ifdef UG_RGB_MATRIX_CYCLEALL
void CycleAll(void);                                                        // CycleAll effect for underglow rgb light
#endif

#ifdef UG_RGB_MATRIX_CYCLELEFTRIGHT
void CycleLeftRight(void);                                                  // CycleLeftRight effect for underglow rgb light
#endif

#ifdef UG_RGB_MATRIX_CYCLEUPDOWN
void CycleUpDown(void);                                                     // CycleUpDown effect for underglow rgb light
#endif

#ifdef UG_RGB_MATRIX_CYCLEOUTIN
void CycleOutIn(void);                                                      // CycleOutIn effect for underglow rgb light
#endif

#ifdef UG_RGB_MATRIX_CYCLEINOUT
void CycleInOut(void);                                                      // CycleInOut effect for underglow rgb light
#endif

#ifdef UG_RGB_MATRIX_RAINBOWPINWHEEL
void RainbowPinwheel(void);                                                 // RainbowPinwheel  effect for underglow rgb light
#endif

#ifdef UG_RGB_MATRIX_CYCLESPIRAL
void CycleSpiral(void);                                                     // CycleSpiral effect for underglow rgb light
#endif

#if defined UG_RGB_MATRIX_WPMCYCLELEFTRIGHT && defined WPM_ENABLE
void WpmCycleLeftRight(void);                                               // WpmCycleLeftRight effect for underglow rgb light
#endif

#if defined UG_RGB_MATRIX_WPMRAINBOWPINWHEEL && defined WPM_ENABLE
void WpmRainbowPinwheel(void);                                              // WpmRainbowPinwheel effect for underglow rgb light
#endif

#if defined UG_RGB_MATRIX_WPMCYCLEBREATHING && defined WPM_ENABLE
void WpmCycleBreathing(void);                                               // WpmCycleBreathing effect for underglow rgb light
#endif

#if defined UG_RGB_MATRIX_WPMCYCLESPIRAL && defined WPM_ENABLE
void WpmCycleSpiral(void);                                                  // WpmCycleSpial effect for underglow rgb light
#endif

#if defined UG_RGB_MATRIX_WPMCYCLEINOUT && defined WPM_ENABLE
void WpmCycleInOut(void);                                                   // WpmCycleInOut effect for underglow rgb light
#endif
