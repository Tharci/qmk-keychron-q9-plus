//
// Created by tharci on 5/31/24.
//

#ifndef QMK_FIRMWARE_TAP_DANCE_GAMING_LAYER_H
#define QMK_FIRMWARE_TAP_DANCE_GAMING_LAYER_H

#include "quantum.h"

#define TD_ACTION_GAMING ACTION_TAP_DANCE_FN_ADVANCED_WITH_RELEASE(td_gaming_tap, td_gaming_release, td_gaming_finished, td_gaming_reset)

void td_gaming_tap(tap_dance_state_t* state, void* user_data);
void td_gaming_release(tap_dance_state_t* state, void* user_data);
void td_gaming_finished(tap_dance_state_t *state, void *user_data);
void td_gaming_reset(tap_dance_state_t *state, void *user_data);

#endif // QMK_FIRMWARE_TAP_DANCE_GAMING_LAYER_H
