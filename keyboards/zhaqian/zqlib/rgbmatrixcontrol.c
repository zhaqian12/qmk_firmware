#include "rgbmatrixcontrol.h"

#ifdef RGB_MATRIX_INDIPENDENT_CONTROL_ENABLE

bool is_underglow_rgblight_active = true;
bool is_key_backlight_active = true;
#ifdef LOGO_RGB_MATRIX_CONTROL_ENABLE
bool is_logo_rgblight_active = true;
#endif

void RGBMatrixControlInit(void) {
    is_underglow_rgblight_active = eeprom_read_byte((void*)VIA_CUSTOM_EEPROM_MAGIC_ADDR + 1);
    is_key_backlight_active = eeprom_read_byte((void*)VIA_CUSTOM_EEPROM_MAGIC_ADDR + 2);
#ifdef LOGO_RGB_MATRIX_CONTROL_ENABLE
    is_logo_rgblight_active = eeprom_read_byte((void*)VIA_CUSTOM_EEPROM_MAGIC_ADDR + 3);
#endif
}

void UGLRGBToggle(void) {
    if (is_underglow_rgblight_active) {
        is_underglow_rgblight_active = false;
    } else {
        is_underglow_rgblight_active = true;
    }
    eeprom_write_byte((void*)VIA_CUSTOM_EEPROM_MAGIC_ADDR + 1, is_underglow_rgblight_active);
}

void KBLRGBToggle(void) {
    if (is_key_backlight_active) {
        is_key_backlight_active = false;
    } else {
        is_key_backlight_active = true;
    }
    eeprom_write_byte((void*)VIA_CUSTOM_EEPROM_MAGIC_ADDR + 2, is_key_backlight_active);
}

#ifdef LOGO_RGB_MATRIX_CONTROL_ENABLE
void LogoRGBToggle(void) {
    if (is_logo_rgblight_active) {
        is_logo_rgblight_active = false;
    } else {
        is_logo_rgblight_active = true;
    }
    eeprom_write_byte((void*)VIA_CUSTOM_EEPROM_MAGIC_ADDR + 3, is_logo_rgblight_active);
}
#endif

void RGBMatrixSet(void) {
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i ++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            if (is_underglow_rgblight_active)
                rgb_matrix_enable();
            else
                rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
#ifdef LOGO_RGB_MATRIX_CONTROL_ENABLE
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_INDICATOR)) {
            if (is_logo_rgblight_active)
                rgb_matrix_enable();
            else
                rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
#endif
        } else {
            if (is_key_backlight_active)
                rgb_matrix_enable();
            else
                rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
        }
    }
}

#endif
