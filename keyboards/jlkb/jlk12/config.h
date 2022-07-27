#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x5007
#define DEVICE_VER      0x0001
#define MANUFACTURER    JLK12_E4
#define PRODUCT         JLK12_E4
#define DESCRIPTION     JLK12_E4

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 6

/* key matrix pins */
#define MATRIX_ROW_PINS { E6, B0, B1, B2, B3, B7 }
#define MATRIX_COL_PINS { E6, B0, B1, B2, B3, B7 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* 编码器 */
#define ENCODERS_PAD_A { F5, F7, B5, C6 }
#define ENCODERS_PAD_B { F6, C7, B4, B6 }

#define ENCODER_RESOLUTION 4

/* 指示灯 */
#define LED_CAPS_LOCK_PIN F0
#define LED_NUM_LOCK_PIN F1
#define LED_SCROLL_LOCK_PIN F4
#define LED_PIN_ON_STATE 0  /* 指示灯 LED“亮”时指示灯引脚的状态 -1高电平，0低电平*/

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

#define RGB_DI_PIN D7
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif
/* OLED Configuration */
#ifdef OLED_ENABLE
    #define OLED_TIMEOUT	    60000
    #define OLED_LOGO_TIMEOUT   3000  // How long (in ms) the logo appears at start up
#endif

#endif