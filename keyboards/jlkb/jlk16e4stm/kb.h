
#pragma once
#include "quantum.h"

#define LAYOUT( \
	     K01, K02, K03, K04, K05, K06, \
	K10,      K12, K13, K14, K15, K16, \
	K20, K21,      K23, K24, K25, K26, \
	K30, K31, K32,      K34, K35, K36, \
	K40, K41, K42, K43,      K45, K46, \
	K50, K51, K52, K53, K54,      K56, \
	K60, K61, K62, K63, K64, K65  \
) { \
	{ KC_NO, K01,   K02,   K03,   K04,   K05,   K06 }, \
	{ K10,   KC_NO, K12,   K13,   K14,   K15,   K16 }, \
	{ K20,   K21,   KC_NO, K23,   K24,   K25,   K26 }, \
	{ K30,   K31,   K32,   KC_NO, K34,   K35,   K36 }, \
	{ K40,   K41,   K42,   K43,   KC_NO, K45,   K46 }, \
	{ K50,   K51,   K52,   K53,   K54,   KC_NO, K56 }, \
	{ K60,   K61,   K62,   K63,   K64,   K65,   KC_NO }  \
}
