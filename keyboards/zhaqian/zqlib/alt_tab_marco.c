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

#include "alt_tab_marco.h"

static uint8_t is_alt_tab_active = 0;
static uint16_t alt_tab_timer = 0;

void matrix_scan_kb(void) {
	if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1000) {
            unregister_code16(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}

void alt_tab_forward(void) {
	if (is_alt_tab_active == 0) {
        is_alt_tab_active ^= 1;
        register_code16(KC_LALT);
    }
    alt_tab_timer = timer_read();
    tap_code16(KC_TAB);
}

void alt_tab_reverse(void) {
    if (is_alt_tab_active == 0) {
        is_alt_tab_active ^= 1;
        register_code16(KC_LALT);
    }
    alt_tab_timer = timer_read();
    tap_code16(S(KC_TAB));
}

