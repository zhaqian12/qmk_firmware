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
led_config_t g_led_config = {
    {
        {3,2,1,0},
        {7,6,5,4},
        {11,10,9,8},
    },{
        {224,16},{149,16},{74,16},{0,16},
        {224,32},{149,32},{74,32},{0,32},
        {224,48},{149,48},{74,48},{0,48},
        {0,64},{112,64},{224,64},
        {224,0},{112,0},{0,0},
    },{
        4,4,4,4,
        4,4,4,4,
        4,4,4,4,
        2,2,2,
        2,2,2,
    }
};


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

#ifdef VIA_CUSTOM_KEYCODES
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
bool flag = false;
bool flag1 = false;
void matrix_scan_kb(void) {
	if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1000) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
    return matrix_scan_user();
}

void alt_tab_reverse(void) {
    if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code(KC_LALT);
    }
    alt_tab_timer = timer_read();
    tap_code16(S(KC_TAB));

}

void alt_tab_forward(void) {
	if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code(KC_LALT);
    }
    alt_tab_timer = timer_read();
    tap_code16(KC_TAB);
}

void BRGBToggle(void){
    if (flag1){
        flag1 = false;
    } else {
        flag1 = true;
    }
}

void URGBToggle(void){
    if (flag){
        flag = false;
    } else {
        flag = true;
    }
}

void rgb_matrix_indicators_kb(void) {
    for (int i = 0; i < 12; i++) {
        if (flag)
             rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
        else
            rgb_matrix_enable();
    }
    for (int i = 12; i < 18; i++) {
        if (flag1)
             rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
        else
            rgb_matrix_enable();
    }
}

#ifdef ENCODER_ENABLE
void encoder_trigger(uint16_t keycode) {
    if (keycode >= MACRO00 && keycode <= MACRO15) {
        dynamic_keymap_macro_send(keycode - MACRO00);
    } else {
        switch (keycode) {
                case USER00:
                    alt_tab_reverse();
                    break;
                case USER01:
                    alt_tab_reverse();
                    break;
                case USER02:
                    rgblight_decrease_val();
                    break;
                case USER03:
                    rgblight_increase_val();
                    break;
                default:
                    register_code16(keycode);
                    wait_ms(10);
                    unregister_code16(keycode);
                    break;
            }
    }
}
#endif

#endif



bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    
#ifdef VIA_CUSTOM_KEYCODES
    switch(keycode) {
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
        case BRGBTog:
            if (record->event.pressed) {
                BRGBToggle();
            }
            return false;
        case URGBTog:
            if (record->event.pressed) {
                URGBToggle();
            }
            return false;
    }
#endif
    return process_record_user(keycode, record);
};

