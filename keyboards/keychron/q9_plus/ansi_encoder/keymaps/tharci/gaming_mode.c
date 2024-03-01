#include "quantum.h"
#include "layers.h"
#include "gaming_mode.h"


bool gaming = false;


bool gaming_mode_is_on(void) {
    return gaming;
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



