#include "tap_dance_win.h"
#include "extra/tap_dance_helper.h"
#include "quantum.h"


static td_tap_t win_tap_state = TD_INIT_STATE;


void td_win_release(tap_dance_state_t* state, void* user_data) {
    if (!state->finished && !state->interrupted) {
        tap_code16(LWIN(KC_SPC));
    }
}

void td_win_tap(tap_dance_state_t* state, void* user_data) {}

void td_win_finished(tap_dance_state_t *state, void *user_data) {
    win_tap_state.state = td_cur_dance(state);

    switch (win_tap_state.state) {
        case TD_SINGLE_HOLD:
            register_code(KC_LWIN);
            break;

        default:
            break;
    }
}


void td_win_reset(tap_dance_state_t *state, void *user_data) {
    win_tap_state.state = TD_NONE;
    unregister_code(KC_LWIN);
}