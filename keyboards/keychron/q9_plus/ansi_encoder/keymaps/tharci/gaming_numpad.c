#include "gaming_numpad.h"
#include "quantum.h"
#include "layers.h"


void led_set_gaming_numpad(uint8_t led_state) {
    // Keep num lock turned on for layer LY_GAMING_NUMPAD
    if (IS_LAYER_ON(LY_GAMING_NUMPAD) && !(led_state & (1<<HID_KEYBOARD_LED_NUMLOCK))) {
        tap_code(KC_LNUM);
    }
}


void rgb_matrix_gaming_numpad(void) {
    int numpad_keys[] = {40, 50, 51, 52};
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
}

