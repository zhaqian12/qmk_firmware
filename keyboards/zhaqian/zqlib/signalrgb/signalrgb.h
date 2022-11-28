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

#include <stdint.h>
#include "quantum.h"
#include "color.h"

#define SIGNALRGB_PROTOCOL_VERSION 0x01

enum signalrgb_command_id
{
    id_signalrgb_prefix                     = 0xAA,

    id_signalrgb_get_protocol_version       = 0x01,
    id_signalrgb_get_qmk_version            = 0x02,
    id_signalrgb_get_device_info            = 0x03,
    id_signalrgb_set_leds                   = 0x04,
    id_signalrgb_set_effect                 = 0x05,
    id_signalrgb_set_device                 = 0x06,
};

enum signalrgb_responses {
    DEVICE_ERROR_LEDS = 254,
};

enum set_device_id {
    id_backlight_set = 0,
    id_underglow_set = 1,
    id_logo_set = 2,
};

extern RGB signalrgb_colors[RGB_MATRIX_LED_COUNT];

void signal_rgb_command_handler(uint8_t *data, uint8_t length);
void signalrgb_get_protocol_version(uint8_t *data);
void signalrgb_get_qmk_version(uint8_t *data);
void signalrgb_get_device_info(uint8_t *data);
void signalrgb_set_leds(uint8_t *data);
void signalrgb_set_effect(uint8_t *data);
void signalrgb_set_device(uint8_t *data);