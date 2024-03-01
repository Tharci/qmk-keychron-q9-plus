VIA_ENABLE = no
ENCODER_MAP_ENABLE = yes
LEADER_ENABLE = no
TAP_DANCE_ENABLE = yes
MOUSEKEY_ENABLE = yes
COMMAND_ENABLE = no  # needed for CAPS_WORD_ENABLE
CAPS_WORD_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes

VPATH += keyboards/keychron/common
SRC += keychron_common.c
SRC += ./dynamic_macro_helper.c
