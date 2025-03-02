//
// Created by tharci on 03/02/25.
//

#ifndef QMK_FIRMWARE_TAP_DANCE_LALT_H
#define QMK_FIRMWARE_TAP_DANCE_LALT_H

#include "quantum.h"

#define TD_ACTION_LALT ACTION_TAP_DANCE_FN_ADVANCED_WITH_RELEASE(td_lalt_tap, td_lalt_release,td_lalt_finished, td_lalt_reset)

void td_lalt_tap(tap_dance_state_t* state, void* user_data);
void td_lalt_release(tap_dance_state_t* state, void* user_data);
void td_lalt_finished(tap_dance_state_t *state, void *user_data);
void td_lalt_reset(tap_dance_state_t *state, void *user_data);

#endif // QMK_FIRMWARE_TAP_DANCE_LALT_H
