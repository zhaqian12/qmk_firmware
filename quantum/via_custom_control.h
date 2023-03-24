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

#if defined(MAGIC_SETTINGS_ENABLE)
#define VIA_CUSTOM_MAGIC_SETTINGS_ENABLE
#endif

enum via_custom_channel_id {
    id_custom_rgb_matrix_channel = 5,
    id_custom_rgb_indicators_channel = 6,
    id_custom_magic_setting_channel = 7,
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

enum via_custom_magic_setting_value {
    id_magic_nkro                           = 1,
    id_magic_no_gui                         = 2,
    id_magic_capslock_to_control            = 3,
    id_magic_swap_control_capslock          = 4,  
    id_magic_swap_escape_capslock           = 5,
    id_magic_swap_lalt_lgui                 = 6,
    id_magic_swap_ralt_rgui                 = 7,     
    id_magic_swap_lctl_lgui                 = 8,
    id_magic_swap_rctl_rgui                 = 9,
    id_magic_swap_grave_esc                 = 10,
    id_magic_swap_backslash_backspace       = 11, 
    id_magic_oneshot_enable                 = 12,
    id_magic_autocorrect_enable             = 13,
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

#if defined(VIA_CUSTOM_MAGIC_SETTINGS_ENABLE)
void via_custom_magic_setting_command(uint8_t *data, uint8_t length);
void via_custom_magic_setting_set_value(uint8_t *data);
void via_custom_magic_setting_get_value(uint8_t *data);
void via_custom_magic_setting_save(void);
#endif
