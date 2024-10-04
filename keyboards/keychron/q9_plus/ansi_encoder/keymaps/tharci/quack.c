#include "quack.h"
#include "extra_keycodes_user.h"
#include "quantum.h"


/*
Play an effect on the duck key whenever it is pressed.
They key lights up an slowly fades out.
*/

// state variables
static uint8_t led_brg = 0;
static const uint8_t led_speed = 2;

bool rgb_matrix_quack(uint8_t led_min, uint8_t led_max) {
    if (led_brg == 0) {
        return false;
    }

    // fade out
    if (led_brg > led_speed) {
        led_brg -= led_speed;
    } else {
        led_brg = 0;
    }


    // set color of key: DUCK_LED_INDEX
    // it should be yellow and have led_brg brightness
    RGB color = hsv_to_rgb_nocie((HSV){50, 255, led_brg});
    rgb_matrix_set_color(DUCK_LED_INDEX, color.r, color.g, color.b);
    return false;
}




bool process_record_quack(uint16_t keycode, keyrecord_t* record) {
    if (keycode == KC_DUCK && record->event.pressed) {
        tap_code16(LSFT(LCTL(LALT(KC_Q))));
        led_brg = 255;
        return false;
    }

    return true;
}
