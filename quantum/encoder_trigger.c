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

#include "encoder_trigger.h"

// define the key position for encoder pad a
// ex: {col, row} or {col1, row1}, {col2, row2}
#ifndef ENCODER_PAD_A_KEY_POS
#define ENCODER_PAD_A_KEY_POS {1, 0}
#endif

// define the key position for encoder pad b
#ifndef ENCODER_PAD_B_KEY_POS
#define ENCODER_PAD_B_KEY_POS {0, 0}
#endif

static keypos_t encoder_pad_a_key_pos[] = {ENCODER_PAD_A_KEY_POS};
static keypos_t encoder_pad_b_key_pos[] = {ENCODER_PAD_B_KEY_POS};

void encoder_trigger(uint8_t index, bool clockwise) {
    keypos_t current_key_pos;
    if (clockwise) {
        current_key_pos = encoder_pad_a_key_pos[index];
    } else {
        current_key_pos = encoder_pad_b_key_pos[index];
    }
    action_exec((keyevent_t){.key = current_key_pos, .pressed = 1, .time = (timer_read() | 1)});
    wait_ms(10);
    action_exec((keyevent_t){.key = current_key_pos, .pressed = 0, .time = (timer_read() | 1)});
}
