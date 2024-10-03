VIA_ENABLE = no
ENCODER_MAP_ENABLE = yes
LEADER_ENABLE = no
TAP_DANCE_ENABLE = yes
MOUSEKEY_ENABLE = yes
COMMAND_ENABLE = no  # needed for CAPS_WORD_ENABLE
CAPS_WORD_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
SLEEP_LED_ENABLE = yes
RGB_MATRIX_ENABLE = yes

VPATH += keyboards/keychron/common
SRC += keychron_common.c

# SRC += $(wildcard $(TOP_DIR)/keyboards/keychron/common/extra/*.c)
SRC += extra/dynamic_macro_helper.c
SRC += extra/caps_word.c
SRC += extra/common.c
SRC += extra/tap_dance_helper.c
SRC += extra/knob.c
SRC += extra/tabloop.c
SRC += extra/tap_dance_dynamic_macros.c

SRC += space_num.c
SRC += tap_dance_caps.c
SRC += tap_dance_right_space.c
SRC += tap_dance_gaming_layer.c
SRC += gaming_mode.c
SRC += gaming_numpad.c
