//
// Created by tharci on 1/23/24.
//

#include QMK_KEYBOARD_H

#include "dynamic_macro_helper.h"

dyn_macro_t dyn_macro = {.recording = 0};

void dyn_macro_start(uint16_t keycode) {
    keyrecord_t kr;
    kr.event.pressed    = false;
    dyn_macro.recording = keycode;
    process_dynamic_macro(keycode, &kr);
}

void dyn_macro_stop(void) {
    keyrecord_t kr;
    dyn_macro.recording = 0;
    kr.event.pressed    = true;
    process_dynamic_macro(QK_DYNAMIC_MACRO_RECORD_STOP, &kr);
}

void dyn_macro_play(uint8_t macro) {
    if (macro != 1 && macro != 2) {
        return;
    }

    uint16_t macro_play_codes[] = {
        QK_DYNAMIC_MACRO_PLAY_1, QK_DYNAMIC_MACRO_PLAY_2
    };

    keyrecord_t kr;
    dyn_macro_stop();
    kr.event.pressed = false;
    process_dynamic_macro(macro_play_codes[macro-1], &kr);
}

void dyn_macro_toggle(uint8_t macro) {
    if (macro != 1 && macro != 2) {
        return;
    }

    if (dyn_macro.recording != 0) {
        dyn_macro_stop();
    } else {
        uint16_t macro_start_codes[] = {
            QK_DYNAMIC_MACRO_RECORD_START_1, QK_DYNAMIC_MACRO_RECORD_START_2
        };

        dyn_macro_start(macro_start_codes[macro-1]);
    }
}

void dyn_macro_reset(void) {
    if (dyn_macro.recording != 0) {
        dyn_macro_stop();
        dyn_macro_start(dyn_macro.recording);
        dyn_macro_stop();
    }
}
