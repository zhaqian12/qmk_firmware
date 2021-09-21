#ifndef MPAD12_H
#define MPAD12_H

#include "quantum.h"

#define LAYOUT( \
	     K01, K02,           \
	     K11, K12, K13, K14, \
	     K21, K22, K23, K24, \
	K30, K31, K32, K33, K34  \
) { \
	{ KC_NO, K01,   K02,   KC_NO, KC_NO }, \
	{ KC_NO, K11,   K12,   K13,   K14 }, \
	{ KC_NO, K21,   K22,   K23,   K24 }, \
	{ K30,   K31,   K32,   K33,   K34 }  \
}

#ifdef VIA_ENABLE
#define VIA_CUSTOM_KEYCODES
#endif

#ifdef VIA_CUSTOM_KEYCODES
//custom keycodes
enum custom_keycodes {
    ATR = USER00,			//alt_shift_tab
    ATF,					//alt_tab
	BRGBTog,					
	URGBTog,
	NEW_SAFE_RANGE
};

void alt_tab_reverse(void);					//alt_shift_tab
void alt_tab_forward(void);					//alt_tab
void BRGBToggle(void);
void URGBToggle(void);
// #ifdef ENCODER_ENABLE
// void encoder_trigger(uint16_t keycode);		//use custom keycodes on encoder
// #endif

#endif

#endif