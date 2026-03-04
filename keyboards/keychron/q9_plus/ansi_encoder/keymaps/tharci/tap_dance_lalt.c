#include "tap_dance_lalt.h"
#include "extra/tap_dance_helper.h"
#include "quantum.h"


static td_tap_t td_tap_state = TD_INIT_STATE;


void td_lalt_release(tap_dance_state_t* state, void* user_data) {
    if (!state->finished && !state->interrupted) {
        tap_code(KC_ENTER);
    }
}

void td_lalt_tap(tap_dance_state_t* state, void* user_data) {}

void td_lalt_finished(tap_dance_state_t *state, void *user_data) {
    td_tap_state.state = td_cur_dance(state);

    switch (td_tap_state.state) {
        case TD_SINGLE_HOLD:
            register_code(KC_LALT);
            break;

        default:
            break;
    }
}


void td_lalt_reset(tap_dance_state_t *state, void *user_data) {
    td_tap_state.state = TD_NONE;
    unregister_code(KC_LALT);
}
