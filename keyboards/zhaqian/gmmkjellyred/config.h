#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x4C88
#define DEVICE_VER      0x0001
#define MANUFACTURER    Glorious
#define PRODUCT         GmmkPro_Jelly

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 15

/* key matrix pins */
#define MATRIX_ROW_PINS { F7, F6, F5, F4, F1, F0 }
#define MATRIX_COL_PINS { B4, B5, B6, C6, C7, E6, B0, B1, D0, D1, D2, D3, D5, D4, D6 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW
#define DEBOUNCE 5

/* number of backlight levels */
#define LED_CAPS_LOCK_PIN B7
#define LED_PIN_ON_STATE 0

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

#define RGB_DI_PIN D7
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 16
#define RGBLIGHT_LED_MAP { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }

#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN D7
#define RGBLED_NUM 16
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_DISABLE_WHEN_USB_SUSPENDED true
#define RGB_MATRIX_ANIMATION
#endif

/* Capslock
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {1, 1, HSV_RED}
);
*/

/* 编码器 */
#define ENCODERS_PAD_A { B2 }
#define ENCODERS_PAD_B { B3 }
#define ENCODER_RESOLUTION 2
#define TAP_CODE_DELAY 10
