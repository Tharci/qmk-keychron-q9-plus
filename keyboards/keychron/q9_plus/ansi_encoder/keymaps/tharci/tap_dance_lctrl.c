#include "tap_dance_lctrl.h"
#include "layers.h"
#include "extra/tap_dance_helper.h"
#include "quantum.h"
#include <process_dynamic_macro.h>


static td_tap_t td_tap_state = TD_INIT_STATE;


void td_lctrl_release(tap_dance_state_t* state, void* user_data) {
    if (!state->finished && !state->interrupted) {
        tap_code(KC_ENTER);
    }
}

void td_lctrl_tap(tap_dance_state_t* state, void* user_data) {}

void td_lctrl_finished(tap_dance_state_t *state, void *user_data) {
    td_tap_state.state = td_cur_dance(state);

    switch (td_tap_state.state) {
        case TD_SINGLE_HOLD:
            register_code(KC_LCTL);
            break;

        default:
            break;
    }
}


void td_lctrl_reset(tap_dance_state_t *state, void *user_data) {
    td_tap_state.state = TD_NONE;
    unregister_code(KC_LCTL);
}
