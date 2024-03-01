//
// Created by tharci on 5/30/24.
//

#ifndef QMK_FIRMWARE_KNOB_H
#define QMK_FIRMWARE_KNOB_H

#include "keychron_common.h"

typedef enum {
    KNOB_VOLUME,
    KNOB_MEDIA,
    KNOB_BRIG,
    KNOB_RGB_MODE,
    KNOB_RGB_BRIG,
    KNOB_RGB_COLOR,
    KNOB_RGB_SAT,
    KNOB_SPEED,
    KNOB_NAV_HOR,
    KNOB_NAV_VER,
} knob_mode_t;

#define KC_IS_KNOB_MODE(x) ((x > KC_KNOB_PRESS) && (x <= KC_KNOB_SPEED))

void knob_turn_left(void);
void knob_turn_right(void);
void knob_press(void);
void set_knob_mode(knob_mode_t knob_mode);
bool process_record_knob(uint16_t keycode, keyrecord_t* record);

#endif // QMK_FIRMWARE_KNOB_H
