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

#include "quantum.h"
#include <caps_word.h>
#include QMK_KEYBOARD_H
#include "keychron_common.h"


// TODO: try to fix this
// only needed for intellisense to work
#ifndef MATRIX_COLS
#    define MATRIX_COLS 15
#endif // MATRIX_COLS

#ifndef MATRIX_ROWS
#    define MATRIX_ROWS 4
#endif // MATRIX_ROWS

#ifndef ENCODERS_PAD_A
#    define ENCODERS_PAD_A { B4 }
#endif // ENCODERS_PAD_A

#ifndef ENCODERS_PAD_B
#    define ENCODERS_PAD_B { B5 }
#endif // ENCODERS_PAD_B


enum layers {
    LY_BASE,
    LY_FNC,
    LY_FNC_SH,
    LY_GAMING,
    LY_FN_GAMING,
    LY_GAMING_NUMPAD,
    LY_FN_SPACE,
    LY_FN1,
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

bool gaming = false;

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
            if (host_keyboard_led_state().caps_lock) {
                tap_code(KC_CAPS);
            }
            else {
                caps_word_toggle();
            }
            break;

        case TD_SINGLE_HOLD:
            if (gaming) {
                layer_on(LY_FN_GAMING);
            }
            else {
                layer_on(LY_FNC);
            }
            break;

        case TD_DOUBLE_TAP:
            tap_code(KC_CAPS);
            caps_word_off();
            break;

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
    layer_off(LY_FN_GAMING);

    caps_layers_tap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
   [TD_CAPS_LAYERS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_caps_layers_finished, td_caps_layers_reset),
};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LY_BASE] = LAYOUT_54_ansi(
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,     KC_RBRC,  KC_BSPC,          KC_HOME,
        TD(TD_CAPS_LAYERS), KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,               KC_ENT,           LALT(KC_Q),
        SC_LSPO,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,               SC_RSPC, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,  MO(LY_FN_GAMING),      KC_SPC,                    MO(LY_FN_SPACE),           KC_RALT,  MO(LY_FN1), _______,  KC_LEFT, KC_DOWN, KC_RGHT),

    [LY_FNC] = LAYOUT_54_ansi(
        KC_ESC,   _______,  KC_CUT, KC_COPY, KC_PASTE, KC_SELECT, _______, KC_MS_BTN4, KC_UP, KC_MS_BTN5, _______,  KC_HOME,     KC_END,  KC_DEL,          KC_END,
        _______,  _______,  KC_SAVE,  KC_UNDO, KC_REDO, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP,  KC_PGDN,               _______,          _______,
        _______,            _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,               _______, _______,
        _______, _______,  _______,  KC_LCTL,          KC_TABLOOP,                   _______,          _______,  _______,     _______,  _______, _______, _______),

    [LY_FNC_SH] = LAYOUT_54_ansi(
        _______,   _______,  _______, _______, _______, _______, _______, _______, LSFT(KC_UP), _______, _______,  LSFT(KC_HOME), LSFT(KC_END),  _______,          _______,
        _______,  _______,  _______,  _______, _______, _______, _______, LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_RGHT), _______,  _______,               _______,          _______,
        _______,            _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,               _______, _______,
        _______, _______,  _______,  _______,          _______,                   _______,          _______,  _______,     _______,  _______, _______, _______),

    [LY_GAMING] = LAYOUT_54_ansi(
        _______,   _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,          RGB_TOG,
        _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,               _______,          _______,
        KC_LSFT,            _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,               KC_RSFT, _______,
        _______, _______,  _______,  _______,          _______,                   _______,          _______,  _______,     _______,  _______, _______, _______),

    [LY_FN_GAMING] = LAYOUT_54_ansi(
        KC_ESC, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,      KC_F12,   _______,          _______,
        _______,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     _______,               _______,          _______,
        _______,            _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,               _______, _______,
        _______, _______,  _______,  KC_LCTL,          KC_TABLOOP,                   _______,          _______,  _______,     _______,  _______, _______, _______),

    [LY_GAMING_NUMPAD] = LAYOUT_54_ansi(
        _______,   _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,          _______,
        _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,               _______,          _______,
        _______,            _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,               _______, KC_KP_8,
        _______, _______,  _______,  _______,          _______,                   _______,          _______,  _______,     _______,  KC_KP_4, KC_KP_5, KC_KP_6),

    [LY_FN_SPACE] = LAYOUT_54_ansi(
        KC_GRV, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,      KC_F12,   KC_BSLS,          KC_MUTE,
        _______,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,               KC_EQL,          _______,
        _______,           _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,               _______, _______,
        _______, _______,  _______,  _______,          _______,                   _______,          _______,  _______,     _______,  _______, _______, _______),

    [LY_FN1] = LAYOUT_54_ansi(
        _______, KC_VOLU, KC_MNXT, KC_BRIU, RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______,  _______,     _______,  _______,          RGB_TOG,
        _______, KC_VOLD, KC_MPRV, KC_BRID, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______,  _______,               _______,          _______,
        _______,           KC_MUTE, KC_MPLY, KC_CALC, _______, _______,  _______, _______, _______, _______,  _______,               _______, TG(LY_GAMING_NUMPAD),
        _______, _______,  _______,  _______,          _______,                   _______,          _______,  _______,     _______,  RGB_MODE_XMAS, RGB_MODE_KNIGHT, RGB_MODE_SNAKE),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LY_BASE] = {ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
    [LY_FNC]  = {ENCODER_CCW_CW(KC_UP, KC_DOWN)},
    [LY_GAMING]  = {ENCODER_CCW_CW(_______, _______)},
    [LY_FN_GAMING]  = {ENCODER_CCW_CW(RGB_RMOD, RGB_MOD)},
    [LY_FN_SPACE]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LY_FN1]      = {ENCODER_CCW_CW(RGB_RMOD, RGB_MOD)}
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
    gaming = !active;

    if (gaming) {
        layer_on(LY_GAMING);
    }
    else {
        layer_off(LY_GAMING);
    }

    return false;
}
#endif


void led_set_user(uint8_t led_state) {
    // Keep num lock turned on for layer
    if (IS_LAYER_ON(LY_GAMING_NUMPAD) && !(led_state & (1<<HID_KEYBOARD_LED_NUMLOCK))) {
        tap_code(KC_LNUM);
    }
}


void update_caps_led(void) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, RGB_RED);
    }
    else if (is_caps_word_on()) {
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, RGB_WHITE);
    }
    else {
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, RGB_BLACK);
    }
}


#if defined(RGB_MATRIX_ENABLE)

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    int numpad_keys[] = {40, 50, 51, 52};

    update_caps_led();

    if (IS_LAYER_ON(LY_GAMING_NUMPAD)) {
        for (int i = 0; i < sizeof(numpad_keys) / sizeof(numpad_keys[0]); i++) {
            rgb_matrix_set_color(numpad_keys[i], RGB_WHITE);
        }
    }
    else {
        for (int i = 0; i < sizeof(numpad_keys) / sizeof(numpad_keys[0]); i++) {
            rgb_matrix_set_color(numpad_keys[i], RGB_BLACK);
        }
    }

    return true;
}

#endif


void caps_word_set_user(bool active) {
    update_caps_led();
}


bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case MO(LY_FN_SPACE):
        case TD(TD_CAPS_LAYERS):
        case SC_LSPO:
        case KC_LSFT:
        case KC_MINS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

