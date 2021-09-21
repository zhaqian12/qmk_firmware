#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x00AA
#define PRODUCT_ID      0xAA01
#define DEVICE_VER      0x0001
#define MANUFACTURER    ZHAQIAN
#define PRODUCT         ZQ75V2pro
#define DESCRIPTION     Keyboard

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 15

/* key matrix pins */
#define MATRIX_ROW_PINS { B4, B3, B2, A0, B7, D2 }
#define MATRIX_COL_PINS { F2, F3, F4, F5, F6, F7, A1, A2, D6, D5, D4, D3, F1, F0, B5 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

// #define FORCE_NKRO
#define USB_POLLING_INTERVAL_MS 2
#define QMK_KEYS_PER_SCAN 4
#define FORCE_NKRO

#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN C6
#define RGBLED_NUM 99
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_DISABLE_WHEN_USB_SUSPENDED true
#define RGB_MATRIX_CENTER {106, 32}
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
#endif

#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { B0 }
#define ENCODERS_PAD_B { B1 }
#define ENCODER_RESOLUTION  2
#endif

#ifdef VIA_ENABLE
#define DYNAMIC_KEYMAP_LAYER_COUNT 11
#endif

#ifdef UNDERGLOW_RGB_MATRIX_ENABLE
#define UG_RGB_MATRIX_ANIMATIONS
#define UG_RGB_MATRIX_WPM_ANIMATIONS
#endif

#ifdef TAP_DANCE_ENABLE
#define TAPPING_TERM 175
#endif

#ifdef OLED_DRIVER_ENABLE
#define OLED_DISPLAY_128X64
#define OLED_TIMEOUT 100000
#define OLED_FONT_HEIGHT 8
#define OLED_FONT_WIDTH 6
#define OLED_FONT_H "nfont.c"
#endif

#ifdef VIAL_ENABLE
#define VIAL_KEYBOARD_UID {0xA7, 0xDA, 0x16, 0xD5, 0x43, 0xF0, 0x6A, 0xDC}
#ifdef VIAL_ENCODERS_ENABLE
#define VIAL_ENCODER_DEFAULT {KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU}
#define VIAL_ENCODER_KEYCODE_DELAY 10
#endif
#endif

#ifdef OPENRGB_ENABLE
#define OPENRGB_DIRECT_MODE_USE_UNIVERSAL_BRIGHTNESS
#endif

#endif
