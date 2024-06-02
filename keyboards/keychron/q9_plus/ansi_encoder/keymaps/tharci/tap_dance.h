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
    NUM_OF_TAP_DANCES,
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

tap_dance_action_t tap_dance_actions[NUM_OF_TAP_DANCES] = {
    [TD_CAPS]        = TD_ACTION_CAPS,
    [TD_MACRO_1]     = TD_ACTION_MACRO_1,
    [TD_MACRO_2]     = TD_ACTION_MACRO_2,
    [TD_RIGHT_SPACE] = TD_ACTION_RIGHT_SPACE,
    [TD_GAMING]      = TD_ACTION_GAMING,
};

#endif

#endif // QMK_FIRMWARE_TAP_DANCE_H
