#include "split69.h"
#include <stdio.h>
char wpm_str[10];
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_MUTE, KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, 
		TO(1), KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
		SATF, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G,
		SATR, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, 
		RGBVD, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,

		KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, 
		KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, 
		KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, 
		KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, 
		KC_SPC, KC_RALT, MO(1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
		),

	KEYMAP(
		RGB_TOG, KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, 
		TO(2), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 

		KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, RESET, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
		),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_SLEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_WAKE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
		),


};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
	
}
void matrix_scan_user(void) {
	// if (host_keyboard_led_state().caps_lock) {
    //     rgblight_setrgb_at(255, 0, 0, 8);
    // } else if (biton32(layer_state) == 1){
	// 	rgblight_setrgb_at(0, 255, 0, 8);
	// } else if (biton32(layer_state) ==2 ){
	// 	rgblight_setrgb_at(0, 0, 255, 8);
	// } else {
    //     rgblight_setrgb_at(0, 0, 0, 8);
    // }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}


bool encoder_update_user(uint8_t index, bool clockwise) {
    // switch (biton32(layer_state)) {  
    //     case 1:
    //         clockwise ? rgblight_decrease_val() : rgblight_increase_val();
    //         break;
    // }
	// if (clockwise) {
	// 	uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 4,6);
	// 	if (keycode == USER00){
	// 		satf();
	// 	} else if (keycode == USER01) {
	// 		satr();
	// 	} else if (keycode == USER02) {
	// 		rgblight_decrease_val();
	// 	} else if (keycode == USER03) {
	// 		rgblight_increase_val();
	// 	} else {
	// 		register_code16(keycode);
	// 		wait_ms(10);
	// 	 	unregister_code16(keycode);
	// 	// 	//tap_code16(dynamic_keymap_get_keycode(biton32(layer_state), 4, 6));
	// 	}
    // } else {
	// 	uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 4,7);
	// 	if (keycode == USER00){
	// 		satf();
	// 	} else if (keycode == USER01) {
	// 		satr();
	// 	} else if (keycode == USER02) {
	// 		rgblight_decrease_val();
	// 	} else if (keycode == USER03) {
	// 		rgblight_increase_val();
	// 	} else {
	// 	 	register_code16(keycode);
	// 	 	wait_ms(10);
	// 	 	unregister_code16(keycode);
	// 	// 	//tap_code16(dynamic_keymap_get_keycode(biton32(layer_state), 4, 7));
	// 	}
    // }
	 return true;
}

