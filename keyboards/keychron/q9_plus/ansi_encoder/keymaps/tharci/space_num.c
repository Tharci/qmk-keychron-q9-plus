#include "quantum.h"
#include "layers.h"
#include "space_num.h"
#include "tap_dance.h"


static bool     is_space_num_on      = false;
static uint16_t space_num_idle_timer = 0;


bool space_num_is_on(void) {
    return is_space_num_on;
}


void space_num_reset_idle_timer(void) {
    space_num_idle_timer = timer_read() + SPACE_NUM_IDLE_TIMEOUT;
}


void space_num_on(void) {
    is_space_num_on = true;
    layer_on(LY_SPACE_NUM);

#if SPACE_NUM_IDLE_TIMEOUT > 0
    space_num_reset_idle_timer();
#endif
}


void space_num_off(void) {
    is_space_num_on = false;
    layer_off(LY_SPACE_NUM);
}


void space_num_toggle(void) {
    if (is_space_num_on) {
        space_num_off();
    } else {
        space_num_on();
    }
}


void housekeeping_task_space_num(void) {
    if (is_space_num_on && timer_expired(timer_read(), space_num_idle_timer)) {
        space_num_off();
    }
}


void rgb_matrix_space_num(void) {
    if (space_num_is_on()) {
        rgb_matrix_set_color(46, RGB_WHITE);
    }
}


void process_space_num(uint16_t keycode, keyrecord_t* record) {
    space_num_reset_idle_timer();

    switch (keycode) {
        // Keycodes that continue Space Num
        case KC_1 ... KC_0:
        case KC_COMMA:
        case KC_DOT:
        case KC_BSPC:
        case MO(LY_FN_SPACE):
        // this is a bit of a workaround, so that the toggle won't turn it back on
        case TD(TD_RIGHT_SPACE):
            return;

        // Deactivate Space Num
        default:
            space_num_off();
            return;
    }
}
