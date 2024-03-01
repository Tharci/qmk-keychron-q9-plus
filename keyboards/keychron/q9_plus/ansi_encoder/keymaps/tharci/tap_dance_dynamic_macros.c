#include "tap_dance_dynamic_macros.h"
#include "quantum.h"
#include "extra/dynamic_macro_helper.h"


void td_macro_1(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        dyn_macro_play(1);
    } else if (state->count == 2) {
        dyn_macro_toggle(1);

    }
}


void td_macro_2(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        dyn_macro_play(2);
    } else if (state->count == 2) {
        dyn_macro_toggle(2);
    }
}

