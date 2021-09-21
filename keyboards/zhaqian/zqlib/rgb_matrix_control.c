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

#include "rgb_matrix_control.h"

// internal variables
static uint8_t is_underglow_rgblight_active = 1;
static uint8_t is_key_backlight_active = 1;
#ifdef LOGO_RGB_MATRIX_CONTROL_ENABLE
static uint8_t is_logo_rgblight_active = 1;
#endif

// rgb matrix status initialized by reading from eeprom
void rgb_matrix_control_init(void) {
    is_underglow_rgblight_active = eeprom_read_byte((void*)ZQ_EEPROM_ADDR + 1);
    is_key_backlight_active = eeprom_read_byte((void*)ZQ_EEPROM_ADDR + 2);
#ifdef LOGO_RGB_MATRIX_CONTROL_ENABLE
    is_logo_rgblight_active = eeprom_read_byte((void*)ZQ_EEPROM_ADDR + 3);
#endif
}

// underglow rgb matrix toggle
void underglow_rgb_toggle(void) {
    is_underglow_rgblight_active ^= 1;
    eeprom_write_byte((void*)ZQ_EEPROM_ADDR + 1, is_underglow_rgblight_active);
}

// backlight rgb matrix toggle
void key_backlight_rgb_toggle(void) {
    is_key_backlight_active ^= 1;
    eeprom_write_byte((void*)ZQ_EEPROM_ADDR + 2, is_key_backlight_active);
}

#ifdef LOGO_RGB_MATRIX_CONTROL_ENABLE
// logo rgb matrix toggle
void logo_rgb_toggle(void) {
    is_logo_rgblight_active ^= 1;
    eeprom_write_byte((void*)ZQ_EEPROM_ADDR + 3, is_logo_rgblight_active);
}
#endif

// rgb matrix controllers handling
void rgb_matrix_indicators_rgbmatrixcontrol(void) {
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i ++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            if (is_underglow_rgblight_active)
                rgb_matrix_enable();
            else
                rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
#ifdef LOGO_RGB_MATRIX_CONTROL_ENABLE
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_INDICATOR)) {
            if (is_logo_rgblight_active)
                rgb_matrix_enable();
            else
                rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
#endif
        } else {
            if (is_key_backlight_active)
                rgb_matrix_enable();
            else
                rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
        }
    }
}

