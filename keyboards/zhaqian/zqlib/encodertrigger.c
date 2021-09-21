#include "encodertrigger.h"


__attribute__((weak)) void encoder_trigger_kb(uint16_t keycode, keypos_t keylocation) {
    if (keycode <= QK_MODS_MAX) {
        register_code16(keycode);
        wait_ms(10);
        unregister_code16(keycode);
    } else {
        action_exec((keyevent_t){.key = keylocation, .pressed = 1, .time = (timer_read() | 1)});
        wait_ms(10);
        action_exec((keyevent_t){.key = keylocation, .pressed = 0, .time = (timer_read() | 1)});
    }
}



