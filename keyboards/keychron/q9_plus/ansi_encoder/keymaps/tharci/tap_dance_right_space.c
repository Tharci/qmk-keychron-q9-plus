#include "tap_dance_right_space.h"
#include "layers.h"
#include "extra/knob.h"
#include "extra/tap_dance_helper.h"
#include "quantum.h"
#include <process_dynamic_macro.h>
#include "space_num.h"


static td_tap_t right_space_tap_state = TD_INIT_STATE;


void td_right_space_finished(tap_dance_state_t *state, void *user_data) {
    right_space_tap_state.state = td_cur_dance(state);

    switch (right_space_tap_state.state) {
        case TD_SINGLE_TAP:
            space_num_toggle();
            break;

        case TD_SINGLE_HOLD:
            space_num_off();
            layer_on(LY_FN_SPACE);
            set_knob_mode(KNOB_VOLUME);
            break;

        default:
            break;
    }
}


void td_right_space_reset(tap_dance_state_t *state, void *user_data) {
    if (right_space_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(LY_FN_SPACE);
        set_knob_mode(KNOB_NAV_HOR);
    }

    right_space_tap_state.state = TD_NONE;
}