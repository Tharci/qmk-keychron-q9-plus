#include "quack.h"
#include "extra_keycodes_user.h"
#include "quantum.h"
#include "math.h"  // For sqrt

// State variables
static uint8_t led_brg = 0;
static uint16_t circle_radius = 0; // Current radius of the circle
static const uint8_t led_speed = 1;  // Speed of the fade-out
static const uint8_t circle_speed = 2;  // Speed of the circle expansion

// Helper function to calculate the distance between two LEDs
static uint8_t calculate_distance(uint8_t led_index, uint8_t center_led, uint8_t scale) {
    int16_t dx = g_led_config.point[led_index].x - g_led_config.point[center_led].x;
    int16_t dy = g_led_config.point[led_index].y - g_led_config.point[center_led].y;
    return sqrt(dx * dx * scale * scale + dy * dy * scale * scale);  // Calculate Euclidean distance
}

bool rgb_matrix_quack(uint8_t led_min, uint8_t led_max) {
    if (led_brg == 0) {
        return false;
    }

    // Loop through all LEDs and set color based on distance from the circle
    for (uint8_t i = led_min; i < led_max; i++) {
        const uint8_t circle_radius_scale = 200;
        int16_t distance = abs((int16_t) calculate_distance(i, DUCK_LED_INDEX, circle_radius_scale) - (int16_t)(circle_radius));
        uint8_t brg_decrease = distance / circle_radius_scale * 5;
        uint8_t brightness = led_brg > brg_decrease ? led_brg - brg_decrease : 0;
        if (brightness > 0) {
            RGB color = hsv_to_rgb_nocie((HSV){35, 255, led_brg});
            rgb_matrix_set_color(i, color.r, color.g, color.b);
        }
    }

    // Fade out the brightness
    if (led_brg > led_speed) {
        led_brg -= led_speed;
    } else {
        led_brg = 0;
    }

    circle_radius += circle_speed;

    return false;
}

bool process_record_quack(uint16_t keycode, keyrecord_t* record) {
    if (keycode == KC_DUCK && record->event.pressed) {
        tap_code16(LSFT(LCTL(LALT(KC_Q))));
        led_brg = 255;  // Set initial brightness
        circle_radius = 0;  // Start circle with radius 0
        return false;
    }
    return true;
}
