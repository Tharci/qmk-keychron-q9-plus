//
// Created by tharci on 10/3/24.
//

#ifndef QUACK_H
#define QUACK_H

#include "keychron_common.h"

bool process_record_quack(uint16_t keycode, keyrecord_t* record);
bool rgb_matrix_quack(uint8_t led_min, uint8_t led_max);

#endif //QUACK_H
