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

#include "split69.h"

enum {
	MAIN = 0,
	FN,
	PLAY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = KEYMAP(
		KC_MUTE, KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,
		TO(1), KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
	    ATF, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G,
		ATR, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,
		KC_SPC, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,

		KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
		KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
		KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
		KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,
		KC_SPC, KC_RALT, MO(1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
		),

	[1] = KEYMAP(
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

	[2] = KEYMAP(
		KC_MSTP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
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

#ifdef OLED_DRIVER_ENABLE

static uint32_t oled_timer                       = 0;
bool            master_oled_cleared = false;  // OLED CLEAR 标记
#define OLED_SHOW_STATE_TIMEOUT 10000         // 无操作10秒后激活OLED动画

// static const char PROGMEM skeeb_logo[] = {
//     0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
//     0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
//     0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
// 	0x95,0x96,0x97,0x98,0x99,0x9a,0x9b,0xb5,0xb6,0xb7,0xb8,0xb9,0xba,0xbb,0xd5,0xd6,0xd7,0xd8,0xd9,0xda,0xdb,0};

    static const char PROGMEM oled_header[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
	0xc0,0};

	static const char PROGMEM oled_layer_keylog_separator[] = {
    0xc8,0xff,0};

	static const char PROGMEM oled_layer_line_end[] = {
    0xd4,0};

	static const char PROGMEM oled_layer_keylog_bottom[] = {
    0xc1,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc3,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc2,0};

	static const char PROGMEM oled_line_start[] = {
    0xc0,0};

	static const char PROGMEM oled_mods_bottom[] = {
    0xc1,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc2,0};

	static const char PROGMEM oled_footer[] = {
    0xc4,0xc5,0xc5,0xc9,0xca,0xca,0xca,0xca,0xca,0xca,0xca,0xca,0xca,0xca,0xca,0xca,0xca,0xcb,0xc5,0xc5,0xc6,0};


// static void render_kyria_logo(void) {
//     static const char PROGMEM kyria_logo[] = {
//         // 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         // 0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         // 0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,126, 31,  7,  3,  1,  0,  0,  0,  0,  0,  0,128,128,192,192,224,224,224,224,224,224,192,192,128,  0,  0,192,192,192,192,192,128,  0,  0,  0,  1,  3,  7, 31,126,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         // 0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  0,  0,  0,  0,  0,  0,  0,240,252,254,255,255,255,127, 31, 15, 15, 15, 15, 15, 15, 31, 63, 15,128,248,255,255,255,255,255,  7,  0,  0,  0,  0,  0,  0,  0,  0,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,  0, 60,126,231,195,195,199,142, 12,  0,  0,255,255,131,131,131,199,254,124,  0,  0,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  3,255,255,  3,  3,  3,  0,  0,  3,  3,  3,255,255,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,
//         // 0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,  0,  0,  0,  0,  0,  0,  0, 15, 63,255,255,255,255,252,240,224,224,224,224,224,224,240,248,254,255,255,255,127, 63, 15,193,240,254,  0,  0,  0,  0,  0,  0,  0,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,  0, 12, 28, 56, 48, 48, 57, 31, 15,  0,  0, 63, 63,  1,  1,  1,  1,  0,  0,  0,  0, 63, 63, 48, 48, 48, 48, 48, 48,  0,  0, 48, 48, 48, 63, 63, 48, 48, 48,  0,  0,  0,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         // 0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,126,248,224,192,128,  0,  0,  0,  0,  0,  1,  3,  3,  7,  7, 15, 15, 15, 15, 15, 15,  7,  7,  3,  3,  9,  8, 12, 14, 15, 15, 15, 15,  0,  0,128,192,224,248,126, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         // 0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         // 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,127, 65, 65, 99, 62,  0,127, 73, 73, 73,  0, 79, 73, 73,121,  0, 65,127, 65,  0,127, 65, 65,113,  0,127,  6, 24,127,  0,127, 73, 73, 73,  0,127, 65, 65, 99, 62,  0,113, 89, 77, 71,  0,127, 65, 97,127, 64,  0,  0,
// 		0,  0, 60, 60,240,240,192,192,  0,  0,  0,  0,240,240,240,  0,  0,  0,252,252,252,252,  0,  0,  0,  0,240,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,192,252,252, 28,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,252,252,252,252,  0,  0,  0,  0,  0,  0,  0,  0,252,252,252,252,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,224,224, 96, 96, 96, 96, 96, 96, 96, 96,224,224, 96, 96, 96, 96,120,120,120,120,120, 96,
//         12, 12,204,204, 15, 15,207,207,252,252,140,140,143,143,143,140,140,140,143,143,143,143,140,140,140,140,159,159,128,128,128,  0,  0,  0,  0,  0,240,240, 60, 60, 15, 15,  3,  3,  3,  3,  3,  3,255,255,255,255,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,240,240,255,255,255,255, 60, 60,243,243,  7,  7,  7,  7,255,255,255,255,  7,  7,  7,  7,  7,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,252,252,255,255,  0,  0,  0,  0,  0,  0,  0,  0,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,127,255, 60, 56,249,255, 15, 15,  3,243,243,243, 51, 51, 51,243,255, 63, 51, 51,243,243, 51, 51, 51,243,243,243,  3,  3,  0,  0, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,255,255,255,255, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  0,  0,  0,  0, 15, 15,  3,  3,255,255,255,255, 12, 12, 12, 12, 12, 12, 12, 12,255,255, 63, 63,252,252, 12, 12, 12, 15, 15, 15, 12, 12, 12, 12,  0,  0,  0,  0, 15, 15, 15, 15,195,195,243,243,195,195,  3,  3,255,255,  3,  3, 51, 51,243,243,195,195,  3,  3,
//         60, 60, 12, 12, 15, 15, 15, 15,  3,  3,  3,255,255,255,  0,  0,  0,255,255,  0,  0,  0,255,255,  0,  0,  0,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,  0,  0,192,192,240,240, 63, 63,  3,  3,  0,  0,  3,  3, 63, 63,240,240,192,192,192,192,192,192,  0,  0, 48, 48, 60, 60, 15, 15,  3,195,192,192,192,192,192,192,255,255,  0,  0,  0,  0,  0,  0, 15, 15,127,126,
//     };
//     oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
// }

#    define KEYLOGGER_LENGTH 8
static char keylog_str[KEYLOGGER_LENGTH + 1] = {0};

static const char PROGMEM code_to_name[0xFF] = {
//   0    1    2    3    4    5    6    7    8    9    A    B    c    D    E    F
    182, ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',  // 0x
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2',  // 1x
    '3', '4', '5', '6', '7', '8', '9', '0',  20,  19,  17,  29,  22, '-', '=', '[',  // 2x
    ']','\\', '#', ';','\'', '`', ',', '.', '/', 188, 149, 150, 151, 152, 153, 154,  // 3x
    155, 156, 157, 158, 159, 181, 191, 190, ' ', ' ', 185, 183,  16, 186, 184,  26,  // 4x
     27,  25,  24, 189, '/', '*', '-', '+', ' ', '1', '2', '3', '4', '5', '6', '7',  // 5x
    '8', '9', '0', '.', ' ', 187, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 6x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 7x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 8x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 9x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 214, 215, 216, 217, 218, 219, 220, 221,  // Ax
    ' ', ' ', 213, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Bx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Cx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Dx
    'C', 'S', 'A', 'W', ' ', 'S', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ex
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '        // Fx
};

void add_keylog(uint16_t keycode);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        oled_timer = timer_read32();
        add_keylog(keycode);
    }
    return true;
}

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) || (keycode >= QK_MODS && keycode <= QK_MODS_MAX)) {
        keycode = keycode & 0xFF;
    } else if (keycode > 0xFF) {
        keycode = 0;
    }

    for (uint8_t i = (KEYLOGGER_LENGTH - 1); i > 0; --i) {
        keylog_str[i] = keylog_str[i - 1];
    }

    if (keycode < (sizeof(code_to_name) / sizeof(char))) {
        keylog_str[0] = pgm_read_byte(&code_to_name[keycode]);
    }
}

