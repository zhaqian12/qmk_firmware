# MCU name
MCU = atmega32u4

NKRO_ENABLE = yes # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
VIA_ENABLE = no

BOOTMAGIC_ENABLE = no	# Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = no		# Mouse keys(+4700)
EXTRAKEY_ENABLE= no		# Audio control and System control(+450)
CONSOLE_ENABLE = no	# Console for debug(+400)
COMMAND_ENABLE = no    # Commands for debug and configuration
SLEEP_LED_ENABLE = no  # Breathing sleep LED during USB suspend
BACKLIGHT_ENABLE = no  # Enable keyboard backlight functionality
AUDIO_ENABLE = no
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
RGB_MATRIX_CUSTOM_USER = yes
ENCODER_ENABLE = no
VIA_ENABLE = no
RAW_ENABLE = yes
OPENRGB_ENABLE = yes


