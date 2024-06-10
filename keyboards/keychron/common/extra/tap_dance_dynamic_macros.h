//
// Created by tharci on 5/31/24.
//

#ifndef QMK_FIRMWARE_TAP_DANCE_DYNAMIC_MACROS_H
#define QMK_FIRMWARE_TAP_DANCE_DYNAMIC_MACROS_H

#include "quantum.h"

#define TD_ACTION_MACRO_1 ACTION_TAP_DANCE_FN(td_macro_1)
#define TD_ACTION_MACRO_2 ACTION_TAP_DANCE_FN(td_macro_2)

void td_macro_1(tap_dance_state_t *state, void *user_data);
void td_macro_2(tap_dance_state_t *state, void *user_data);

#endif // QMK_FIRMWARE_TAP_DANCE_DYNAMIC_MACROS_H
