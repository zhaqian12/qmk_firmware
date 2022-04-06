# MCU name
MCU = STM32F103

# Bootloader selection
BOOTLOADER = tinyuf2

# Build Options
#   comment out to disable the options.
#
BOOTMAGIC_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
SLEEP_LED_ENABLE = no
NKRO_ENABLE = yes
RGBLIGHT_ENABLE = no
KEYBOARD_SHARED_EP = yes

OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
