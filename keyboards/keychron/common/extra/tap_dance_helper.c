#include "quantum.h"
#include "tap_dance_helper.h"


td_state_t td_cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->pressed)
            return TD_SINGLE_HOLD;
        else
            return TD_SINGLE_TAP;
    } else if (state->count == 2) {
        if (state->pressed)
            return TD_DOUBLE_HOLD;
        else
            return TD_DOUBLE_TAP;
    } else if (state->count == 3) {
        if (state->pressed)
            return TD_TRIPLE_HOLD;
        else
            return TD_TRIPLE_TAP;
    } else {
        return TD_UNKNOWN;
    }
}
