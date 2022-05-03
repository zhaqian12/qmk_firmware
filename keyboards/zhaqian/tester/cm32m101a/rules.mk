MCU = CM32M101A

# BOOTLOADER = stm32duino
BOOTLOADER = stm32-dfu

OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

KEYBOARD_SHARED_EP = no
# WS2812_DRIVER = pwm
# LTO_ENABLE = yes
SRC += ../../../../lib/RTT/SEGGER_RTT_printf.c \
		../../../../lib/RTT/SEGGER_RTT.c

INC += ../../../../lib/RTT