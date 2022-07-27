#include QMK_KEYBOARD_H
#include "jlk108.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT(
		KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_HOME, KC_PGUP, KC_END, KC_PGDN, 
		KC_TAB, KC_Q, KC_E, KC_R, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, KC_INS, KC_PAUS, 
		KC_CAPS, KC_A, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_Z, KC_X, KC_SPC, KC_C, KC_V, 
		KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_UP, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_P7, KC_P8, KC_P9, KC_PSLS, 
		KC_P4, KC_P5, KC_P6, KC_PAST, KC_P1, KC_P2, KC_P3, KC_P0, KC_PDOT, KC_PPLS, KC_NLCK, KC_ENT, KC_Q, KC_W, KC_W, KC_E, KC_R, 
		KC_F, KC_H, KC_J, KC_P, KC_G, KC_F, KC_H, KC_V, KC_C, KC_5, KC_8, KC_P, KC_P, KC_H, KC_U, KC_H, KC_A, 
		KC_T, KC_Q, KC_W, KC_Y, KC_Y, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J),

};

/* 编码器 */
bool encoder_update_user(uint8_t index, bool clockwise) {
		uint8_t  layer_now                 = biton32(layer_state);
		uint16_t encoder_cw_keycode        = keymap_key_to_keycode(layer_now,(keypos_t){.row = 6,.col = 11});
		uint16_t encoder_ccw_keycode       = keymap_key_to_keycode(layer_now,(keypos_t){.row = 6,.col = 13});
		uint16_t encoder_caw_keycode        = keymap_key_to_keycode(layer_now,(keypos_t){.row = 6,.col = 14});
		uint16_t encoder_cacw_keycode       = keymap_key_to_keycode(layer_now,(keypos_t){.row = 6,.col = 16});

    if (index == 0) { /* 编码器1 */
         if (clockwise) {
            tap_code(encoder_cw_keycode);
        } else {
            tap_code(encoder_ccw_keycode);
        }
    } else if (index == 1) { /* 编码器2 */
         if (clockwise) {
            tap_code(encoder_caw_keycode);
        } else {
            tap_code(encoder_cacw_keycode);
        }
    }
        return true;
}
