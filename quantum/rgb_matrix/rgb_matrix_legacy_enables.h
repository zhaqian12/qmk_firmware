/* Copyright 2021 QMK
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

#ifdef RGB_MATRIX_ANIMATION
#    define ENABLE_RGB_MATRIX_ALPHAS_MODS
#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_BAND_SAT
#    define ENABLE_RGB_MATRIX_BAND_VAL
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    define ENABLE_RGB_MATRIX_CYCLE_ALL
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#    define ENABLE_RGB_MATRIX_DUAL_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    define ENABLE_RGB_MATRIX_RAINDROPS
#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    define ENABLE_RGB_MATRIX_HUE_BREATHING
#    define ENABLE_RGB_MATRIX_HUE_PENDULUM
#    define ENABLE_RGB_MATRIX_HUE_WAVE
#    define ENABLE_RGB_MATRIX_PIXEL_RAIN
#    define ENABLE_RGB_MATRIX_PIXEL_FLOW
#    define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#endif

#ifdef RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    define ENABLE_RGB_MATRIX_SPLASH
#    define ENABLE_RGB_MATRIX_MULTISPLASH
#    define ENABLE_RGB_MATRIX_SOLID_SPLASH
#    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

#ifdef RGB_MATRIX_CUSTOM_ANIMATION
#    define ENABLE_RGB_MATRIX_CANDY_TAP
#    define ENABLE_RGB_MATRIX_CYCLE_BAND_PINWHEEL_SAT
#    define ENABLE_RGB_MATRIX_CYCLE_BAND_PINWHEEL_VAL
#    define ENABLE_RGB_MATRIX_CYCLE_BAND_SPIRAL_SAT
#    define ENABLE_RGB_MATRIX_CYCLE_BAND_SPIRAL_VAL
#    define ENABLE_RGB_MATRIX_CYCLE_BANDVAL
#    define ENABLE_RGB_MATRIX_CYCLE_BREATHING
#    define ENABLE_RGB_MATRIX_CYCLE_DOWN_UP
#    define ENABLE_RGB_MATRIX_CYCLE_IN_OUT_DUAL
#    define ENABLE_RGB_MATRIX_CYCLE_IN_OUT
#    define ENABLE_RGB_MATRIX_CYCLE_MULTISPLASH
#    define ENABLE_RGB_MATRIX_CYCLE_REACTIVE_MULTICROSS
#    define ENABLE_RGB_MATRIX_CYCLE_REACTIVE_MULTINEXUS
#    define ENABLE_RGB_MATRIX_CYCLE_REACTIVE_MULTIWIDE
#    define ENABLE_RGB_MATRIX_CYCLE_RIGHT_LEFT
#    define ENABLE_RGB_MATRIX_FRACTAL_RGB
#    define ENABLE_RGB_MATRIX_KITT_RGB
#    define ENABLE_RGB_MATRIX_REACTIVE_MULTICROSS_RGB
#    define ENABLE_RGB_MATRIX_REACTIVE_MULTINEXUS_RGB
#    define ENABLE_RGB_MATRIX_REACTIVE_MULTIWIDE_RGB
#    define ENABLE_RGB_MATRIX_CYCLE_SIN_WAVE
#    define ENABLE_RGB_MATRIX_RAINBOW_SIN_WAVE
#    define ENABLE_RGB_MATRIX_RAINBOW_SIN_WAVE_REVERSE
#    define ENABLE_RGB_MATRIX_CYCLE_ALTER
#    define ENABLE_RGB_MATRIX_RAINBOW_ALTER
#    define ENABLE_RGB_MATRIX_STATIC_BREATHING_CIRCLE
#    define ENABLE_RGB_MATRIX_CYCLE_BREATHING_CIRCLE
#    define ENABLE_RGB_MATRIX_BLOOM
#    define ENABLE_RGB_MATRIX_COMMET
#    define ENABLE_RGB_MATRIX_ROTATE_RAINBOW
#    define ENABLE_RGB_MATRIX_MOTION_POINT
#    define ENABLE_RGB_MATRIX_ROTATE_BEAM_PENDULUM
#    define ENABLE_RGB_MATRIX_ROTATE_BEAM_WIPERS
#    define ENABLE_RGB_MATRIX_H_STACK
#    define ENABLE_RGB_MATRIX_V_STACK
#    define ENABLE_RGB_MATRIX_SWAP
#    define ENABLE_RGB_MATRIX_STATIC_ZIGZAG
#    define ENABLE_RGB_MATRIX_RAINBOW_ZIGZAG
#endif

#ifdef RGB_INDICATORS_ENABLE
#    define RGB_MATRIX_INDICATORS_TASK(rgb_effect_params)       \
        do {                                                    \
            rgb_indicators_task();                              \
            rgb_matrix_indicators();                            \
            rgb_matrix_indicators_advanced(&rgb_effect_params); \
        } while (0)
#else
#    define RGB_MATRIX_INDICATORS_TASK(rgb_effect_params)                          \
        do {                                                                       \
            if (rgb_effect_params.iter == RGB_MATRIX_LED_PROCESS_MAX_ITERATIONS) { \
                rgb_matrix_indicators();                                           \
            }                                                                      \
            rgb_matrix_indicators_advanced(&rgb_effect_params);                    \
        } while (0)
#endif
