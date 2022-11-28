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

#include "version.h"
#include "signalrgb.h"

#ifndef SIGNALRGB_STARTUP_HSV
#    define SIGNALRGB_STARTUP_HSV { 0, 0, 200 }
#endif

#define SIGNALRGB_TRANS_NUMS ((RGB_MATRIX_LED_COUNT - 1) / 20 + 1)

RGB signalrgb_colors[RGB_MATRIX_LED_COUNT] = {[0 ... RGB_MATRIX_LED_COUNT - 1] = SIGNALRGB_STARTUP_HSV};

void signal_rgb_command_handler(uint8_t *data, uint8_t length) {
    uint8_t *command_id   = &(data[1]);
    uint8_t *command_data = &(data[2]);

    switch (*command_id) {
        case id_signalrgb_get_protocol_version: {
            signalrgb_get_protocol_version(command_data);
            break;
        }
        case id_signalrgb_get_qmk_version: {
            signalrgb_get_qmk_version(command_data);
            break;
        }
        case id_signalrgb_get_device_info: {
            signalrgb_get_device_info(command_data);
            break;
        }
        case id_signalrgb_set_leds: {
            signalrgb_set_leds(command_data);
            break;
        }
        case id_signalrgb_set_effect: {
            signalrgb_set_effect(command_data);
            break;
        }
        case id_signalrgb_set_device: {
            signalrgb_set_device(command_data);
            break;
        }
        default: {
            // data[0] = id_unhandled;
            break;
        }
    }
}

void signalrgb_get_protocol_version(uint8_t *data) {
    data[0] = SIGNALRGB_PROTOCOL_VERSION;
}

void signalrgb_get_qmk_version(uint8_t *data) {
    uint8_t i = 0;
    for (i = 0; ((i < 62) && (QMK_VERSION[i] != 0)); i++) {
        data[i + 1] = QMK_VERSION[i];
    }
    data[0] = i;
}

void signalrgb_get_device_info(uint8_t *data) {
    data[0] = RGB_MATRIX_LED_COUNT;
    data[1] = SIGNALRGB_TRANS_NUMS;
}

void signalrgb_set_leds(uint8_t *data) {
    uint8_t first_led_index = data[0];
    uint8_t leds_num        = data[1];

    if (leds_num > 20) {
        data[0] = DEVICE_ERROR_LEDS;
        return;
    }
    uint8_t led_index   = first_led_index;
    uint8_t color_index = 2;
    for (uint8_t i = 0; i < leds_num; ++i, ++led_index, color_index += 3) {
        signalrgb_colors[led_index].r = data[color_index];
        signalrgb_colors[led_index].g = data[color_index + 1];
        signalrgb_colors[led_index].b = data[color_index + 2];
    }
}

void signalrgb_set_effect(uint8_t *data) {
    uint8_t enabled = data[0];
    if (enabled) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SIGNALRGB);
    } else {
        rgb_matrix_reload_from_eeprom();
    }
}

void signalrgb_set_device(uint8_t *data) {
    switch (*data) {
#ifdef RGB_MATRIX_CONTROL_ENABLE
        case id_backlight_set: {
            uint8_t enabled = data[1];
            if (enabled) {
                key_rgb_enable(true);
            } else {
                key_rgb_disable(true);
            }
            break;
        }
        case id_underglow_set: {
            uint8_t enabled = data[1];
            if (enabled) {
                underglow_rgb_enable(true);
            } else {
                underglow_rgb_disable(true);
            }
            break;
        }
        case id_logo_set: {
            uint8_t enabled = data[1];
            if (enabled) {
                logo_rgb_enable(true);
            } else {
                logo_rgb_disable(true);
            }
            break;
        }
#endif
        default: {
            break;
        }
    }

}