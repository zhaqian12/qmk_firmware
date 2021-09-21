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

// #ifdef ENCODER_ENABLE
// void encoder_trigger(uint16_t keycode) {
//     if (keycode >= MACRO00 && keycode <= MACRO15) {
//         dynamic_keymap_macro_send(keycode - MACRO00);
//     } else {
//         switch (keycode) {
//                 case USER00:
//                     alt_tab_reverse();
//                     break;
//                 case USER01:
//                     alt_tab_reverse();
//                     break;
//                 case USER02:
//                     rgblight_decrease_val();
//                     break;
//                 case USER03:
//                     rgblight_increase_val();
//                     break;
//                 default:
//                     register_code16(keycode);
//                     wait_ms(10);
//                     unregister_code16(keycode);
//                     break;
//             }
//     }
// }
// #endif

#endif

#ifdef OLED_DRIVER_ENABLE

// static uint32_t oled_timer = 0;
// bool oled_has_cleared = false;
// #define OLED_SHOW_STATE_TIMEOUT 20000     

// static void render_mpad12logo(void) {
//     static const char PROGMEM raw_logo[] = {
//         0,  0,  0,192,  0,  0,  0, 32, 16,176,224,224,192,224,144,144,192,240,160,144,224, 32, 64, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         8, 16, 48,176,185,251, 30,199,243,249,253,252,254,254,254,254,254,252,253,249,243,198, 30,252,231,193, 65,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,254,254,126,240,128,  0,  0,  0,  0,  0,  0,128,240,126,254,254,  0,  0,  0,254,254,  6,  6,  6,  6,  6,  6,140,252,112,  0,  0,  0,  0,128,240,124, 15, 15,124,240,128,  0,  0,  0,  0,  0,255,255,  3,  3,  3,  7,  6, 14, 28,248,240,  0,  0,  0, 24, 24, 12, 14,255,255,  0,  0,  0,  0,  0,  0,  0,131,131,131,131,131,131,131,131,255,255,  0,  0, 
//         4,  2, 99, 35,103,223,240,199,159, 63,127,127,255,255,255,255,255,127,127, 63,159,199,240, 31, 13, 24, 32, 32,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,  0,  1,  7, 30,120,224,224,120, 30,  7,  1,  0,255,255,  0,  0,  0,255,255,  3,  3,  3,  3,  3,  3,  1,  1,  0,  0,  0,224,252, 31,  7,  6,  6,  6,  6,  7, 31,252,224,  0,  0,  0,255,255,192,192,192,224, 96,112, 56, 31, 15,  0,  0,  0,192,192,192,192,255,255,192,192,192,192,  0,  0,  0,255,255,193,193,193,193,193,193,193,193,  0,  0, 
//         0,  0,  0,  0,  0,  4,  4,  8, 15,  7,  3, 18, 18, 10, 14,  6,  6,  2,  3, 19, 23, 12,  1,  3,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//     };
//     oled_write_raw_P(raw_logo, sizeof(raw_logo));
// }
// static void render_qmklogo(void) {
//     static const char PROGMEM raw_logo[] = {
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,240,128,240,128,128,240,128,128,240,128,240,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,148,148,148,255,255,255,255,  3,255,255,255,  3,255,255,255,  3,255,255,255,255,148,148,148,  0,  0,  0,  0,  0,240,248, 12, 12, 12,248,240,  0,252,252,120,224,128,224,120,252,252,  0,252,252,224,240,184, 28, 12,  0,  0,  0,  0,  0,252,252,204,204,204,  0,236,236,  0,240,224, 48, 48,  0,240,224, 48, 48,224,224, 48, 48,240,224,  0,240,224,  0,192, 96,192,  0,224,240,  0, 32,176,144,144,240,224,  0,240,224, 48, 48,  0,224,240,144,144,240, 96,  0,  0,  0,  0,  0,  0,  0, 
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 20, 20, 20,127,255,255,255,254,253,251,251,192,251,251,253,254,255,255,255,127, 20, 20, 20,  0,  0,  0,  0,  0,  1,  3,  6,  6, 14, 27, 17,  0,  7,  7,  0,  1,  3,  1,  0,  7,  7,  0,  7,  7,  0,  1,  3,  7,  6,  0,  0,  0,  0,  0,  7,  7,  0,  0,  0,  0,  7,  7,  0,  7,  7,  0,  0,  0,  7,  7,  0,  0,  7,  7,  0,  0,  7,  7,  0,  0,  3,  7,  3,  0,  3,  7,  3,  0,  0,  3,  7,  4,  4,  3,  7,  0,  7,  7,  0,  0,  0,  1,  3,  6,  6,  6,  2,  0,  0,  0,  0,  0,  0,  0, 
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  0,  7,  0,  0,  7,  0,  0,  7,  0,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//     };
//     oled_write_raw_P(raw_logo, sizeof(raw_logo));
// }

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
	// if (timer_elapsed32(oled_timer) > OLED_SHOW_STATE_TIMEOUT) {
    //     if (!oled_has_cleared) {
    //         oled_clear();
    //         oled_has_cleared = true;
    //     }
	// 	// if (oled_timer % 10 >= 5) {
	// 	// 	render_mpad12logo();
	// 	// // } else {
	// 	// // 	render_qmklogo();
	// 	// // }
	// 	// oled_scroll_left();
    //     return;
    // } else {
        // if (oled_has_cleared) {
        //     oled_on();
        //     oled_clear();
        //     oled_has_cleared = false;
        // } 
	    oled_write_P(oled_header, false);
		oled_write_P(oled_line_start, false);
        render_layer_state();
		oled_write_P(PSTR("      "),false);
        oled_write_P(oled_line_end, false);
		oled_write_P(oled_line_start, false);
        render_keyboard_status(host_keyboard_leds());
        oled_write_P(oled_line_end, false);
		oled_write_P(oled_footer, false);
	// }
}
#endif


bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
//     if (record->event.pressed) {
// #ifdef OLED_DRIVER_ENABLE
//         // oled_timer = timer_read32();
// 		// oled_scroll_off();
// #endif
//     }
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


