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

#include "winry16cc.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		TO(1), KC_MPLY, KC_VOLD, KC_VOLU, LCTL(KC_C), LCTL(KC_V), KC_MPRV, KC_MNXT, LCTL(KC_X), LCTL(KC_F), LCTL(KC_F), M(0), M(1), M(3), KC_WHOM, M(2)),

	KEYMAP(
		TO(2), KC_PSLS, KC_PAST, KC_PMNS, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_P4, KC_P5, KC_P6, KC_PDOT, KC_P1, KC_P2, KC_P3, KC_P0),

	KEYMAP(
		TO(0), RGB_MOD, RGB_RMOD, RGB_TOG, RGB_VAD, RGB_VAI, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_T, RGB_M_X, RGB_M_G, RGB_SAI, RGB_SAD),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {


	switch (id) {
		case 0:
			if (record->event.pressed) {
				return MACRO( D(LGUI), D(LSFT), T(S), U(LSFT), U(LGUI), END );
			}
			break;
		case 1:
			if (record->event.pressed) {
				return MACRO( D(LCTL), D(LALT), T(W), U(LALT), U(LCTL), END );
			}
			break;
		case 2:
			if (record->event.pressed) {
				return MACRO( D(LCTL), D(LSFT), D(LALT), T(H), U(LALT), U(LSFT), U(LCTL), END );
			}
			break;
		case 3:
			if (record->event.pressed) {
				return MACRO( D(LCTL), D(LALT), T(Y), U(LALT), U(LCTL), END );
			}
			break;
	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
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
