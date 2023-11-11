/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

#include QMK_KEYBOARD_H
#include "keychron_common.h"

enum layers {
    LY_BASE,
    LY_FNC,
    LY_FNC_SH,
    LY_FN1,
    LY_FN2,
};

enum custom_keys_tharci {
    KC_TABLOOP = KEYCHRON_SAFE_RANGE,
};

#define KC_SELECT LCTL(KC_A)
#define KC_CUT LCTL(KC_X)
#define KC_COPY LCTL(KC_C)
#define KC_PASTE LCTL(KC_V)
#define KC_SAVE LCTL(KC_S)
#define KC_UNDO LCTL(KC_Z)
#define KC_REDO LCTL(KC_Y)

// Tap Dance declarations
enum tap_dance {
    TD_CAPS_LAYERS,
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

static td_tap_t caps_layers_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};


td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->pressed) return TD_SINGLE_HOLD;
        else return TD_SINGLE_TAP;
    } else if (state->count == 2) {
        if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }
    else if (state->count == 3) {
        if (state->pressed) return TD_TRIPLE_HOLD;
        else return TD_TRIPLE_TAP;
    }
    else  {
        return TD_UNKNOWN;
    }
}

static void td_caps_layers_finished(tap_dance_state_t *state, void *user_data) {
    caps_layers_tap_state.state = cur_dance(state);

    switch (caps_layers_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_CAPS);
            break;

        case TD_SINGLE_HOLD:
            layer_on(LY_FNC);
            break;

        // case TD_DOUBLE_TAP:
        //     leader_start();
        //     break;

        case TD_DOUBLE_HOLD:
            layer_on(LY_FNC);
            layer_on(LY_FNC_SH);
            break;

        default:
            break;
    }
}

static void td_caps_layers_reset(tap_dance_state_t *state, void *user_data) {
    if (caps_layers_tap_state.state == TD_SINGLE_HOLD || caps_layers_tap_state.state == TD_DOUBLE_HOLD) {
        unregister_code(KC_LALT);
    }

    layer_off(LY_FNC);
    layer_off(LY_FNC_SH);

    caps_layers_tap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
   [TD_CAPS_LAYERS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_caps_layers_finished, td_caps_layers_reset),
};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LY_BASE] = LAYOUT_54_ansi(
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,     KC_RBRC,  KC_BSPC,          KC_HOME,
        TD(TD_CAPS_LAYERS), KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,               KC_ENT,           RGB_TOG,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,               KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,  MO(LY_FN1),      KC_SPC,                    MO(LY_FN1),           KC_RALT,  MO(LY_FN1), MO(LY_FN2),  KC_LEFT, KC_DOWN, KC_RGHT),

    [LY_FNC] = LAYOUT_54_ansi(
        KC_ESC,   _______,  KC_CUT, KC_COPY, KC_PASTE, KC_SELECT, _______, _______, KC_UP, _______, _______,  KC_HOME,     KC_END,  KC_DEL,          KC_END,
        _______,  _______,  KC_SAVE,  KC_UNDO, KC_REDO, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,  _______,               _______,          _______,
        _______,            _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,               _______, _______,
        _______, _______,  _______,  KC_LCTL,          KC_TABLOOP,                   _______,          _______,  _______,     _______,  _______, _______, _______),

    [LY_FNC_SH] = LAYOUT_54_ansi(
        _______,   _______,  _______, _______, _______, _______, _______, _______, LSFT(KC_UP), _______, _______,  LSFT(KC_HOME), LSFT(KC_END),  _______,          _______,
        _______,  _______,  _______,  _______, _______, _______, _______, LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_RGHT), _______,  _______,               _______,          _______,
        _______,            _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,               _______, _______,
        _______, _______,  _______,  _______,          _______,                   _______,          _______,  _______,     _______,  _______, _______, _______),

    [LY_FN1] = LAYOUT_54_ansi(
        KC_GRV, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,      KC_F12,   KC_BSLS,          KC_MUTE,
        _______,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,               KC_EQL,          _______,
        _______,           _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,               _______, _______,
        _______, _______,  _______,  _______,          _______,                   _______,          _______,  _______,     _______,  _______, _______, _______),

    [LY_FN2] = LAYOUT_54_ansi(
        _______, KC_VOLU, KC_MNXT, KC_BRIU, RGB_VAD,  _______, _______, _______, _______, _______, _______,  _______,     _______,  _______,          RGB_TOG,
        _______, KC_VOLD, KC_MPRV, KC_BRID, RGB_VAI,  _______, _______, _______, _______, _______, _______,  _______,               _______,          _______,
        _______,           KC_MUTE, KC_MPLY, KC_CALC, _______, _______,  _______, _______, _______, _______,  _______,               _______, _______,
        _______, _______,  _______,  _______,          _______,                   _______,          _______,  _______,     _______,  _______, _______, _______),

    //[LY_FN2] = LAYOUT_54_ansi(
    //    KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,     KC_VOLU,  _______,          RGB_TOG,
    //    RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,               _______,          _______,
    //    _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, NK_TOGG, _______, _______, _______,  _______,               _______, _______,
    //    _______, _______,  _______,  _______,          _______,                   _______,          _______,  _______,     _______,  _______, _______, _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LY_BASE] = {ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
    [LY_FNC]  = {ENCODER_CCW_CW(KC_UP, KC_DOWN)},
    [LY_FNC_SH]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    // [LY_GAMING_F1] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LY_FN1]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LY_FN2]      = {ENCODER_CCW_CW(RGB_RMOD, RGB_MOD)}
};
#endif


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_record_keychron(keycode, record)) {
        return false;
    }

    if (record->event.pressed) {
        switch (keycode) {
        case KC_TABLOOP:
            register_code(KC_LALT);
            register_code16(KC_TAB);
            return false;

        default:
            break;
        }
    }

    if (!record->event.pressed) {
        switch(keycode) {
        case KC_TABLOOP:
            unregister_code16(KC_TAB);
            return false;

        default:
            break;
        }
    }
    return true;
}

void housekeeping_task_user(void) {
    housekeeping_task_keychron();
}

#ifdef DIP_SWITCH_ENABLE
bool dip_switch_update_user(uint8_t index, bool active) {
    return false;
}
#endif

