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


#include "encoder_trigger.h"


__attribute__((weak)) void encoder_trigger_kb(uint16_t keycode, keypos_t keylocation) {
#ifdef VIA_ENABLE
    if (keycode <= QK_MODS_MAX) {
        register_code16(keycode);
        wait_ms(10);
        unregister_code16(keycode);
    } else {
#else
    if (keycode == 1) {
#endif
        action_exec((keyevent_t){.key = keylocation, .pressed = 1, .time = (timer_read() | 1)});
        wait_ms(10);
        action_exec((keyevent_t){.key = keylocation, .pressed = 0, .time = (timer_read() | 1)});
    }
}



