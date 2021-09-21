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

#include "rgb_matrix_control_rev2.h"
#include "eeprom.h"

// internal variables
static uint8_t rgb_matrix_control_index = 0;

// rgb matrix status initialized by reading from eeprom
void rgb_matrix_control_init(void) {
    rgb_matrix_control_index = eeprom_read_byte(EECONFIG_RGBCONTROL) % 3;
}

void rgb_matrix_control_sw(void) {
    rgb_matrix_control_index += 1;
    rgb_matrix_control_index %= 3;
    eeprom_update_byte(EECONFIG_RGBCONTROL, rgb_matrix_control_index);
}

// rgb matrix controllers handling
void rgb_matrix_indicators_rgbmatrixcontrol(void) {
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i ++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            if (rgb_matrix_control_index == 2)
                rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
        } else {
            if (rgb_matrix_control_index == 1)
                rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
        }
    }
}

bool process_rgbcontrol(const uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        case RGB_CT_SW:
            if (record->event.pressed) {
                rgb_matrix_control_sw();
            }
            return false;
    }
    return true;
}


