#ifndef ALTTABMARCO_H
#define ALTTABMARCO_H

#include "quantum.h"

/*
 * if you want to use these functions,
 * please define ALT_TAB_MARCO_ENABLE in config.h,
 * then include this headfile in kb.c
 */

void alt_tab_reverse(void);					//alt_shift_tab
void alt_tab_forward(void);					//alt_tab

#endif
