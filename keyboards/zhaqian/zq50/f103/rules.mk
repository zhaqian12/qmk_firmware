# MCU name
MCU = STM32F103
MCU_LDSCRIPT = STM32F103xB_uf2
FIRMWARE_FORMAT = uf2
BOARD = STM32_F103_STM32DUINO

# Bootloader selection
BOOTLOADER = custom

WS2812_DRIVER = pwm

EEPROM_DRIVER = wear_leveling
WEAR_LEVELING_DRIVER = embedded_flash

KEYBOARD_SHARED_EP = yes
LTO_ENABLE = yes

OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
SRC += uf2_boot.c

