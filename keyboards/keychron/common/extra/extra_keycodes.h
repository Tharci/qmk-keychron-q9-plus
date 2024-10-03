//
// Created by tharci on 5/31/24.
//

#ifndef QMK_FIRMWARE_EXTRA_KEYCODES_H
#define QMK_FIRMWARE_EXTRA_KEYCODES_H

#include "keychron_common.h"

enum extra_keycodes {
    /*** knob key presses ***/
    KC_KNOB_LEFT = KEYCHRON_SAFE_RANGE,
    KC_KNOB_RIGHT,
    KC_KNOB_PRESS,

    /*** knob modes ***/
    KC_KNOB_VOLUME,
    KC_KNOB_MEDIA,
    KC_KNOB_BRIG,
    KC_KNOB_RGB_MODE,
    KC_KNOB_RGB_BRIG,
    KC_KNOB_RGB_COLOR,
    KC_KNOB_RGB_SAT,
    KC_KNOB_SPEED,

    /*** tabloop ***/
    KC_TABLOOP,

    /*** safe range ***/
    KC_EXTRA_SAFE_RANGE,
};

#endif // QMK_FIRMWARE_EXTRA_KEYCODES_H
