#include "tap_dance_caps.h"
#include "layers.h"
#include "extra/knob.h"
#include "extra/tap_dance_helper.h"
#include "quantum.h"
#include "gaming_mode.h"


static td_tap_t caps_layers_tap_state = TD_INIT_STATE;


void td_caps_finished(tap_dance_state_t *state, void *user_data) {
    caps_layers_tap_state.state = td_cur_dance(state);

    switch (caps_layers_tap_state.state) {
        case TD_SINGLE_TAP:
            if (host_keyboard_led_state().caps_lock) {
                tap_code(KC_CAPS);
            } else {
                caps_word_toggle();
            }
            break;

        case TD_SINGLE_HOLD:
            set_knob_mode(KNOB_NAV_VER);
            if (gaming_mode_is_on()) {
                layer_on(LY_FN_GAMING);
            } else {
                layer_on(LY_FNC);
            }
            break;

        case TD_DOUBLE_TAP:
            tap_code(KC_CAPS);
            caps_word_off();
            break;

        case TD_DOUBLE_HOLD:
            layer_on(LY_FNC);
            layer_on(LY_FNC_SH);
            set_knob_mode(KNOB_NAV_VER);
            break;

        default:
            break;
    }
}


void td_caps_reset(tap_dance_state_t *state, void *user_data) {
    if (caps_layers_tap_state.state == TD_SINGLE_HOLD || caps_layers_tap_state.state == TD_DOUBLE_HOLD) {
        unregister_code(KC_LALT);
    }

    layer_off(LY_FNC);
    layer_off(LY_FNC_SH);
    layer_off(LY_FN_GAMING);
    set_knob_mode(KNOB_NAV_HOR);

    caps_layers_tap_state.state = TD_NONE;
}