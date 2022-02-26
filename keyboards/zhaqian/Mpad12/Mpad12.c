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

#include "Mpad12.h"

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

#if defined ENCODER_ENABLE && defined ENCODER_TRIGGER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            encoder_trigger_kb(
#ifdef VIA_ENABLE
                dynamic_keymap_get_keycode(biton32(layer_state), 0, 3),
#else
                1,
#endif
                (keypos_t){.row = 0, .col = 3});
        } else {
            encoder_trigger_kb(
#ifdef VIA_ENABLE
                dynamic_keymap_get_keycode(biton32(layer_state), 0, 4),
#else
                1,
#endif
                (keypos_t){.row = 0, .col = 4});
        }
    } else if (index == 1) {
        if (clockwise) {
            encoder_trigger_kb(
#ifdef VIA_ENABLE
                dynamic_keymap_get_keycode(biton32(layer_state), 1, 5),
#else
                1,
#endif
                (keypos_t){.row = 1, .col = 5});
        } else {
            encoder_trigger_kb(
#ifdef VIA_ENABLE
                dynamic_keymap_get_keycode(biton32(layer_state), 0, 5),
#else
                1,
#endif
                (keypos_t){.row = 0, .col = 5});
        }
    return true;
}
#endif

#ifdef OLED_DRIVER_ENABLE

static const char PROGMEM oled_header[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0};

static const char PROGMEM oled_line_start[] = {0xc0, 0};

static const char PROGMEM oled_line_end[] = {0xd4, 0};

static const char PROGMEM oled_footer[] = {0xc4, 0xc5, 0xc5, 0xc9, 0xca, 0xca, 0xca, 0xca, 0xca, 0xca, 0xca, 0xca, 0xca, 0xca, 0xca, 0xca, 0xca, 0xcb, 0xc5, 0xc5, 0xc6, 0};


void render_layer_state(void) {
	 oled_write_P(PSTR(" LAYER:"),false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR(" BASE "), false);
            break;
        case 1:
            oled_write_P(PSTR(" 1ST  "), false);
            break;
        case 2:
            oled_write_P(PSTR(" 2ND  "), false);
            break;
		case 3:
			oled_write_P(PSTR(" 3RD  "), false);
            break;
        default:
            oled_write_P(PSTR(" UDEF "), false);
    }
}

void render_keyboard_status(uint8_t led_usb_state) {
	oled_write_P(PSTR(" "), false);
	oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("-NUML") : PSTR("-----"), false);
	oled_write_P(PSTR(" "), false);
	oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("-CAPS") : PSTR("-----"), false);
	oled_write_P(PSTR(" "), false);
	rgb_matrix_is_enabled() ? oled_write_P(PSTR("RGBON"), false) : oled_write_P(PSTR("-----"), false);
	oled_write_P(PSTR(" "), false);
}

void oled_task_user(void) {
	oled_write_P(oled_header, false);
	oled_write_P(oled_line_start, false);
    render_layer_state();
	oled_write_P(PSTR("      "),false);
    oled_write_P(oled_line_end, false);
	oled_write_P(oled_line_start, false);
    render_keyboard_status(host_keyboard_leds());
    oled_write_P(oled_line_end, false);
	oled_write_P(oled_footer, false);
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
#ifdef RGB_MATRIX_CONTROL_REV2_ENABLE
        case RGB_CTRL_SW:
            if (record->event.pressed) {
                rgb_matrix_control_sw();
            }
            return false;
#endif
    }
    return process_record_user(keycode, record);
};


