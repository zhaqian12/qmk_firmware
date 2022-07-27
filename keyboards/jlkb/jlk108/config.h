#pragma once
#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x5003
#define DEVICE_VER      0x0001
#define MANUFACTURER    JL-K108
#define PRODUCT         JL-K108

#define VIAL_KEYBOARD_UID {0xC6, 0x38, 0x14, 0x65, 0x69, 0x0C, 0x9C, 0xFB}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 5, 8 }

#define MIDI_ADVANCED

/* 层数 */
#  define DYNAMIC_KEYMAP_LAYER_COUNT 3

/* key matrix size */
#define MATRIX_ROWS 7
#define MATRIX_COLS 17
 
 /* 层指示灯 */
#define RGBLIGHT_LAYERS

/* key matrix pins */
#define MATRIX_ROW_PINS {  B9, B8, B7, B6, B5, B4, B3}
#define MATRIX_COL_PINS {  B9, B8, B7, B6, B5, B4, B3, C13, C14, C15, A0, A1, A2, A3, A4, A5, A6}
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* 编码器 */
#define ENCODERS_PAD_A { A7, B1 }
#define ENCODERS_PAD_B { B0, B10 }

#define ENCODER_RESOLUTION 4

/* 编码器01 */
#define ENCODER_DEFAULT_POS 0x3

/* 指示灯 */
#define LED_CAPS_LOCK_PIN B12
#define LED_NUM_LOCK_PIN B13
#define LED_SCROLL_LOCK_PIN B14
#define LED_PIN_ON_STATE -1 /* 指示灯 LED“亮”时指示灯引脚的状态 -1高电平，0低电平*/

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

/* Set 0 if debouncing isn't needed */
/*  #define DEBOUNCING_DELAY 5 */

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* prevent stuck modifiers */
/* #define PREVENT_STUCK_MODIFIERS */

