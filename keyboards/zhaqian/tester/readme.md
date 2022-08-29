# tester

A test keyboard with rgb and different mcus.
This keyboard use different mcus.

* Keyboard Maintainer: [zhaqian](https://github.com/zhaqian12)
* Hardware Supported: tester
* Hardware Availability: [zq-kb](https://github.com/zhaqian12/ZQ-Keyboard)

Make example for this keyboard (after setting up your build environment):

* MCU:at90usb1286
    ```
    make zhaqian/tester/at90usb1286:default
    make zhaqian/tester/at90usb1286:via
    ```

* MCU:atmega32u4
    ```
    make zhaqian/tester/atmega32u4:default
    make zhaqian/tester/atmega32u4:via
    ```

* MCU:stm32f103/apm32f103/cks32f103/gd32f103/gd32f303
    ```
    make zhaqian/tester/f103:default
    make zhaqian/tester/f103:via
    ```

* MCU:stm32f401 (recommended)
    ```
    make zhaqian/tester/f401:default
    make zhaqian/tester/f401:via
    ```

* MCU:stm32f411 (recommended)
    ```
    make zhaqian/tester/f411:default
    make zhaqian/tester/f411:via
    ```
    
* MCU:gd32vf103
    ```
    make zhaqian/tester/gd32vf103:default
    make zhaqian/tester/gd32vf103:via
    ```
    
* MCU:stm32l433
    ```
    make zhaqian/tester/l433:default
    make zhaqian/tester/l433:via
    ```
    
 * MCU:air32f103xB/xC
    ```
    make zhaqian/tester/air32f103:default
    make zhaqian/tester/air32f103:via
    ```

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
 
