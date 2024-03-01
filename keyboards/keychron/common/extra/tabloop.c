#include "extra_keycodes.h"
#include "quantum.h"


bool process_record_tabloop(uint16_t keycode, keyrecord_t* record) {
    if (keycode != KC_TABLOOP) return true;

    if (record->event.pressed) {
        register_code16(KC_LALT);
        register_code16(KC_TAB);
    } else {
        unregister_code16(KC_TAB);
    }

    return false;
}
