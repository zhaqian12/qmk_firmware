#include "kb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT(
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC),

	LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};


/* 编码器 */
bool encoder_update_user(uint8_t index, bool clockwise) {
		uint8_t  layer_now                 = biton32(layer_state);
		uint16_t encoder_cw_keycode        = keymap_key_to_keycode(layer_now,(keypos_t){.row = 2,.col = 4});
		uint16_t encoder_ccw_keycode       = keymap_key_to_keycode(layer_now,(keypos_t){.row = 2,.col = 5});
		uint16_t encoder_caw_keycode        = keymap_key_to_keycode(layer_now,(keypos_t){.row = 3,.col = 4});
		uint16_t encoder_cacw_keycode       = keymap_key_to_keycode(layer_now,(keypos_t){.row = 3,.col = 5});
		uint16_t encoder_cbw_keycode        = keymap_key_to_keycode(layer_now,(keypos_t){.row = 5,.col = 0});
		uint16_t encoder_cbcw_keycode       = keymap_key_to_keycode(layer_now,(keypos_t){.row = 5,.col = 1});
		uint16_t encoder_cdw_keycode        = keymap_key_to_keycode(layer_now,(keypos_t){.row = 5,.col = 2});
		uint16_t encoder_cdcw_keycode       = keymap_key_to_keycode(layer_now,(keypos_t){.row = 5,.col = 3});
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
    }else if (index == 2) { /* 编码器3 */
         if (clockwise) {
            tap_code(encoder_cbw_keycode);
        } else {
            tap_code(encoder_cbcw_keycode);
        }
    }else if (index == 3) { /* 编码器4 */
         if (clockwise) {
            tap_code(encoder_cdw_keycode);
        } else {
            tap_code(encoder_cdcw_keycode);
        }
    }
        return true;
}
