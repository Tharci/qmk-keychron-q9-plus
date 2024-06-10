//
// Created by tharci on 5/31/24.
//

#ifndef QMK_FIRMWARE_TAP_DANCE_RIGHT_SPACE_H
#define QMK_FIRMWARE_TAP_DANCE_RIGHT_SPACE_H

#include "quantum.h"

#define TD_ACTION_RIGHT_SPACE ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_right_space_finished, td_right_space_reset)

void td_right_space_finished(tap_dance_state_t *state, void *user_data);
void td_right_space_reset(tap_dance_state_t *state, void *user_data);

#endif // QMK_FIRMWARE_TAP_DANCE_RIGHT_SPACE_H
