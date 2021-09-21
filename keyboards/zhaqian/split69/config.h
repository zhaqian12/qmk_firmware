#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEEC
#define PRODUCT_ID      0x6061
#define DEVICE_VER      0x0001
#define MANUFACTURER    ZHAQIAN
#define PRODUCT         split69
#define DESCRIPTION     SPLIT 69 designed by zq

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 9
// /* key matrix pins */
#define MATRIX_ROW_PINS { B0, B1, E6, F0, F1 }                  //LEFT
#define MATRIX_COL_PINS { F4, F7, F6, F5, D4, D6, D7, C7, B4 }
#define MATRIX_ROW_PINS_RIGHT { F0, F1, F4, F5, F6 }
#define MATRIX_COL_PINS_RIGHT { D4, D6, D7, B4, B5, B6, C6, C7, D3 }
// #define MATRIX_ROW_PINS { F0, F1, F4, F5, F6 }                    //RIGHT
// #define MATRIX_COL_PINS { D4, D6, D7, B4, B5, B6, C6, C7, D3 }
#define USE_SERIAL
#define SELECT_SOFT_SERIAL_SPEED 1
#define SOFT_SERIAL_PIN D2
#define MASTER_RIGHT
#define SPLIT_USB_DETECT
#define SPLIT_MODS_ENABLE
#define SPLIT_USB_TIMEOUT 1000
/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */

// #ifdef BACKLIGHT_PIN
// #define BACKLIGHT_LEVELS 3
// #endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

//#define RGB_DI_PIN B7 //LEFT
#define RGB_DI_PIN B3  //RIGHT

#ifdef RGB_DI_PIN

// #define RGBLIGHT_SPLIT
// #define RGBLED_NUM 21
// #define RGBLED_SPLIT { 9, 12 }
// #define RGBLIGHT_EFFECT_BREATHING
// #define RGBLIGHT_EFFECT_ALTERNATING
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #define RGBLIGHT_SLEEP
// #define RGBLIGHT_LIMIT_VAL 200

#endif

#ifdef RGB_MATRIX_ENABLE
#define RGBLED_NUM 21
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200    
#define RGB_DISABLE_WHEN_USB_SUSPENDED false 
#define RGB_MATRIX_SPLIT { 9, 12 }
#define SPLIT_TRANSPORT_MIRROR
#endif

#ifdef ENCODER_ENABLE

#define ENCODERS_PAD_A { B2 }
#define ENCODERS_PAD_B { B3 }
#define ENCODER_RESOLUTION 3

#endif
#ifdef VIA_ENABLE
#define DYNAMIC_KEYMAP_LAYER_COUNT 3
#endif

#ifdef OLED_DRIVER_ENABLE
// #    define OLED_DISPLAY_128X64
// #    define I2C_DRIVER I2CD1
// //#    define OLED_IC OLED_IC_SH1106  // 选用1.3寸SH1106主控OLED时打开, 0.96寸SSD1306主控OLED注释掉本行。
// //#    define OLED_COLUMN_OFFSET 2  // 调整OLED纵向偏移，0.96寸SSD1306主控OLED注释掉本行。
// #    define I2C1_TIMINGR_PRESC 0U
// #    define I2C1_TIMINGR_SCLDEL 7U
// #    define I2C1_TIMINGR_SDADEL 0U
// #    define I2C1_TIMINGR_SCLH 38U
// #    define I2C1_TIMINGR_SCLL 129U
// #    define OLED_TIMEOUT 60000  // 60秒无操作关闭OLED
// #    define OLED_FONT_HEIGHT 8
// #    define OLED_FONT_WIDTH 6
// #    define OLED_FONT_H "././nfont.c"
#define OLED_DISPLAY_128X64
#define OLED_FONT_HEIGHT 8
#define OLED_FONT_WIDTH 6
#define OLED_FONT_H "././nfont.c"
#endif
#endif