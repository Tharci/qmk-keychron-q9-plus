#include "quantum.h"
#include "common.h"


void rgb_matrix_caps(void) {
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
