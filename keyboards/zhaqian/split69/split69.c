#include "split69.h"

#ifdef RGB_MATRIX_ENABLE

  // Logical Layout
  // Columns
  // Left
  // 0  1  2  3  4  5
  //                   ROWS
  // 25 24 19 18 11 10   0
  //    03    02    01
  // 26 23 20 17 12 09   1
  //    04    05    06
  // 27 22 21 16 13 08   2
  //
  //          15 14 07   3
  //
  // Right
  // 0  1  2  3  4  5
  //                    ROWS
  // 25 24 19 18 11 10   4
  //    03    02    01
  // 26 23 20 17 12 09   5
  //    04    05    06
  // 27 22 21 16 13 08   6
  //
  //          15 14 07   7
  //
  // Physical Layout
  // Columns
  // 0  1  2  3  4  5  6  7  8  9  10 11 12 13
  //                                           ROWS
  // 25 24 19 18 11 10       10 11 18 19 24 25  0
  //    03    02    01       01    02    03
  // 26 23 20 17 12 09       09 12 17 20 23 26  1
  //    04                               04
  // 27 22 21 16 13 08       08 13 16 21 22 27  2
  //          05    06       06    05
  //           15 14 07     07 14 15              3

led_config_t g_led_config = { {
    
}, {
    {  85,  16 }, {  50,  13 }, {  16,  20 }, {  16,  38 }, {  50,  48 }, {  85,  52 }, {  95,  63 },
    {  85,  39 }, {  85,  21 }, {  85,   4 }, {  68,   2 }, {  68,  19 }, {  68,  37 }, {  80,  58 },
    {  60,  55 }, {  50,  35 }, {  50,  13 }, {  50,   0 }, {  33,   3 }, {  33,  20 }, {  33,  37 },
    {  16,  42 }, {  16,  24 }, {  16,   7 }, {   0,   7 }, {   0,  24 }, {   0,  41 }, { 139,  16 },
    { 174,  13 }, { 208,  20 }, { 208,  38 }, { 174,  48 }, { 139,  52 }, { 129,  63 }, { 139,  39 },
    { 139,  21 }, { 139,   4 }, { 156,   2 }, { 156,  19 }, { 156,  37 }, { 144,  58 }, { 164,  55 },
    { 174,  35 }, { 174,  13 }, { 174,   0 }, { 191,   3 }, { 191,  20 }, { 191,  37 }, { 208,  42 },
    { 208,  24 }, { 208,   7 }, { 224,   7 }, { 224,  24 }, { 224,  41 }
}, {
    2, 2, 2, 2, 2, 2, 1,
    4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 1, 1, 1, 2,
    2, 2, 2, 2, 2, 1, 4,
    4, 4, 4, 4, 4, 1, 1,
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 1, 1, 1
} };

void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}
#endif

bool is_alt_tab_active = false; 
uint16_t alt_tab_timer = 0; 

void matrix_scan_kb(void) {
	if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1000) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false; 
        }
    }
    // if (host_keyboard_led_state().caps_lock) {
    //     rgblight_setrgb_at(255, 0, 0,8);
    // } else if (biton32(layer_state) == 1){
	// 	rgblight_setrgb_at(0, 255, 0,8);
	// } else if (biton32(layer_state) ==2 ){
	// 	rgblight_setrgb_at(0, 0, 255,8);
	// } else {
    //     rgblight_setrgb_at(0, 0, 0, 8);
    // }
    return matrix_scan_user();
}


void satr(void){
    if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code(KC_LALT);
    }
    alt_tab_timer = timer_read();
    tap_code16(S(KC_TAB));

}
void satf(void){
	if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code(KC_LALT);
    }
    alt_tab_timer = timer_read();
    tap_code16(KC_TAB);
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case SATF:
            if (record->event.pressed) {
				 satf();
            }
            return false;
        case SATR:
            if (record->event.pressed) {
                satr();
            }
            return false;
        case RGBVD:
            if (record->event.pressed) {
                rgblight_decrease_val();
            }
            return false;
		case RGBVI:
			if (record->event.pressed) {
                rgblight_increase_val();
            }
            return false;
    }
    return process_record_user(keycode, record);
};

void encoder_trigger(uint16_t keycode) {
    if (keycode == USER00){
			satf();
		} else if (keycode == USER01) {
			satr();
		} else if (keycode == USER02) {
			rgblight_decrease_val();
		} else if (keycode == USER03) {
			rgblight_increase_val();
		} else {
			register_code16(keycode);
			wait_ms(10);
		 	unregister_code16(keycode);
		}
}

bool encoder_update_kb(uint8_t index, bool clockwise) {
	if (clockwise) {
		uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 4,6);
		encoder_trigger(keycode);
    } else {
		uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 4,7);
		encoder_trigger(keycode);
    }
    return true;
}