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

#include "via_custom_control.h"
#include "via.h"

void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *command_id = &(data[0]);
    uint8_t *channel_id = &(data[1]);
#if defined(VIA_CUSTOM_RGB_MATRIX_ENABLE)
    if (*channel_id == id_custom_rgb_matrix_channel) {
        via_custom_rgb_matrix_command(data, length);
        return;
    }
#endif
    *command_id = id_unhandled;
    *channel_id = *channel_id;  // force use of variable
}

#if defined(VIA_CUSTOM_RGB_MATRIX_ENABLE)
void via_custom_rgb_matrix_command(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *command_id        = &(data[0]);
    uint8_t *value_id_and_data = &(data[2]);

    switch (*command_id) {
        case id_custom_set_value: {
            via_custom_rgb_matrix_set_value(value_id_and_data);
            break;
        }
        case id_custom_get_value: {
            via_custom_rgb_matrix_get_value(value_id_and_data);
            break;
        }
        case id_custom_save: {
            via_custom_rgb_matrix_save();
            break;
        }
        default: {
            *command_id = id_unhandled;
            break;
        }
    }
}

void via_custom_rgb_matrix_set_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);
    switch (*value_id) {
#if defined(RGB_MATRIX_CONTROL_ENABLE)
        case id_rgb_matrix_toggle: {
            switch (*value_data) {
                case 0: {
                    if (value_data[1] == 0) {
                        rgb_matrix_disable();
                    } else {
                        rgb_matrix_enable();
                    }
                    break;
                } 
                case 1: {
                    if (value_data[1] == 0) {
                        key_rgb_disable(true);
                    } else {
                        key_rgb_enable(true);
                    }
                    break;
                }      
                case 2: {
                    if (value_data[1] == 0) {
                        underglow_rgb_disable(true);
                    } else {
                        underglow_rgb_enable(true);
                    }
                    break;
                } 
                case 3: {
                    if (value_data[1] == 0) {
                        logo_rgb_disable(true);
                    } else {
                        logo_rgb_enable(true);
                    }
                    break;
                } 
            }
            break;
        }
#endif
#if (defined(UNDERGLOW_RGB_MATRIX_ENABLE) && !defined(UNDERGLOW_RGB_MATRIX_API_DISABLE))
        case id_underglow_rgb_matrix_brightness: {
            underglow_rgb_matrix_set_hsv(underglow_rgb_matrix_get_hue(), underglow_rgb_matrix_get_sat(), value_data[0], false);
            break;
        }
        case id_underglow_rgb_matrix_effect: {
            underglow_rgb_enable(false);
            underglow_rgb_matrix_set_mode(value_data[0], false);
            break;
        }
        case id_underglow_rgb_matrix_effect_speed: {
            underglow_rgb_matrix_set_speed(value_data[0], false);
            break;
        }
        case id_underglow_rgb_matrix_color: {
            underglow_rgb_matrix_set_hsv(value_data[0], value_data[1], underglow_rgb_matrix_get_val(), false);
            break;
        }
#endif
    }
}

void via_custom_rgb_matrix_get_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);
    switch (*value_id) {
#if defined(RGB_MATRIX_CONTROL_ENABLE)
        case id_rgb_matrix_toggle: {
           switch (*value_data) {
                case 0: {
                    value_data[1] = rgb_matrix_is_enabled() ? 1 : 0;
                    break;
                } 
                case 1: {
                    value_data[1] = key_rgb_is_enabled() ? 1 : 0;
                    break;
                }      
                case 2: {
                    value_data[1] = underglow_rgb_is_enabled() ? 1 : 0;
                    break;
                } 
                case 3: {
                    value_data[1] = logo_rgb_is_enabled() ? 1 : 0;
                    break;
                } 
            }
            break;
        }
#endif
#if (defined(UNDERGLOW_RGB_MATRIX_ENABLE) && !defined(UNDERGLOW_RGB_MATRIX_API_DISABLE))
        case id_underglow_rgb_matrix_brightness: {
            value_data[0] = underglow_rgb_matrix_get_val();
            break;
        }
        case id_underglow_rgb_matrix_effect: {
            value_data[0] = underglow_rgb_matrix_get_mode();
            break;
        }
        case id_underglow_rgb_matrix_effect_speed: {
            value_data[0] = underglow_rgb_matrix_get_speed();
            break;
        }
        case id_underglow_rgb_matrix_color: {
            value_data[0] = underglow_rgb_matrix_get_hue();
            value_data[1] = underglow_rgb_matrix_get_sat();
            break;
        }
#endif
    }
}

void via_custom_rgb_matrix_save(void) {
#if defined(UNDERGLOW_RGB_MATRIX_ENABLE)
    eeconfig_update_underglow_rgb_matrix();
#endif
}

#endif