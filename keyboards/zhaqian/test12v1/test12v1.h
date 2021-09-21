#ifndef TEST12_H
#define TEST12_H

#include "quantum.h"

#define LAYOUT( \
	K00, K01, K02, K03, K04, \
	K10, K11, K12, K13, K14, \
	K20, K21, K22, K23, K24  \
) { \
	{ K00,   K01,   K02,   K03,   K04 }, \
	{ K10,   K11,   K12,   K13,   K14 }, \
	{ K20,   K21,   K22,   K23,   K24 }  \
}

#ifdef VIA_CUSTOM_KEYCODES_ENABLE
//custom keycodes
enum custom_keycodes {
#ifdef ALT_TAB_MARCO_ENABLE
    ATR = USER00,			//alt_shift_tab
    ATF,					//alt_tab
#endif
#ifdef RGB_MATRIX_CONTROL_ENABLE
	UGLRGBTog,				//rgb toggle for underglow rgb light
	KBLRGBTog,				//rgb toggle for key rgb backlight
#endif
#ifdef UNDERGLOW_RGB_MATRIX_ENABLE
	UGLFIXEDRGBMODF,		//underglow light fixed and only changes rgb effects of backlight
    UGLFIXEDRGBMODR,
#endif
};

#endif
#endif
