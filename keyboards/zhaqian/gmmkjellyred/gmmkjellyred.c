#include "gmmkjellyred.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
    {
        {NO_LED,   NO_LED,   NO_LED,  NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,  NO_LED },
        {NO_LED,   NO_LED,   NO_LED,  NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,  NO_LED },
        {NO_LED,   NO_LED,   NO_LED,  NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,  NO_LED },
        {NO_LED,   NO_LED,   NO_LED,  NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,  NO_LED },
        {NO_LED,   NO_LED,   NO_LED,  NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,  NO_LED },
        {NO_LED,   NO_LED,   NO_LED,  NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED,  NO_LED }
    }, {
        {112, 63}, {112, 54}, {112, 45}, {112, 36}, {112, 27}, {112, 18}, {112, 9}, {112, 0},
        {112, 0}, {112, 9}, {112, 18}, {112, 27}, {112, 36}, {112, 45}, {112, 54}, {112, 63}
    }, {
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
    }
};

#endif

#ifdef RGB_DISABLE_WHEN_USB_SUSPENDED
void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}
#endif
