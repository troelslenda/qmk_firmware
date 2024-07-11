# MCU name
MCU = atmega328p
BOOTLOADER = usbasploader

BOOTMAGIC_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
NKRO_ENABLE = no

TAP_DANCE_ENABLE = yes
#WPM_ENABLE = yes


OLED_ENABLE = yes
OLED_DRIVER_ENABLE = yes
OLED_DRIVER = SSD1306

#ifneq ($(strip $(NO_SECRETS)), yes)
#    ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
#        SRC += secrets.c
#    endif
#endif
