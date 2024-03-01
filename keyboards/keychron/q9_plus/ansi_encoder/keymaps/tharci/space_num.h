//
// Created by tharci on 5/31/24.
//

#ifndef QMK_FIRMWARE_SPACE_NUM_H
#define QMK_FIRMWARE_SPACE_NUM_H

#ifndef SPACE_NUM_IDLE_TIMEOUT
#    define SPACE_NUM_IDLE_TIMEOUT 3000
#endif

void space_num_reset_idle_timer(void);
void space_num_on(void);
void space_num_off(void);
void space_num_toggle(void);
void housekeeping_task_space_num(void);
bool space_num_is_on(void);
void rgb_matrix_space_num(void);
void process_space_num(uint16_t keycode, keyrecord_t* record);

#endif // QMK_FIRMWARE_SPACE_NUM_H
