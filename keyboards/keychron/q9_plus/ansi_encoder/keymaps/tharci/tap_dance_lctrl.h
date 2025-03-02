//
// Created by tharci on 03/02/25.
//

#ifndef QMK_FIRMWARE_TAP_DANCE_LCTRL_H
#define QMK_FIRMWARE_TAP_DANCE_LCTRL_H

#include "quantum.h"

#define TD_ACTION_LCTRL ACTION_TAP_DANCE_FN_ADVANCED_WITH_RELEASE(td_lctrl_tap, td_lctrl_release, td_lctrl_finished, td_lctrl_reset)

void td_lctrl_tap(tap_dance_state_t* state, void* user_data);
void td_lctrl_release(tap_dance_state_t* state, void* user_data);
void td_lctrl_finished(tap_dance_state_t *state, void *user_data);
void td_lctrl_reset(tap_dance_state_t *state, void *user_data);

#endif // QMK_FIRMWARE_TAP_DANCE_LCTRL_H
