# Build Options
#   change yes to no to disable
#
# MCU name
MCU = STM32F401

# Bootloader selection
BOOTLOADER = stm32-dfu

# Build Options
#   change yes to no to disable
#
KEYBOARD_SHARED_EP       = yes

BOOTMAGIC_ENABLE = lite       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no     # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = no     # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
BLUETOOTH_ENABLE = no       # Enable Bluetooth
AUDIO_ENABLE = no           # Audio output
OLED_DRIVER_ENABLE = no
ENCODER_ENABLE = yes
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
WS2812_DRIVER = pwm
RGB_MATRIX_CUSTOM_KB = yes
RGB_MATRIX_CONTROL_ENABLE = yes
UNDERGLOW_RGB_MATRIX_ENABLE = yes
ENCODER_TRIGGER_ENABLE = yes
WPM_ENABLE = yes
VELOCIKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
NO_USB_STARTUP_CHECK = yes
SRC += keyboards/zhaqian/zqlib/alttabmarco.c
