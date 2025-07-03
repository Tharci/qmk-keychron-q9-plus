#ifndef QMK_FIRMWARE_COMMON_H
#define QMK_FIRMWARE_COMMON_H

#define KC_SELECT LCTL(KC_A)
#define KC_CUT LCTL(KC_X)
#define KC_COPY LCTL(KC_C)
#define KC_PASTE LCTL(KC_V)
#define KC_UNDO LCTL(KC_Z)
#define KC_SAVE LCTL(KC_S)
#define KC_REDO LCTL(KC_Y)
#define KC_COMMENT_OUT LCTL(KC_DOT)
#define KC_COPY_RAW LSFT(LCTL(KC_C))
#define KC_PASTE_RAW LSFT(LCTL(KC_V))

void rgb_matrix_caps(void);

#endif // QMK_FIRMWARE_COMMON_H
