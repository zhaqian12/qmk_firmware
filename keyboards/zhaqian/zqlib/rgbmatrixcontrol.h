#ifndef RGBMATRIXCONTROL_H
#define RGBMATRIXCONTROL_H

#include "quantum.h"

/*
 * if you want to use these functions,
 * please define RGB_MATRIX_INDIPENDENT_CONTROL_ENABLE in config.h,
 * then include this headfile in kb.c
 */

#ifndef VIA_CUSTOM_EEPROM_MAGIC_ADDR
#define VIA_CUSTOM_EEPROM_MAGIC_ADDR (VIA_EEPROM_LAYOUT_OPTIONS_ADDR + VIA_EEPROM_LAYOUT_OPTIONS_SIZE)
#endif

#ifndef VIA_EEPROM_CUSTOM_CONFIG_SIZE
#define VIA_EEPROM_CUSTOM_CONFIG_SIZE 5
#endif


#ifdef RGB_MATRIX_INDIPENDENT_CONTROL_ENABLE
void RGBMatrixControlInit(void);                            // init rgb control information from eeprom
void UGLRGBToggle(void);                                    // rgb toggle for underglow rgb light
void KBLRGBToggle(void);                                    // rgb toggle for key rgb backlight
#ifdef LOGO_RGB_MATRIX_CONTROL_ENABLE
void LogoRGBToggle(void);
#endif
void RGBMatrixSet(void);                                    // rgb matrix effect setting function
#endif


#endif
