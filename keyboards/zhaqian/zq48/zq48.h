#ifndef ZQ48_H
#define ZQ48_H

#include "quantum.h"

#define LAYOUT( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110,       K112, K113, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209,       K211, K212, K213, \
	K300, K301,             K304,                   K308, K309,       K311, K312, K313  \
) { \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  K013 }, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  KC_NO, K112,  K113 }, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  KC_NO, K211,  K212,  K213 }, \
	{ K300,  K301,  KC_NO, KC_NO, K304,  KC_NO, KC_NO, KC_NO, K308,  K309,  KC_NO, K311,  K312,  K313 }  \
}

enum custom_keycodes {
#ifdef RGB_MATRIX_CONTROL_ENABLE
#ifdef VIA_ENABLE
	UGLRGBTog = USER00,		//rgb toggle for underglow rgb light
#else
    UGLRGBTog = SAFE_RANGE,
#endif
	KBLRGBTog,				//rgb toggle for key rgb backlight
#endif
#ifdef UNDERGLOW_RGB_MATRIX_ENABLE
    UGRGBMODF,           //logo rgblight and underglow rgblight mode+
    UGRGBMODR,           //logo rgblight and underglow rgblight mode-
#endif
};

#endif