void render_keylogger_status(void) {
    oled_write(keylog_str, false);
}

void render_mod_status(uint8_t modifiers) {
	oled_write_P(PSTR(" "), false);
	oled_write_P(PSTR("-"), false);
    oled_write_P(PSTR("SHF"), (modifiers & MOD_MASK_SHIFT));
	oled_write_P(PSTR("-"), false);
    oled_write_P(PSTR("CTR"), (modifiers & MOD_MASK_CTRL));
	oled_write_P(PSTR("-"), false);
	oled_write_P(PSTR("WIN"), (modifiers & MOD_MASK_GUI));
	oled_write_P(PSTR("-"), false);
    oled_write_P(PSTR("ALT"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("-"), false);
	oled_write_P(PSTR(" "), false);
}

void render_layer_state(void){
	switch (get_highest_layer(layer_state)) {
		case 0: oled_write_P(PSTR(" MAIN   "), false); break;
		case 1: oled_write_P(PSTR(" MEDIA  "), false); break;
		case 2: oled_write_P(PSTR(" FUNC   "), false); break;
		default: oled_write_P(PSTR("Undefined"), false);
	}
}

void render_keylock_status(uint8_t led_usb_state) {
	oled_write_P(PSTR(" "), false);
	oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("-NUML") : PSTR("-----"), false);
	oled_write_P(PSTR(" "), false);
	oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("-CAPS") : PSTR("-----"), false);
	oled_write_P(PSTR(" "), false);
	oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("-SCRL") : PSTR("-----"), false);
	oled_write_P(PSTR(" "), false);
}

void oled_task_user(void) {
     if (timer_elapsed32(oled_timer) > OLED_SHOW_STATE_TIMEOUT) {
        if (!master_oled_cleared) {
            oled_clear();
            master_oled_cleared = true;
        }
        return;
    } else {
        if (master_oled_cleared) {
            oled_on();
            oled_clear();
            master_oled_cleared = false;
        }
        oled_write_P(oled_header, false);
	    render_layer_state();
	    oled_write_P(oled_layer_keylog_separator, false);
        render_keylogger_status();
	    oled_set_cursor(20, 2);
	    oled_write_P(oled_layer_line_end, false);
	    oled_write_P(oled_layer_keylog_bottom, false);
	    oled_write_P(oled_line_start, false);
	    render_keylock_status(host_keyboard_leds());
	    oled_write_P(oled_layer_line_end, false);
	    oled_write_P(oled_mods_bottom, false);
	    oled_write_P(oled_line_start, false);
	    render_mod_status(get_mods() | get_oneshot_mods());
	    oled_write_P(oled_layer_line_end, false);
	    oled_write_P(oled_footer, false);
    }
}
#endif


