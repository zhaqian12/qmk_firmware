# Readme Version
* [Enlish version](./readme.md)
* [Chinese version](./readme_cn.md)
  
# Table of Contents
- [Readme Version](#readme-version)
- [Table of Contents](#table-of-contents)
- [Keyboards Released by ZhaQian](#keyboards-released-by-zhaqian)
- [ZhaQian library](#zhaqian-library)
  - [Alt Tab Marco](#alt-tab-marco)
  - [Encoder Trigger](#encoder-trigger)
  - [Joystick Trigger](#joystick-trigger)
  - [Radial Controller](#radial-controller)
  - [RGB Matrix Control](#rgb-matrix-control)
  - [Underglow RGB Matrix](#underglow-rgb-matrix)
  - [UF2 Bootloader](#uf2-bootloader)
- [TODO LIST](#todo-list)
# Keyboards Released by ZhaQian
| NAME          | VENDOR_ID | PRODUCT_ID | PCB      | MCU      	        | FEATURES                                     |
|:-------------:| :-------: | :--------: | :------: |:----------------: | :------------------------------------------: |
| zq75v2        | 0x00AA    | 0xAA01     | Hotswap  | Atmel at90usb1286 | RGB, UGRGB, ENCODER, OLED                    |
| comb67        | 0x00AA    | 0xAA02     | Hotswap  | Atmel atmega32u4  | RGB, UGRGB                                   |
| zq75          | 0x00AA    | 0xAA03     | Hotswap  | Atmel atmega32u4  | RGB, SPLIT SPACE                             |
| zq60          | 0x00AA    | 0xAA04     | Hotswap  | Atmel atmega32u4  | ESCRGB, COMPATIBILITY LAYOUT                 |
| zq80          | 0x00AA    | 0xAA05     | Hotswap  | Atmel atmega32u4  | RGB, UGRGB, LOGORGB                          |
| tester        | 0x00AA    | 0xAA06     | Hotswap  | f103/401/411/vf103/l433/air32/f407 | RGB, UGRGB, ENCODER                          |
| zq48          | 0x00AA    | 0xAA07     | Hotswap  | Atmel atmega32u4  | RGB, UGRGB                                   |
| zq61          | 0x00AA    | 0xAA08     | Hotswap  | ST stm32f401      | RGB, UGRGB                                   |
| zq67          | 0x00AA    | 0xAA09     | Hotswap  | Atmel atmega32u4  | RGB, UGRGB                                   |
| zq11800       | 0x00AA    | 0xAA0A     | Solder   | Atmel atmega32u4  | ENCODER, RGB                                 |
| wave87        | 0x00AA    | 0xAA0B     | Hotswap  | Atmel atmega32u4  | LOGORGB                                      |
| zq980mini     | 0x00AA    | 0xAA0C     | Hotswap  | Atmel atmega32u4  | RGB, UGRGB                                   |
| zq67rev2      | 0x00AA    | 0xAA0D     | Hotswap  | Atmel atmega32u4  | RGB                                          |
| zq64          | 0x00AA    | 0xAA0E     | Hotswap  | ST stm32f103/f103  | RGB, ENCODER                                 |
| zq68          | 0x00AA    | 0xAA0F     | Hotswap  | ST stm32f103/f103  | RGB, ENCODER                                 |
| toxic67       | 0x00AA    | 0xAA10     | Hotswap  | Atmel atmega32u4  | RGB                                          |
| zq46	        | 0x00AA    | 0xAA11     | Hotswap  | ST stm32f401      | RGB, UGRGB, LOGORGB, ENCODER                 |
| osu	        | 0x00AA    | 0xAA12     | Hotswap  | ST stm32f401      | UGRGB                                        |
| zq89	        | 0x00AA    | 0xAA13     | Hotswap  | ST stm32f411      | RGB, ENCODERS                                |
| m80	        | 0x00AA    | 0xAA14     | Hotswap  | ST stm32f103/f103 | RGB                                          |
| sp67	        | 0x00AA    | 0xAA15     | Hotswap  | ST stm32f103/f103 | ENCODER                                      |
| zq50	        | 0x00AA    | 0xAA16     | Hotswap  | ST stm32f103/f103 | RGB, UGRGB, ENCODER                          |
| Jane_v2_ce_slot	| 0x00AA  | 0xAA17     | Hotswap  | Atmel atmega32u4  |                          |
| m80_solder	        | 0x00AA    | 0xAA18     | Solder  | ST stm32f103/f103 | RGB                                          |
| s75	        | 0x00AA    | 0xAA19     | Hotswap  | ST stm32f103/f103 | RGB                                          |
| Mpad12        | 0x00AA    | 0xAAAA     | Hotswap  | Atmel atmega32u4  | RGB, UGRGB, JOYSTICK, ENCODER, OLED          |
| split69       | 0x00AA    | 0xAAAB     | Solder   | Atmel atmega32u4  | SPLIT, UGRGB, OLED, ENCODER                  |
| joystickex    | 0x00AA    | 0xAAAC     | Hotswap  | f103/401/411/vf103/l433/air32 | JOYSTICK |
| GH60        | 0xFEED    | 0x6060    | Hotswap  | ST stm32f103/f103 | RGB          |
# ZhaQian library
这是一个集合了许多简单的但可能在不同键盘上重复用到功能的库.
 - Alt Tab Marco
 - Encoder Trigger
 - Joystick Trigger
 - Openrgb Protocol
 - Radial Controller
 - RGB Matrix Control
 - Underglow RGB Matrix
 - Via Custom Keycode
 - Via Custom Control
 - Custom RGB Matrix Effects
 - UF2 Bootloader
 - Signalrgb Protocol

## Alt Tab Marco
Alt Tab Marco的功能本质上是一个预设好的按键宏,实现Windows系统的切换窗口功能.如果需要使用该功能,请在 `rules.mk`中添加:
```make
ALT_TAB_MARCO_ENABLE = yes
```
如果需要更长或更短的宏触发时间,开以在 `config.h`中定义一下宏:
| Variable | Description | Default |
|----------|-------------|---------|
| `ALT_TAB_MARCO_DELAY` | Alt tab marco delay time | 1000 |

## Encoder Trigger
Encoder Trigger实现了编码器的映射键盘矩阵按键触发功能,便于使用`via`和`dynamic_keymap`功能实现对编码器功能的自定义.如果需要使用该功能,请在 `rules.mk`中添加:
```make
ENCODER_ENABLE = yes
ENCODER_TRIGGER_ENABLE = yes
```
并在`config.h`中定义编码器顺时针,逆时针触发按键的矩阵映射位置`{行,列}`:
```c
#define ENCODER_PAD_A_KEY_POS {1, 0} // 顺时针
#define ENCODER_PAD_B_KEY_POS {0, 0} // 逆时针
```
同时该功能支持多个编码器,例如:
```c
#define ENCODER_PAD_A_KEY_POS {1, 0}, {3, 0} // {col, row}
#define ENCODER_PAD_B_KEY_POS {0, 0}, {2, 0} // {col, row}
```

## Joystick Trigger
Joystick Trigger功能实现了具有X,Y轴的摇杆电位器四个方向的按键的矩阵映射触发功能.如果需要使用该功能,请在 `rules.mk`中添加:
```make
JOYSTICK_TRIGGER_ENABLE = yes
```
并在`config.h`中定义:
| Variable | Description | Default |
|----------|-------------|---------|
| `JOYSTICK_ADC_RESOLUTION` | ADC采样精度 | 10 |
| `JOYSTICK_AXES_X_PIN` | X轴引脚 |  |
| `JOYSTICK_AXES_Y_PIN` | Y轴引脚 |  |
| `JOYSTICK_AXES_PX_KEY_POS` | X轴正方向触发按键矩阵映射位置 |  |
| `JOYSTICK_AXES_NX_KEY_POS` | X轴反方向触发按键矩阵映射位置|  |
| `JOYSTICK_AXES_PY_KEY_POS` | Y轴正方向触发按键矩阵映射位置 |  |
| `JOYSTICK_AXES_NY_KEY_POS` | Y轴反方向触发按键矩阵映射位置|  |

当然,该功能也支持多个摇杆的使用.

## Radial Controller
Radial Controller功能实现了对WIN10的轮盘功能的模拟(仅适用支持轮盘功能的版本系统).如果需要使用该功能,请在 `rules.mk`中添加:
```make
RADIAL_CONTROLLER_ENABLE = yes
```
以下参数可以在 `config.h`中定义:
| Variable | Description | Default |
|----------|-------------|---------|
| `RADIAL_CONTROLLER_RESOLUTION` | The rotation resolution of radial controller  | 100 |
| `RADIAL_CONTROLLER_ROTATION_STEP` | The rotation step of radial controller | 10 |
| `RADIAL_CONTROLLER_TIMER_DELAY` | The report send delay of radial controller | 15 |
| `RADIAL_CONTROLLER_ROTATION_CONTINUE_STEP` | The rotation step of radial controller continue triggered | 100 |

## RGB Matrix Control
RGB Matrix Control功能实现了对RGB矩阵系统的底灯和轴灯的开关的独立控制.如果需要使用该功能,请在 `rules.mk`中添加:
```make
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_CONTROL_ENABLE = yes
```

## Underglow RGB Matrix
Underglow RGB Matrix功能实现了RGB矩阵系统的独立的底灯灯效.如果需要使用该功能,请在 `rules.mk`中添加:
```mak
RGB_MATRIX_ENABLE = yes
UNDERGLOW_RGB_MATRIX_ENABLE = yes
```
可以在`config.h`定义以下宏:
```c
#define UG_RGB_MATRIX_ANIMATIONS // 开启除了WPM以外的全部灯效
#define UG_RGB_MATRIX_WPM_ANIMATIONS // 开启全部WPM灯效
#define UNDERGLOW_RGB_MATRIX_API_DISABLE // 关闭该功能的独立颜色,亮度,速度设置 
```
所有灯效如下所示:
| Define|Underglow rgb matrix effect |
|----------|-----------|
|UG_RGB_MATRIX_BREATHING|BREATHING|
|UG_RGB_MATRIX_CYCLEBREATHING|CYCLE BREATHING|
|UG_RGB_MATRIX_CYCLEBANDVAL|CYCLE BAND VAL|
|UG_RGB_MATRIX_CYCLEBANDPINWHEELVAL|CYCLE BAND PINWHEEL VAL|
|UG_RGB_MATRIX_CYCLEALL|CYCLE ALL|
|UG_RGB_MATRIX_CYCLELEFTRIGHT|CYCLE LEFT RIGHT|
|UG_RGB_MATRIX_CYCLEUPDOWN|CYCLE UP DOWN|
|UG_RGB_MATRIX_CYCLEOUTIN|CYCCYCLEINOUTLE OUT IN|
|UG_RGB_MATRIX_CYCLEINOUT|CYCLE IN OUT|
|UG_RGB_MATRIX_RAINBOWPINWHEEL|RAINBOW PINWHEEL|
|UG_RGB_MATRIX_CYCLESPIRAL|CYCLE SPIRAL|
|UG_RGB_MATRIX_WPMCYCLELEFTRIGHT|WPM CYCLE LEFT RIGHT|
|UG_RGB_MATRIX_WPMRAINBOWPINWHEEL|WPM RAINBOW PINWHEEL|
|UG_RGB_MATRIX_WPMCYCLEBREATHING|WPM CYCLE BREATHING|
|UG_RGB_MATRIX_WPMCYCLESPIRAL|WPM CYCLE SPIRAL|
|UG_RGB_MATRIX_WPMCYCLEINOUT|WPM CYCLE INOUT|

可以在`config.h`定义更改以下参数:
```c
#define UNDERGLOW_RGB_MATRIX_MAXIMUM_BRIGHTNESS RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define UNDERGLOW_RGB_MATRIX_HUE_STEP 8
#define UNDERGLOW_RGB_MATRIX_SAT_STEP 16
#define UNDERGLOW_RGB_MATRIX_VAL_STEP 16
#define UNDERGLOW_RGB_MATRIX_SPD_STEP 16
#define UNDERGLOW_RGB_MATRIX_STARTUP_MODE UG_RGB_MATRIX_SYNC
#define UNDERGLOW_RGB_MATRIX_STARTUP_HUE 0
#define UNDERGLOW_RGB_MATRIX_STARTUP_SAT UINT8_MAX
#define UNDERGLOW_RGB_MATRIX_STARTUP_VAL UNDERGLOW_RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define UNDERGLOW_RGB_MATRIX_STARTUP_SPD (UINT8_MAX / 2)
```

## UF2 Bootloader
UF2 Bootloader储存了预编译好的MSC下载方式的引导程序,目前支持以下型号的主控.
| 支持的MCU  |  描述 |
|---------- | ---------- |
|STM32F103x8||
|STM32F103xB||
|STM32F401xC||
|STM32F411xE||
|GD32VF103xB||
|AIR32F103xB| 无需硬件DP上拉|
|AIR32F103xC| 无需硬件DP上拉|

# TODO LIST

- Bluetooth (esp32s3,ch58x or nrf)
- Rgb matrix control software (usb hid)
