# Readme Version
* [Enlish version](./readme.md)
* [Chinese version](./readme_cn.md)

# Table of Contents
- [Readme Version](#readme-version)
- [Table of Contents](#table-of-contents)
- [Keyboards Released by ZhaQian](#keyboards-released-by-zhaqian)
- [TODO LIST](#todo-list)
- [ZhaQian library](#zhaqian-library)
  - [Alt Tab Marco](#alt-tab-marco)
  - [Encoder Trigger](#encoder-trigger)
  - [Joystick Trigger](#joystick-trigger)
  - [Radial Controller](#radial-controller)
  - [RGB Matrix Control](#rgb-matrix-control)
  - [Underglow RGB Matrix](#underglow-rgb-matrix)
  - [UF2 Bootloader](#uf2-bootloader)

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
| Jane_v2_ce_slot	| 0x00AA    | 0xAA17     | Hotswap  | Atmel atmega32u4 |                          |
| m80_solder	        | 0x00AA    | 0xAA18     | Solder  | ST stm32f103/f103 | RGB                                          |
| s75	        | 0x00AA    | 0xAA19     | Hotswap  | ST stm32f103/f103 | RGB                                          |
| Mpad12        | 0x00AA    | 0xAAAA     | Hotswap  | Atmel atmega32u4  | RGB, UGRGB, JOYSTICK, ENCODER, OLED          |
| split69       | 0x00AA    | 0xAAAB     | Solder   | Atmel atmega32u4  | SPLIT, UGRGB, OLED, ENCODER                  |
| joystickex    | 0x00AA    | 0xAAAC     | Hotswap  | f103/401/411/vf103/l433/air32 | JOYSTICK |
| GH60        | 0xFEED    | 0x6060    | Hotswap  | ST stm32f103/f103 | RGB          |
# TODO LIST
- BLE 
    - [ ] CH58X protocol of qmk 
    - [x] new kb firmware(use cherry usb)
- Rgb matrix control software (usb hid)

# ZhaQian library
 This is a simple library that integrates some common repetitive functions.
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
This feature integrates the toggle window function in window system.It is supported by adding this to your `rules.mk`:
```make
ALT_TAB_MARCO_ENABLE = yes
```
If you need more delay time to active this marco,you can define it in your `config.h`:
| Variable | Description | Default |
|----------|-------------|---------|
| `ALT_TAB_MARCO_DELAY` | Alt tab marco delay time | 1000 |

## Encoder Trigger
This feature integrates the trigger of encoder, it can simply use when you use via, only through some define.It is supported by adding this to your `rules.mk`:
```make
ENCODER_ENABLE = yes
ENCODER_TRIGGER_ENABLE = yes
```
and these to your `config.h`,they define the matrix positions of the clockwise and counterclockwise mappings of the encoder:
```c
#define ENCODER_PAD_A_KEY_POS {1, 0} // {col, row}
#define ENCODER_PAD_B_KEY_POS {0, 0} // {col, row}
```
Each PAD_A/B variable defines an array so multiple encoders can be defined, e.g.:
```c
#define ENCODER_PAD_A_KEY_POS {1, 0}, {3, 0} // {col, row}
#define ENCODER_PAD_B_KEY_POS {0, 0}, {2, 0} // {col, row}
```

## Joystick Trigger
This feature integrates the trigger of joystick which has two axes,it maps the joystick to four buttons in the keyboard matrix.It is supported by adding this to your `rules.mk`:
```make
JOYSTICK_TRIGGER_ENABLE = yes
```
and these to your `config.h`:
| Variable | Description | Default |
|----------|-------------|---------|
| `JOYSTICK_ADC_RESOLUTION` | The bits of  mcu adc sampling accuracy | 10 |
| `JOYSTICK_AXES_X_PIN` | The X axes pin of joystick |  |
| `JOYSTICK_AXES_Y_PIN` | The Y axes pin of joystick |  |
| `JOYSTICK_AXES_PX_KEY_POS` | The mapped key position of positive X trigger |  |
| `JOYSTICK_AXES_NX_KEY_POS` | The mapped key position of negative X trigger |  |
| `JOYSTICK_AXES_PY_KEY_POS` | The mapped key position of positive Y trigger |  |
| `JOYSTICK_AXES_NY_KEY_POS` | The mapped key position of negative Y trigger |  |

It can also use if you need multiple joysticks.

## Radial Controller
This feature virtualize the function of radial controller in windows 10.It is supported by adding this to your `rules.mk`:
```make
RADIAL_CONTROLLER_ENABLE = yes
```
You can add these define to your `config.h`:
| Variable | Description | Default |
|----------|-------------|---------|
| `RADIAL_CONTROLLER_RESOLUTION` | The rotation resolution of radial controller  | 100 |
| `RADIAL_CONTROLLER_ROTATION_STEP` | The rotation step of radial controller | 10 |
| `RADIAL_CONTROLLER_TIMER_DELAY` | The report send delay of radial controller | 15 |
| `RADIAL_CONTROLLER_ROTATION_CONTINUE_STEP` | The rotation step of radial controller continue triggered | 100 |

## RGB Matrix Control
This feature supports independent control of different areas in rgb matrix .It is supported by adding this to your `rules.mk`:
```make
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_CONTROL_ENABLE = yes
```

## Underglow RGB Matrix
This feature supports independent effect of underglow area in rgb matrix .It is supported by adding this to your `rules.mk`:
```make
RGB_MATRIX_ENABLE = yes
UNDERGLOW_RGB_MATRIX_ENABLE = yes
```
You can add this define in you `config.h`:
```c
#define UG_RGB_MATRIX_ANIMATIONS // enable all effects of this feature except wpm effects
#define UG_RGB_MATRIX_WPM_ANIMATIONS // enable all wpm effects of this feature
#define UNDERGLOW_RGB_MATRIX_API_DISABLE // diasble underglow rgb matrix api
```
All the rgb matrix effects of this feature are as follows.
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

You can also alternate these defines to control these feature:
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
| Support Devices  |  Description |
|---------- | ---------- |
|STM32F103x8||
|STM32F103xB||
|STM32F401xC||
|STM32F411xE||
|GD32VF103xB||
|AIR32F103xB| No hardware DP pull-up required|
|AIR32F103xC| No hardware DP pull-up required|
