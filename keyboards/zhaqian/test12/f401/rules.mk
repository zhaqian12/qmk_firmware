# MCU name
MCU = STM32F401

# Address of the bootloader in system memory
STM32_BOOTLOADER_ADDRESS = 0x1FFF0000

# Bootloader selection
BOOTLOADER = stm32-dfu
# ENCODER_ENABLE = yes
# # project specific file
CUSTOM_MATRIX = lite    # for using the A9 pin as matrix io
QUANTUM_SRC += matrix.c
EEPROM_DRIVER = custom
SRC += eep/eeprom_stm32.c
SRC += eep/flash_stm32.c
OPT_DEFS += -DEEPROM_EMU_STM32F401xC
COMMON_VPATH += patsubst$(%/, %, dir $(mkfile_patch))/eep

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
WS2812_DRIVER = pwm

ENCODER_ENABLE = yes

OLED_DRIVER_ENABLE = no
RGB_MATRIX_CUSTOM_KB = yes
RGB_MATRIX_CONTROL_ENABLE = yes
UNDERGLOW_RGB_MATRIX_ENABLE = yes
ENCODER_TRIGGER_ENABLE = yes
WPM_ENABLE = yes
VELOCIKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes

SRC += keyboards/zhaqian/zqlib/alttabmarco.c

OPT_DEFS += -DSTM32_EEPROM_F401_ENABLE
# # # Enter lower-power sleep mode when on the ChibiOS idle thread
# OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

KEYBOARD_SHARED_EP = yes
OPT_DEFS += -DSTM32_DMA_REQUIRED=TRUE
