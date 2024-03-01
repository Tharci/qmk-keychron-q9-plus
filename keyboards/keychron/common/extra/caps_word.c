#include "quantum.h"
#include <info_config.h>
#include <process_dynamic_macro.h>
#include QMK_KEYBOARD_H
#include "common.h"
#include "caps_word.h"


__attribute__((weak)) bool caps_extra_key_is_allowed(uint16_t keycode) {
    return false;
}


void caps_word_set_user(bool active) {
    rgb_matrix_caps();
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
//            if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
//                return true;
//            }
//            else {
//                tap_code16(LSFT(keycode));
//                return false;
//            }

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_LSFT:
            return true;

        default:
            return caps_extra_key_is_allowed(keycode);  // Deactivate Caps Word.
    }
}
