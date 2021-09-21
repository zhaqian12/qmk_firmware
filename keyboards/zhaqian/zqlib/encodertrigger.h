#ifndef ENCODERTRIGGER_H
#define ENCODERTRIGGER_H

#include "quantum.h"

/*
 * if you want to use these functions,
 * please define ENCODER_TRIGGER_ENABLE in config.h,
 * then include this headfile in kb.c
 */

void encoder_trigger_kb(uint16_t keycode,  keypos_t keylocation);		//encoder trigger
#endif
