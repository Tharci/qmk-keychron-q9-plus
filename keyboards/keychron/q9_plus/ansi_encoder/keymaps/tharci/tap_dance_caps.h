//
// Created by tharci on 5/31/24.
//

#ifndef QMK_FIRMWARE_TAP_DANCE_CAPS_H
#define QMK_FIRMWARE_TAP_DANCE_CAPS_H

#include "quantum.h"

#define TD_ACTION_CAPS ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_caps_finished, td_caps_reset)

void td_caps_finished(tap_dance_state_t *state, void *user_data);
void td_caps_reset(tap_dance_state_t *state, void *user_data);

#endif // QMK_FIRMWARE_TAP_DANCE_CAPS_H
