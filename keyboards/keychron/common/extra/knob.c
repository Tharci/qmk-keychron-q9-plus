#include <process_rgb.h>
#include "quantum.h"
#include "knob.h"
#include "extra_keycodes.h"


const uint16_t knob_map[][3] = {
    [KNOB_VOLUME] = {KC_VOLD, KC_VOLU, KC_MUTE},
    [KNOB_MEDIA] = {KC_MPRV, KC_MNXT, KC_MEDIA_PLAY_PAUSE},
    [KNOB_BRIG] = {KC_BRID, KC_BRIU, KC_NO},
    [KNOB_RGB_MODE] = {RGB_RMOD, RGB_MOD, RGB_TOG},
    [KNOB_RGB_BRIG] = {RGB_VAD, RGB_VAI, KC_NO},
    [KNOB_RGB_COLOR] = {RGB_HUD, RGB_HUI, KC_NO},
    [KNOB_RGB_SAT] = {RGB_SAD, RGB_SAI, KC_NO},
    [KNOB_SPEED] = {RGB_SPD, RGB_SPI, KC_NO},
    [KNOB_NAV_HOR] = {KC_LEFT, KC_RIGHT, KC_HOME},
    [KNOB_NAV_VER] = {KC_UP, KC_DOWN, KC_END},
};


static knob_mode_t current_knob_mode = KNOB_NAV_HOR;


void set_knob_mode(knob_mode_t knob_mode) {
    current_knob_mode = knob_mode;
}


static keyrecord_t create_record(void) {
    return (keyrecord_t) {
        .event = MAKE_KEYEVENT(0, 0, false)
    };
}


/**
 * This is an awful workaround, but works.
 */
void tap_code_custom(uint16_t keycode) {
    keyrecord_t record = create_record();
    if (process_rgb(keycode, &record)) {
        tap_code16(keycode);
    }
}


void knob_turn_left(void) {
    tap_code_custom(knob_map[current_knob_mode][0]);
}


void knob_turn_right(void) {
    tap_code_custom(knob_map[current_knob_mode][1]);
}


void knob_press(void) {
    tap_code_custom(knob_map[current_knob_mode][2]);
}


bool process_record_knob(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case KC_KNOB_LEFT:
            if (record->event.pressed) knob_turn_left();
            return false;
        case KC_KNOB_RIGHT:
            if (record->event.pressed) knob_turn_right();
            return false;
        case KC_KNOB_PRESS:
            if (record->event.pressed) knob_press();
            return false;
        case KC_KNOB_VOLUME:
            if (record->event.pressed) set_knob_mode(KNOB_VOLUME);
            return false;
        case KC_KNOB_MEDIA:
            if (record->event.pressed) set_knob_mode(KNOB_MEDIA);
            return false;
        case KC_KNOB_BRIG:
            if (record->event.pressed) set_knob_mode(KNOB_BRIG);
            return false;
        case KC_KNOB_RGB_MODE:
            if (record->event.pressed) set_knob_mode(KNOB_RGB_MODE);
            return false;
        case KC_KNOB_RGB_BRIG:
            if (record->event.pressed) set_knob_mode(KNOB_RGB_BRIG);
            return false;
        case KC_KNOB_RGB_COLOR:
            if (record->event.pressed) set_knob_mode(KNOB_RGB_COLOR);
            return false;
        case KC_KNOB_RGB_SAT:
            if (record->event.pressed) set_knob_mode(KNOB_RGB_SAT);
            return false;
        case KC_KNOB_SPEED:
            if (record->event.pressed) set_knob_mode(KNOB_SPEED);
            return false;
        default:
            return true;
    }
}
