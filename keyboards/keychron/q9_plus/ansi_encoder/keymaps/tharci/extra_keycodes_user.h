//
// Created by tharci on 5/31/24.
//

#ifndef QMK_FIRMWARE_EXTRA_KEYCODES_USER_H
#define QMK_FIRMWARE_EXTRA_KEYCODES_USER_H

#include "extra/extra_keycodes.h"

enum extra_keycodes_user {
    KC_QUACK = KC_EXTRA_SAFE_RANGE,
};

#define KC_GOTO_DEF LCTL(KC_F6)
#define KC_PEEK_DEF LCTL(KC_F7)
#define KC_REVEAL_FILE LCTL(KC_F8)
#define KC_PREV_PROBLEM LCTL(KC_F10)
#define KC_NEXT_PROBLEM LCTL(KC_F11)
#define KC_REFACTOR LCTL(KC_F1)
#define KC_FORMAT LCTL(KC_F12)

#endif // QMK_FIRMWARE_EXTRA_KEYCODES_USER_H
