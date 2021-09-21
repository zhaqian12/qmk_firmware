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

#include "zq11800.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
    {
        {18, NO_LED, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, NO_LED, 6},
        {NO_LED, NO_LED,29, 28, 27, 26, 25, 24, 23, 22, 21, 20, NO_LED, NO_LED, 19},
        {44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30},
        {59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45},
        {73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, NO_LED, 60},
        {86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, NO_LED, 75, 74, NO_LED},
        {97, 96, 95, 94, NO_LED, 93, NO_LED, 92, 91, 90, NO_LED, 89, 88, 87},
    }, {
        {0, 0}, {45, 0}, {90, 0}, {134, 0}, {178, 0}, {222, 0},
        {215, 0}, {172, 0}, {155, 0}, {141, 0}, {127, 0}, {113, 0}, {96, 0}, {83, 0}, {69, 0}, {55, 0}, {41, 0}, {28, 0}, {0, 0},
        {215, 9}, {155, 9}, {141, 9}, {127, 9}, {113, 9}, {96, 9}, {83, 9}, {69, 9}, {55, 9}, {41, 9}, {28, 9},
        {215, 17}, {186, 26}, {165, 26}, {152, 26}, {138, 26}, {124, 26}, {110, 26}, {96, 26}, {83, 26}, {69, 26}, {55, 26}, {41, 26}, {28, 26}, {14, 26}, {0, 26},
        {215, 26}, {190, 35}, {172, 35}, {159, 35}, {145, 35}, {131, 35}, {117, 35}, {103, 35}, {90, 35}, {76, 35}, {62, 35}, {48, 35}, {34, 35}, {21, 35}, {3, 35},
        {215, 35}, {184, 44}, {162, 44}, {148, 44}, {134, 44}, {121, 44}, {107, 44}, {93, 44}, {79, 44}, {65, 44}, {52, 44}, {38, 44}, {24, 44}, {5, 44},
        {198, 57}, {176, 53}, {155, 53}, {141, 53}, {128, 53}, {114, 53}, {100, 53}, {86, 53}, {72, 53}, {59, 53}, {45, 53}, {31, 53}, {9, 53},
        {210, 64}, {196, 64}, {183, 64}, {164, 60}, {146, 60}, {129, 60}, {102, 60}, {64, 60}, {36, 60}, {19, 60}, {2, 60},

    }, {
        8, 8, 8, 8, 8, 8,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    }};
#endif

#ifdef RGB_DISABLE_WHEN_USB_SUSPENDED
void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}
#endif

void rgb_matrix_indicators_kb(void) {
// COLOR RED RGB VALUE
    HSV hsv = {0, 255, rgb_matrix_get_val()};
    RGB rgb = hsv_to_rgb(hsv);
// caps_lock indicator
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = 0; i < 6; i++) {
            rgb_matrix_set_color(56, rgb.r, rgb.g, rgb.b);
        }
    }
}

#if defined ENCODER_ENABLE && defined ENCODER_TRIGGER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (clockwise) {
		encoder_trigger_kb(
#ifdef VIA_ENABLE
            dynamic_keymap_get_keycode(biton32(layer_state), 1, 13),
#else
            1,
#endif
            (keypos_t){.row = 1, .col = 13});
    } else {
		encoder_trigger_kb(
#ifdef VIA_ENABLE
            dynamic_keymap_get_keycode(biton32(layer_state), 1, 12),
#else
            1,
#endif
            (keypos_t){.row = 1, .col = 12});
	}
	return true;
}
#endif

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


