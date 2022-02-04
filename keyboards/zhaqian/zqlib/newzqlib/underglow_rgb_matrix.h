/* Copyright 2022 zhaqian
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
#include "color.h"

typedef struct {
    uint8_t mode;
    HSV hsv;
    uint8_t speed;
} underglow_rgb_matrix_config_t;

#define EECONFIG_UNDERGLOW_RGB_MATRIX (uint8_t *)16

void underglow_rgb_matrix_init(void);
void underglow_rgb_matrix_task(void);
void underglow_rgb_mode_sync(void);
void underglow_rgb_mode_step(void);
void underglow_rgb_mode_step_reverse(void);

#ifndef UNDERGLOW_RGB_MATRIX_API_DISABLE
uint8_t underglow_rgb_matrix_get_mode(void);
HSV undeglow_rgb_matrix_get_hsv(void);
uint8_t underglow_rgb_matrix_get_speed(void);
void underglow_rgb_matrix_set_mode(uint8_t mode);
void underglow_rgb_matrix_set_hsv(uint8_t hue, uint8_t sat, uint8_t val);
void underglow_rgb_matrix_set_hue(uint8_t hue);
void underglow_rgb_matrix_set_sat(uint8_t sat);
void underglow_rgb_matrix_set_val(uint8_t val);
void underglow_rgb_matrix_set_speed(uint8_t speed);
void underglow_rgb_matrix_increase_hue(void);
void underglow_rgb_matrix_decrease_hue(void);
void underglow_rgb_matrix_increase_sat(void);
void underglow_rgb_matrix_decrease_sat(void);
void underglow_rgb_matrix_increase_val(void);
void underglow_rgb_matrix_decrease_val(void);
void underglow_rgb_matrix_increase_speed(void);
void underglow_rgb_matrix_decrease_speed(void);
#endif

bool process_underglow_rgb_matrix(const uint16_t keycode, const keyrecord_t *record);

#define UG_RGB_MATRIX_SYNC

#ifdef UG_RGB_MATRIX_ANIMATIONS
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

#if defined UG_RGB_MATRIX_WPM_ANIMATIONS && defined WPM_ENABLE
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
