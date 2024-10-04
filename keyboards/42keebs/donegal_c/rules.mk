# MCU name

EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
NKRO_ENABLE = no

TAP_DANCE_ENABLE = yes
#WPM_ENABLE = yes

VIA_ENABLE = yes

OLED_ENABLE = yes
OLED_DRIVER_ENABLE = yes
OLED_DRIVER = ssd1306

#ifneq ($(strip $(NO_SECRETS)), yes)
#    ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
#        SRC += secrets.c
#    endif
#endif
