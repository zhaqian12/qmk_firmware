#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x00AA
#define PRODUCT_ID      0xAA06
#define DEVICE_VER      0x0001
#define MANUFACTURER    zhaiqian
#define PRODUCT         test12
#define DESCRIPTION     Keyboard

// enable the nkro when using the VIA.
#define FORCE_NKRO

// fix VIA RGB_light
#define VIA_HAS_BROKEN_KEYCODES

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 1

// #define DEBUG_MATRIX_SCAN_RATE

#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 4

#ifdef VIA_ENABLE
#define VIA_CUSTOM_KEYCODES_ENABLE
#define UG_RGB_MATRIX_ANIMATIONS
#define ALT_TAB_MARCO_ENABLE
#define UG_RGB_MATRIX_WPM_ANIMATIONS
#define ENCODER_TRIGGER_ENABLE
#endif

#ifdef VIAL_ENABLE
#define VIAL_KEYBOARD_UID {0x41, 0x57, 0x03, 0xA0, 0x6B, 0xC6, 0x1B, 0x12}
#ifdef VIAL_ENCODERS_ENABLE
#define VIAL_ENCODER_DEFAULT {KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU}
#define VIAL_ENCODER_KEYCODE_DELAY 10
#endif
#endif



#endif
