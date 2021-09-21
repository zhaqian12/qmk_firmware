#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x00AA
#define PRODUCT_ID      0xAA04
#define DEVICE_VER      0x0001
#define MANUFACTURER    zhaqian
#define PRODUCT         zq60
#define DESCRIPTION     Keyboard

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 14

/* key matrix pins */
#define MATRIX_ROW_PINS { F5, F4, F1, D6, D4 }
#define MATRIX_COL_PINS { D7, B4, B5, C6, B6, C7, F0, B3, B7, D0, D1, D2, D3, D5 }
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

#ifdef RGBLIGHT_ENABLE
#define RGB_DI_PIN F6
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 5
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LIMIT_VAL 200
#endif


#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN F6
#define RGBLED_NUM 5
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_DISABLE_WHEN_USB_SUSPENDED false
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
#endif

#ifdef VIAL_ENABLE
#define VIAL_KEYBOARD_UID {0x89, 0x5B, 0x48, 0x01, 0x00, 0x52, 0x88, 0xF1}
#endif


#endif
