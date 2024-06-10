#define KEYMAP_SOURCE_FILE

#include "quantum.h"
#include <info_config.h>
#include QMK_KEYBOARD_H
#include "keychron_common.h"

#include "layers.h"
#include "space_num.h"
#include "tap_dance.h"
#include "gaming_numpad.h"

#include "extra/caps_word.h"
#include "extra/common.h"
#include "extra/knob.h"
#include "extra/tabloop.h"
#include "extra/extra_keycodes.h"


/**** Caps Word configuration ****/

bool caps_extra_key_is_allowed(uint16_t keycode) {
    static const uint16_t caps_word_allow_keys[] = {
        MO(LY_FN_SPACE),
        TD(TD_RIGHT_SPACE),
        TD(TD_CAPS),
        KC_UNDERSCORE,
        KC_MINUS,
        SC_LSPO
    };

    for (int i = 0; i < ARRAY_SIZE(caps_word_allow_keys); i++) {
        if (caps_word_allow_keys[i] == keycode) return true;
    }
    return false;
}

/**** ****/


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    process_space_num(keycode, record);

    if (!process_record_keychron(keycode, record)) {
        return false;
    }

    if (!process_record_tabloop(keycode, record)) {
        return false;
    }

    // put the knob back to the default state
    if (!record->event.pressed && KC_IS_KNOB_MODE(keycode) && keycode != KC_KNOB_VOLUME) {
        set_knob_mode(KNOB_VOLUME);
    }

    if (!process_record_knob(keycode, record)) {
        return false;
    }

    return true;
}


void housekeeping_task_user(void) {
    housekeeping_task_keychron();
    housekeeping_task_space_num();
}


#if defined(RGB_MATRIX_ENABLE)
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    rgb_matrix_caps();
    rgb_matrix_space_num();
    rgb_matrix_gaming_numpad();
    return true;
}
#endif


void led_set_user(uint8_t led_state) {
    led_set_gaming_numpad(led_state);
}


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[NUMBER_OF_LAYERS][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0 ... NUMBER_OF_LAYERS - 1] = {ENCODER_CCW_CW(KC_KNOB_LEFT, KC_KNOB_RIGHT)},
};
#endif


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LY_BASE] = LAYOUT_54_ansi(
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,     KC_RBRC,  KC_BSPC,          KC_KNOB_PRESS,
        TD(TD_CAPS), KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,               KC_ENT,           LALT(KC_Q),
        SC_LSPO,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,               SC_RSPC, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,  TD(TD_GAMING),      KC_SPC,                    TD(TD_RIGHT_SPACE),           KC_RALT,  MO(LY_FN1), MO(LY_FN2),  KC_LEFT, KC_DOWN, KC_RGHT),

    [LY_FNC] = LAYOUT_54_ansi(
        KC_ESC,   _______,  KC_CUT, KC_COPY, KC_PASTE, KC_SELECT, _______, KC_MS_BTN4, KC_UP, KC_MS_BTN5, _______,  KC_HOME,     KC_END,  KC_DEL,          _______,
        _______,  _______,  KC_SAVE,  KC_UNDO, KC_REDO, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP,  KC_PGDN,               _______,          _______,
        _______,            _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,               _______, _______,
        _______, _______,  _______,  KC_LCTL,          KC_TABLOOP,                   _______,          _______,  _______,     _______,  _______, _______, _______),

    [LY_FNC_SH] = LAYOUT_54_ansi(
        _______,   _______,  _______, _______, _______, _______, _______, _______, LSFT(KC_UP), _______, _______,  LSFT(KC_HOME), LSFT(KC_END),  _______,          _______,
        _______,  _______,  _______,  _______, _______, _______, _______, LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_RGHT), _______,  _______,               _______,          _______,
        _______,            _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,               _______, _______,
        _______, _______,  _______,  _______,          _______,                   _______,          _______,  _______,     _______,  _______, _______, _______),

    [LY_GAMING] = LAYOUT_54_ansi(
        _______,   _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,          _______,
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
        KC_GRV, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,      KC_F12,   KC_BSLS,          _______,
        _______,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,               KC_EQL,          _______,
        _______,           KC_KNOB_MEDIA,  KC_KNOB_BRIG, KC_KNOB_RGB_MODE, KC_KNOB_RGB_BRIG, KC_KNOB_RGB_COLOR, KC_KNOB_RGB_SAT, KC_KNOB_SPEED, _______, _______,  _______,               _______, _______,
        _______, _______,  _______,  _______,          _______,                   _______,          _______,  _______,     _______,  _______, _______, _______),

    [LY_FN1] = LAYOUT_54_ansi(
        _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,  _______,     _______,  _______,          _______,
        _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,  _______,               _______,          _______,
        _______,           _______, _______, KC_CALC, _______, _______,  _______, _______, _______, _______,  _______,               _______, TG(LY_GAMING_NUMPAD),
        _______, _______,  _______,  _______,          _______,                   _______,          _______,  _______,     _______,  _______, _______, _______),

    [LY_FN2] = LAYOUT_54_ansi(
        _______,   _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,          _______,
        _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,               _______,          _______,
        _______,            _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,               _______, _______,
        _______, _______,  _______,  _______,          _______,                   _______,          _______,  _______,     _______,  TD(TD_MACRO_1), QK_DYNAMIC_MACRO_RECORD_STOP, TD(TD_MACRO_2)),

    [LY_SPACE_NUM] = LAYOUT_54_ansi(
        _______,   _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,          _______,
        _______,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     _______,               _______,          _______,
        _______,            _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,               _______, _______,
        _______, _______,  _______,  _______,          _______,                   _______,          _______,  _______,     _______,  _______, _______, _______),
};
