/* Copyright 2021 JasonRen(biu)
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
#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {  //
    {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
    },{
        {0, 0}, {74, 0}, {148, 0}, {222, 0},
        {0, 32}, {74, 32}, {148, 32}, {222, 32},
        {0, 64}, {74, 64}, {148, 64}, {222, 64},
        {0, 64}, {224, 64}, {0, 0}, {224, 0},

    },{
        4, 4, 4, 4,
        4, 4, 4, 4,
        4, 4, 4, 4,
        2, 2, 2, 2,
    }};

void rgb_matrix_indicators_kb(void) {
// caps_lock indicator
    if (host_keyboard_led_state().caps_lock) {
        HSV hsv = {0, 255, rgb_matrix_get_val()};
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(5, rgb.r, rgb.g, rgb.b);
    }
}

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

#ifdef ENCODER_TRIGGER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (clockwise) {
		encoder_trigger_kb(
#ifdef VIA_ENABLE
            dynamic_keymap_get_keycode(biton32(layer_state), 1, 4),
#else
            1,
#endif
            (keypos_t){.row = 1, .col = 4});
    } else {
		encoder_trigger_kb(
#ifdef VIA_ENABLE
            dynamic_keymap_get_keycode(biton32(layer_state), 2, 4),
#else
            1,
#endif
            (keypos_t){.row = 2, .col = 4});
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
#if defined RGB_MATRIX_CONTROL_ENABLE && !defined RGB_MATRIX_CONTROL_REV2_ENABLE
        case UGLRGBTog:
            if (record->event.pressed) {
                underglow_rgb_toggle();
            }
            return false;
        case KBLRGBTog:
            if (record->event.pressed) {
                key_backlight_rgb_toggle();
            }
            return false;
#endif
#ifdef UNDERGLOW_RGB_MATRIX_ENABLE
        case UGLFIXEDRGBMODF:
            if (record->event.pressed) {
               underglow_rgb_mode_step();
            }
            return false;
        case UGLFIXEDRGBMODR:
            if (record->event.pressed) {
               underglow_rgb_mode_step_reverse();
            }
            return false;
#endif
    }
    return process_record_user(keycode, record);
};




