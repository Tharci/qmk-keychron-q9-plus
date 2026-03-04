//
// Created by tharci on 3/4/26.
//

#ifndef TAP_DANCE_WIN_H
#define TAP_DANCE_WIN_H

#include "quantum.h"

#define TD_ACTION_WIN ACTION_TAP_DANCE_FN_ADVANCED_WITH_RELEASE(td_win_tap, td_win_release, td_win_finished, td_win_reset)

void td_win_tap(tap_dance_state_t* state, void* user_data);
void td_win_release(tap_dance_state_t* state, void* user_data);
void td_win_finished(tap_dance_state_t *state, void *user_data);
void td_win_reset(tap_dance_state_t *state, void *user_data);

#endif //TAP_DANCE_WIN_H
