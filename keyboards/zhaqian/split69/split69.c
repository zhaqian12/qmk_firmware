/* Copyright 2021 ZhaQian
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

#include "split69.h"

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
#ifdef ALT_TAB_MARCO_ENABLE
        case ATR:
            if (record->event.pressed) {
                alt_tab_reverse();
            }
            return false;
        case ATF:
            if (record->event.pressed) {
                alt_tab_forward();
            }
            return false;
#endif
    }
    return process_record_user(keycode, record);
};

#if defined ENCODER_ENABLE && defined ENCODER_TRIGGER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (clockwise) {
        encoder_trigger_kb(
#ifdef VIA_ENABLE
            dynamic_keymap_get_keycode(biton32(layer_state), 4, 6),
#else
            1,
#endif
            (keypos_t){.row = 4, .col = 6});
    } else {
        encoder_trigger_kb(
#ifdef VIA_ENABLE
            dynamic_keymap_get_keycode(biton32(layer_state), 4, 7),
#else
            1,
#endif
            (keypos_t){.row = 4, .col = 7});
    }
    return true;
}
#endif
