#include "config_common.h"

/* USB Device descriptor parameter  定义via使用*/
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    bbc        //制造商、产品、描述
#define PRODUCT         bbc67
#define DESCRIPTION     Keyboard
/* key matrix size 矩阵*/
#define MATRIX_ROWS 5
#define MATRIX_COLS 15
#define USB_POLLING_INTERVAL_MS 1 //设置键盘、鼠标和共享（NKRO/媒体键）接口的 USB 轮询速率（以毫秒为单位）
/* key matrix pins 行列引脚 从0个开始排列*/
#define MATRIX_ROW_PINS { F5, F4, F1, B0, D5 }
#define MATRIX_COL_PINS { B4, B5, B6, C7, F7, C6, F6, F0, B1, B7, D0, E6, D1, D2, D3 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL  行到列或者列到行*/
#define DIODE_DIRECTION COL2ROW

// via加层数

#define DYNAMIC_KEYMAP_LAYER_COUNT 5


/* Set 0 if debouncing isn't needed 按下到引脚触发时间读取引脚值时的延迟（默认为 5）*/
#define DEBOUNCE 0
//旋钮
#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { B2 }
#define ENCODERS_PAD_B { B3 }
#define ENCODER_RESOLUTION 4   //刻度
#define ENCODER_DIRECTION_FLIP //反向(无反向则注释)
#endif
//RGB
#ifdef RGB_MATRIX_ENABLE
// The pin connected to the data pin of the LEDs
#define RGB_DI_PIN D7 //RGB引脚
// The number of LEDs connected
#define DRIVER_LED_TOTAL 86  //灯数量
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255 //最大亮度
//#define RGB_MATRIX_CENTER { 112, 32 }  //键盘中心
// #define RGB_MATRIX_KEYPRESSES //对按键做出反应
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS //帧缓冲
#define RGB_MATRIX_STARTUP_SPD 50 //默认RGB速度
#endif
