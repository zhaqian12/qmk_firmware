#include "mpad12.h"
#include "joystick.h"
#include "analog.h"
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, RESET),

	KEYMAP(
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),


};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	//keyevent_t event = record->event;

	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
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

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { 
		switch (biton32(layer_state)) {
			case 1:
				if (clockwise) {
					register_code(KC_PGDN);
					wait_ms(10);
					unregister_code(KC_PGDN);
           	 	} else {
					register_code(KC_PGUP);
					wait_ms(10);
					unregister_code(KC_PGUP);
				}
            	break;
			case 2:
				clockwise ? rgblight_decrease_val() : rgblight_increase_val();
				break;
			default:
				if (get_mods() & MOD_BIT(KC_LCTRL)) {
					clockwise ? tap_code(KC_KP_MINUS) : tap_code(KC_KP_PLUS);
				} else {
					if (clockwise) {
						if (!is_alt_tab_active) {
							is_alt_tab_active = true;
							register_code(KC_LALT);
						}
						alt_tab_timer = timer_read();
						tap_code16(S(KC_TAB));
					} else {
						if (!is_alt_tab_active) {
							is_alt_tab_active = true;
							register_code(KC_LALT);
						}
						alt_tab_timer = timer_read();
						tap_code16(KC_TAB);
					}
				}
				break;
				
		}
    } else if (index == 1) { 
		switch (biton32(layer_state)) {
			case 1:
				if (clockwise) {
					register_code(KC_UP);
					wait_ms(10);
					unregister_code(KC_UP);
				} else {
					register_code(KC_DOWN);
					wait_ms(10);
					unregister_code(KC_DOWN);
				}
				break;
			case 2:
				if (clockwise) {
                register_code(KC_BRID);
                wait_ms(10);
                unregister_code(KC_BRID);
				} else {
					register_code(KC_BRIU);
					wait_ms(10);
					unregister_code(KC_BRIU);
				}
			break;
			default:
				if (clockwise) {
					register_code(KC_VOLD);
					wait_ms(10);
					unregister_code(KC_VOLD);
				} else {
					register_code(KC_VOLU);
					wait_ms(10);
					unregister_code(KC_VOLU);
				}
				break;
		}
    }
	// if (index == 0) {
    //     if (clockwise) {
    //         tap_code16(dynamic_keymap_get_keycode(biton32(layer_state),0,3));
    //     } else {
    //         tap_code16(dynamic_keymap_get_keycode(biton32(layer_state),0,4 ));
    //     }
    // } else if (index == 1) {
    //     if (clockwise) {
    //         tap_code16(dynamic_keymap_get_keycode(biton32(layer_state),0,5));
    //     } else {
    //         tap_code16(dynamic_keymap_get_keycode(biton32(layer_state),1,5));
    //     }
    // }
}

char arrow_keys[4] = {KC_UP, KC_LEFT, KC_DOWN, KC_RIGHT};
static int actuation = 256;
bool arrows[4];

void matrix_scan_user(void){
	if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1000) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
    if (!arrows[0] && analogReadPin(D6) - 512 > actuation){
		arrows[0] = true;
		register_code16(KC_UP);
		// uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 0,0);
		// register_code16(keycode);
    } else if (arrows[0] &&  analogReadPin(D6) - 512 < actuation){
    	arrows[0] = false;
        unregister_code16(KC_UP);
        // uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 0,0);
        // unregister_code16(keycode);
    }
    if (!arrows[1] && analogReadPin(D6) - 512 < -actuation){
        arrows[1] = true;
        register_code16(KC_DOWN);
        // uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 3,5);
        // register_code16(keycode);
    } else if (arrows[1] && analogReadPin(D6) - 512 > -actuation){
        arrows[1] = false;
        unregister_code16(KC_DOWN);
        // uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 3,5);
        // unregister_code16(keycode);
    }
    if (!arrows[2] && analogReadPin(D7) - 512 > actuation){
    	arrows[2] = true;
        // uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 1,0);
        // register_code16(keycode);
        register_code16(KC_LEFT);
    } else if (arrows[2] &&  analogReadPin(D7) - 512 < actuation){
        arrows[2] = false;
        // uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 1,0);
        // unregister_code16(keycode);
        unregister_code16(KC_LEFT);
    }
    if (!arrows[3] && analogReadPin(D7) - 512 < -actuation){
        arrows[3] = true;
        register_code16(KC_RIGHT);
        // uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 2,0);
        // register_code16(keycode);
    } else if (arrows[3] && analogReadPin(D7) - 512 > -actuation){
        arrows[3] = false;
        // int16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 2,0);
        // unregister_code16(keycode);
		unregister_code16(KC_RIGHT);
	}
}

joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
    [0] = JOYSTICK_AXIS_VIRTUAL,
    [1] = JOYSTICK_AXIS_VIRTUAL
};