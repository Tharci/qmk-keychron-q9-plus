#include "tap_dance_gaming_layer.h"
#include "layers.h"
#include "extra/tap_dance_helper.h"
#include "quantum.h"
#include <process_dynamic_macro.h>


static td_tap_t gaming_tap_state = TD_INIT_STATE;


void td_gaming_each(tap_dance_state_t* state, void* user_data) {}


void td_gaming_finished(tap_dance_state_t *state, void *user_data) {
    gaming_tap_state.state = td_cur_dance(state);

    switch (gaming_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_DELETE);
            break;

        case TD_SINGLE_HOLD:
            layer_on(LY_FN_GAMING);
            break;

        default:
            break;
    }
}


void td_gaming_reset(tap_dance_state_t *state, void *user_data) {
    layer_off(LY_FN_GAMING);
    gaming_tap_state.state = TD_NONE;
}