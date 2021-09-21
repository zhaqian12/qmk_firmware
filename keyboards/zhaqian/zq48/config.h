#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x00AA
#define PRODUCT_ID      0xAA07
#define DEVICE_VER      0x0001
#define MANUFACTURER    ZhaQian
#define PRODUCT         zq48
#define DESCRIPTION     Keyboard

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 14

/* key matrix pins */
#define MATRIX_ROW_PINS { F7, F6, D7, D6 }
#define MATRIX_COL_PINS { D0, D1, D2, D3, D5, B4, F5, F4, F1, F0, B0, B1, B2, B3 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 1

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define USB_POLLING_INTERVAL_MS 2
#define QMK_KEYS_PER_SCAN 4
#define FORCE_NKRO

#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN B7
#define RGBLED_NUM 58
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_DISABLE_WHEN_USB_SUSPENDED true
#define RGB_MATRIX_CENTER {110, 34}
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
#endif

#ifdef UNDERGLOW_RGB_MATRIX_ENABLE
#define UG_RGB_MATRIX_ANIMATIONS
#endif

#ifdef RGB_MATRIX_CUSTOM_KB
#define RGB_MATRIX_EFFECT_FRACTAL_RGB
#define RGB_MATRIX_EFFECT_CANDY_TAP
#define RGB_MATRIX_EFFECT_REACTIVE_MULTICROSS_RGB
#define RGB_MATRIX_EFFECT_REACTIVE_MULTINEXUS_RGB
#define RGB_MATRIX_EFFECT_REACTIVE_MULTIWIDE_RGB
#endif

#ifdef VIAL_ENABLE
#define VIAL_KEYBOARD_UID {0xDF, 0x3A, 0x05, 0x13, 0x08, 0xA4, 0x52, 0x65}
#endif
#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT
#define NO_ACTION_FUNCTION
#endif
