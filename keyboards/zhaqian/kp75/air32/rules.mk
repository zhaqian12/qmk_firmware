MCU_LDSCRIPT = AIR32F103xC_big_sram_uf2boot
AIR32F10x_USE_UNLOCKED_SRAM = yes

WS2812_DRIVER = pwm

KEYBOARD_SHARED_EP = yes
LTO_ENABLE = yes

OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

