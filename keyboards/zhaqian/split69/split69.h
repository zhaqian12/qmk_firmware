#ifndef SPLIT69_H
#define SPLIT69_H

#include "quantum.h"

#define KEYMAP( \
	L00, L01, L02, L03, L04, L05, L06, L07,    \
	L10, L11, L12, L13, L14, L15, L16,   	   \
	L20, L21, L22, L23, L24, L25, L26,    	   \
	L30, L31, L32, L33, L34, L35, L36,         \
	L40, L41, L42, L43,      L45,              \
	R00, R01, R02, R03, R04, R05,      R07,    \
	R10, R11, R12, R13, R14, R15, R16, R17,    \
	R20, R21, R22, R23, R24, R25,      R27,    \
	R30, R31, R32, R33, R34,      R36, R37,    \
	R40,      R42, R43,      R45, R46, R47, R48\
) { \
	{ L00,   L01,   L02,   L03,   L04,   L05,   L06,   L07,   KC_NO }, \
	{ L10,   L11,   L12,   L13,   L14,   L15,   L16,   KC_NO, KC_NO }, \
	{ L20,   L21,   L22,   L23,   L24,   L25,   L26,   KC_NO, KC_NO }, \
	{ L30,   L31,   L32,   L33,   L34,   L35,   L36,   KC_NO, KC_NO }, \
	{ L40,   L41,   L42,   L43,   KC_NO, L45,   KC_NO, KC_NO, KC_NO }, \
	{ R00,   R01,   R02,   R03,   R04,   R05,   KC_NO, R07,   KC_NO }, \
	{ R10,   R11,   R12,   R13,   R14,   R15,   R16,   R17,   KC_NO }, \
	{ R20,   R21,   R22,   R23,   R24,   R25,   KC_NO, R27,   KC_NO }, \
	{ R30,   R31,   R32,   R33,   R34,   KC_NO, R36,   R37,   KC_NO }, \
	{ R40,   KC_NO, R42,   R43,   KC_NO, R45,   R46,   R47,   R48   }  \
}

enum custom_keycodes {
    SATF = USER00,
    SATR,
	RGBVD,
	RGBVI,
	NEW_SAFE_RANGE
};

void satr(void);
void satf(void);

#endif