#pragma once
#include "quantum.h"

#define LAYOUT( \
	     K01, K02, K03, K04, K05, K06, K07, K08, \
	K10,      K12, K13, K14, K15, K16, K17, K18, \
	K20, K21,      K23, K24, K25, K26, K27, K28, \
	K30, K31, K32,      K34, K35, K36, K37, K38, \
	K40, K41, K42, K43,      K45, K46, K47, K48, \
	K50, K51, K52, K53, K54,      K56, K57, K58, \
	K60, K61, K62, K63, K64, K65,      K67, K68, \
	K70, K71, K72, K73, K74, K75, K76,      K78, \
	K80, K81, K82, K83, K84, K85, K86, K87  \
) { \
	{ KC_NO, K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08 }, \
	{ K10,   KC_NO, K12,   K13,   K14,   K15,   K16,   K17,   K18 }, \
	{ K20,   K21,   KC_NO, K23,   K24,   K25,   K26,   K27,   K28 }, \
	{ K30,   K31,   K32,   KC_NO, K34,   K35,   K36,   K37,   K38 }, \
	{ K40,   K41,   K42,   K43,   KC_NO, K45,   K46,   K47,   K48 }, \
	{ K50,   K51,   K52,   K53,   K54,   KC_NO, K56,   K57,   K58 }, \
	{ K60,   K61,   K62,   K63,   K64,   K65,   KC_NO, K67,   K68 }, \
	{ K70,   K71,   K72,   K73,   K74,   K75,   K76,   KC_NO, K78 }, \
	{ K80,   K81,   K82,   K83,   K84,   K85,   K86,   K87,   KC_NO }  \
}

