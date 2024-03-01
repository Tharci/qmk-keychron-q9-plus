//
// Created by tharci on 5/31/24.
//

#ifndef QMK_FIRMWARE_TAP_DANCE_H
#define QMK_FIRMWARE_TAP_DANCE_H

enum tap_dance {
    TD_CAPS,
    TD_MACRO_1,
    TD_MACRO_2,
    TD_RIGHT_SPACE,
    TD_GAMING,
};


// if the file is included from the keymap source file
#ifdef KEYMAP_SOURCE_FILE

#include "tap_dance.h"
#include "extra/extra_keycodes.h"
#include "tap_dance_caps.h"
#include "tap_dance_dynamic_macros.h"
#include "tap_dance_gaming_layer.h"
#include "tap_dance_right_space.h"
#include "layers.h"


tap_dance_action_t tap_dance_actions[] = {
    [TD_CAPS]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_caps_finished, td_caps_reset),
    [TD_MACRO_1] = ACTION_TAP_DANCE_FN(td_macro_1),
    [TD_MACRO_2] = ACTION_TAP_DANCE_FN(td_macro_2),
    // [TD_RIGHT_SPACE] = ACTION_TAP_DANCE_DOUBLE(KC_SPACE_NUM, MO(LY_FN_SPACE)),
    [TD_RIGHT_SPACE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_right_space_finished, td_right_space_reset),
    [TD_GAMING]      = ACTION_TAP_DANCE_FN_ADVANCED(td_gaming_each, td_gaming_finished, td_gaming_reset),
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LY_BASE] = {ENCODER_CCW_CW(KC_KNOB_LEFT, KC_KNOB_RIGHT)},
    [LY_FNC]  = {ENCODER_CCW_CW(_______, _______)},
    [LY_FNC_SH] = {ENCODER_CCW_CW(_______, _______)},
    [LY_GAMING]  = {ENCODER_CCW_CW(_______, _______)},
    [LY_FN_GAMING]  = {ENCODER_CCW_CW(_______, _______)},
    [LY_FN_SPACE]  = {ENCODER_CCW_CW(_______, _______)},
    [LY_FN1]      = {ENCODER_CCW_CW(_______, _______)},
    [LY_FN2]      = {ENCODER_CCW_CW(_______, _______)},
    [LY_SPACE_NUM] = {ENCODER_CCW_CW(_______, _______)},
};
#endif

#endif

#endif // QMK_FIRMWARE_TAP_DANCE_H
