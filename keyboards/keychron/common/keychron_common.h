/* Copyright 2022 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef QMK_FIRMWARE_KEYCHRON_COMMON_H
#define QMK_FIRMWARE_KEYCHRON_COMMON_H

#include "quantum.h"

#ifdef VIA_ENABLE
#    include "via.h"
#endif

#define KC_MICT QK_KB_0
#define KC_LAPA QK_KB_1

#include "quantum_keycodes.h"

enum custom_keycodes {
    KC_LOPTN = QK_KB_2, // TECH DEBT: Starts at QK_KB_2 to maintain ordering with VIA definitions. See #19884. Revert to QK_KB_0 when VIA catches up with QMK.
    KC_ROPTN,
    KC_LCMMD,
    KC_RCMMD,
    KC_SIRI,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER,
    KC_SCREEN_SHOT,
    KC_CORTANA,
    KEYCHRON_SAFE_RANGE
};

#define KC_TASK KC_TASK_VIEW
#define KC_FLXP KC_FILE_EXPLORER
#define KC_SNAP KC_SCREEN_SHOT
#define KC_CRTA KC_CORTANA

typedef struct PACKED {
    uint8_t len;
    uint8_t keycode[3];
} key_combination_t;

void housekeeping_task_keychron(void);
bool process_record_keychron(uint16_t keycode, keyrecord_t *record);

#ifdef FACTORY_TEST_ENABLE
bool factory_test_rx(uint8_t *data, uint8_t length);
#endif

#endif //QMK_FIRMWARE_KEYCHRON_COMMON_H
