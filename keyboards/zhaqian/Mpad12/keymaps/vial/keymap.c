#include "Mpad12.h"
#include "joystick.h"
#include "analog.h"

enum layer_number {
    First = 0,
    Second,
    Third,
    Fourth,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT(
		KC_SPC, KC_SPC,
		KC_SPC, KC_SPC, KC_SPC, KC_SPC,
		KC_SPC, KC_SPC, KC_SPC, KC_SPC,
		KC_SPC, MO(1), KC_SPC, KC_SPC, KC_SPC),

	[1] = LAYOUT(
		KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET),

	[2] = LAYOUT(
		KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[3] = LAYOUT(
		KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	//keyevent_t event = record->event;
	switch (id) {
	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
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

// #ifdef ENCODER_ENABLE
// bool encoder_update_user(uint8_t index, bool clockwise) {
// 	if (index == 0) {
//         if (clockwise) {
// 			uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 0, 3);
// 			encoder_trigger(keycode);
//     	} else {
// 			uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 0, 4);
// 			encoder_trigger(keycode);
// 		}
//     } else if (index == 1) {
//         if (clockwise) {
// 			uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 1, 5);
// 			encoder_trigger(keycode);
//    	 	} else {
// 			uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 0, 5);
// 			encoder_trigger(keycode);
//     	}
//     }
// 	return true;
// }
// #endif

#ifdef JOYSTICK_ENABLE

static int actuation = 256;
bool arrows[4];
joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
    [0] = JOYSTICK_AXIS_VIRTUAL,
    [1] = JOYSTICK_AXIS_VIRTUAL 
};

#endif

void matrix_scan_user(void){

#ifdef JOYSTICK_ENABLE
    if (!arrows[0] && analogReadPin(D7) - 512 > actuation){
		arrows[0] = true;
		uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 0,0);
		register_code16(keycode);
    } else if (arrows[0] &&  analogReadPin(D7) - 512 < actuation){
    	arrows[0] = false;
        uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 0,0);
        unregister_code16(keycode);
    }
    if (!arrows[1] && analogReadPin(D7) - 512 < -actuation){
        arrows[1] = true;
        uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 3,5);
        register_code16(keycode);
    } else if (arrows[1] && analogReadPin(D7) - 512 > -actuation){
        arrows[1] = false;
        uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 3,5);
        unregister_code16(keycode);
    }
    if (!arrows[2] && analogReadPin(D6) - 512 > actuation){
    	arrows[2] = true;
        uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 1,0);
        register_code16(keycode);
    } else if (arrows[2] &&  analogReadPin(D6) - 512 < actuation){
        arrows[2] = false;
        uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 1,0);
        unregister_code16(keycode);
    }
    if (!arrows[3] && analogReadPin(D6) - 512 < -actuation){
        arrows[3] = true;
        uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 2,0);
        register_code16(keycode);
    } else if (arrows[3] && analogReadPin(D6) - 512 > -actuation){
        arrows[3] = false;
        int16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 2,0);
        unregister_code16(keycode);
	}
#endif

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}
