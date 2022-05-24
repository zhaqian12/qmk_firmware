MCU = STM32F103
MCU_LDSCRIPT = STM32F103xB_uf2
FIRMWARE_FORMAT = uf2
BOARD = STM32_F103_STM32DUINO

# Bootloader selection
BOOTLOADER = custom
# BOOTLOADER = stm32duino
<<<<<<< Updated upstream
BOOTLOADER = tinyuf2
=======
>>>>>>> Stashed changes

OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

KEYBOARD_SHARED_EP = yes
WS2812_DRIVER = pwm
<<<<<<< Updated upstream
=======
QUANTUM_LIB_SRC += uart.c
SRC += uf2_boot.c
>>>>>>> Stashed changes

