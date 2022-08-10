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

#if defined(RGB_MATRIX_CONTROL_ENABLE) || defined(UNDERGLOW_RGB_MATRIX_ENABLE)
#define VIA_CUSTOM_RGB_MATRIX_ENABLE
#endif

#if defined(DYNAMIC_RGB_INDICATORS_ENABLE)
#define VIA_CUSTOM_RGB_INDICATORS_ENABLE
#endif

enum via_custom_channel_id {
    id_custom_rgb_matrix_channel = 5,
    id_custom_rgb_indicators_channel = 6,
};

enum via_custom_rgb_matrix_value {
    id_rgb_matrix_toggle                    = 1,       // rgb matrix control
    id_underglow_rgb_matrix_brightness      = 2,       // underglow rgb matrix brightness
    id_underglow_rgb_matrix_effect          = 3,       // underglow rgb matrix effect
    id_underglow_rgb_matrix_effect_speed    = 4,       // underglow rgb matrix speed
    id_underglow_rgb_matrix_color           = 5,       // underglow rgb matrix color
};

enum via_custom_rgb_indicators_value {
    id_rgb_indicators_override              = 1,       // rgb indicator override
    // rgb indicator {num lock, caps lock, scroll lock}
    id_rgb_indicators_brightness            = 2,       // rgb indicator brightness
    id_rgb_indicators_effect                = 3,       // rgb indicator effect
    id_rgb_indicators_color                 = 4,       // rgb indicator color 
    id_rgb_indicators_led                   = 5,       // rgb indicator led
};

#if defined(VIA_CUSTOM_RGB_MATRIX_ENABLE)
void via_custom_rgb_matrix_command(uint8_t *data, uint8_t length);
void via_custom_rgb_matrix_set_value(uint8_t *data);
void via_custom_rgb_matrix_get_value(uint8_t *data);
void via_custom_rgb_matrix_save(void);
#endif

#if defined(VIA_CUSTOM_RGB_INDICATORS_ENABLE)
void via_custom_rgb_indicators_command(uint8_t *data, uint8_t length);
void via_custom_rgb_indicators_set_value(uint8_t *data);
void via_custom_rgb_indicators_get_value(uint8_t *data);
void via_custom_rgb_indicators_save(void);
#endif
