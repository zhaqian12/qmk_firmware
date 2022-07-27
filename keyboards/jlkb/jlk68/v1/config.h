#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x5002
#define DEVICE_VER      0x0001
#define MANUFACTURER    JL-K68
#define PRODUCT         JL-K68
#define DESCRIPTION     JL-K68

/* key matrix size */
#define MATRIX_ROWS 9
#define MATRIX_COLS 9

/* key matrix pins */
#define MATRIX_ROW_PINS { D7, E6, B0, B1, B2, B3, B7, D2, C7 }
#define MATRIX_COL_PINS { D7, E6, B0, B1, B2, B3, B7, D2, C7 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Rotary Encoder */
#define ENCODERS_PAD_A { F7 }
#define ENCODERS_PAD_B { E2 }
#define ENCODER_RESOLUTION 4  //the default & suggested is 4

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

#define RGB_DI_PIN D5
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 23
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif
