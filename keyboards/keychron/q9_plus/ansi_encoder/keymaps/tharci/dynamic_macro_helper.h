//
// Created by tharci on 1/23/24.
//

#ifndef QMK_FIRMWARE_DYNAMIC_MACRO_HELPER_H
#define QMK_FIRMWARE_DYNAMIC_MACRO_HELPER_H

#include QMK_KEYBOARD_H

#include "keycodes.h"

typedef struct {
    uint16_t recording;
} dyn_macro_t;

void dyn_macro_play(uint8_t keycode);
void dyn_macro_toggle(uint8_t keycode);
void dyn_macro_reset(void);

#endif // QMK_FIRMWARE_DYNAMIC_MACRO_HELPER_H
