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

#include "mpad12.h"
#include "joystick.h"
#include "analog.h"

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

#ifdef JOYSTICK_ENABLE
char arrow_keys[4] = {KC_UP, KC_LEFT, KC_DOWN, KC_RIGHT};
static int actuation = 256;
bool arrows[4];
joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
    [0] = JOYSTICK_AXIS_VIRTUAL,
    [1] = JOYSTICK_AXIS_VIRTUAL
};
#endif

void matrix_scan_user(void){
#ifdef JOYSTICK_ENABLE
    if (!arrows[0] && analogReadPin(D6) - 512 > actuation) {
		arrows[0] = true;
		register_code16(KC_UP);
    } else if (arrows[0] &&  analogReadPin(D6) - 512 < actuation) {
    	arrows[0] = false;
        unregister_code16(KC_UP);
    }
    if (!arrows[1] && analogReadPin(D6) - 512 < -actuation) {
        arrows[1] = true;
        register_code16(KC_DOWN);
    } else if (arrows[1] && analogReadPin(D6) - 512 > -actuation) {
        arrows[1] = false;
        unregister_code16(KC_DOWN);
    }
    if (!arrows[2] && analogReadPin(D7) - 512 > actuation) {
    	arrows[2] = true;
        register_code16(KC_LEFT);
    } else if (arrows[2] &&  analogReadPin(D7) - 512 < actuation) {
        arrows[2] = false;
        unregister_code16(KC_LEFT);
    }
    if (!arrows[3] && analogReadPin(D7) - 512 < -actuation) {
        arrows[3] = true;
        register_code16(KC_RIGHT);
    } else if (arrows[3] && analogReadPin(D7) - 512 > -actuation) {
        arrows[3] = false;
		unregister_code16(KC_RIGHT);
	}
#endif
}
