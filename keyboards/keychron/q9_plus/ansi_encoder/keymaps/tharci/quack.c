#include "quack.h"
#include "extra_keycodes_user.h"


bool process_record_quack(uint16_t keycode, keyrecord_t* record) {
    if (keycode == KC_DUCK && record->event.pressed) {
        tap_code16(LSFT(LCTL(LALT(KC_Q))));
        return false;
    }

    return true;
}
