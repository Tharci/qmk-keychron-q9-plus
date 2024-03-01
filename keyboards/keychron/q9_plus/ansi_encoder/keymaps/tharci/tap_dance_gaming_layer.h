//
// Created by tharci on 5/31/24.
//

#ifndef QMK_FIRMWARE_TAP_DANCE_GAMING_LAYER_H
#define QMK_FIRMWARE_TAP_DANCE_GAMING_LAYER_H

#include "quantum.h"

void td_gaming_each(tap_dance_state_t* state, void* user_data);
void td_gaming_finished(tap_dance_state_t *state, void *user_data);
void td_gaming_reset(tap_dance_state_t *state, void *user_data);

#endif // QMK_FIRMWARE_TAP_DANCE_GAMING_LAYER_H
