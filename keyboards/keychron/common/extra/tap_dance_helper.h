//
// Created by tharci on 5/30/24.
//

#ifndef QMK_FIRMWARE_TAP_DANCE_HELPER_H
#define QMK_FIRMWARE_TAP_DANCE_HELPER_H

#include "quantum.h"

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;


typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;


#define TD_INIT_STATE ((td_tap_t) {.is_press_action = true, .state = TD_NONE})
td_state_t td_cur_dance(tap_dance_state_t *state);


#endif // QMK_FIRMWARE_TAP_DANCE_HELPER_H
