#include "zq75.h"

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {  //
    {
        {14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
        {29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15},
        {44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30},
        {57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, NO_LED, NO_LED},
        {70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, NO_LED, NO_LED},
        {80, 79, NO_LED, 78, NO_LED, NO_LED, 77, NO_LED, 76, 75, 74, 73, 72, NO_LED, 71},
    },{
        {224, 0}, {208, 0}, {192,0}, {176, 0}, {160, 0}, {144, 0}, {128, 0}, {112, 0}, {96, 0}, {80, 0}, {64, 0}, {48, 0}, {32, 0}, {16, 0}, {0, 0},
        {224, 18}, {208, 18}, {192, 18}, {176, 18}, {160, 18}, {144, 18}, {128, 18}, {112, 18}, {96, 18}, {80, 18}, {64, 18}, {48, 18}, {32, 18}, {16, 18}, {0, 8},
        {224, 27}, {208, 27}, {192, 27}, {176, 27}, {160, 27}, {144, 27}, {128, 27}, {112, 27}, {96, 27}, {80, 27}, {64, 27}, {48, 27}, {32, 27}, {16, 27}, {0, 27},
        {192, 36}, {176, 36}, {160, 36}, {144, 36}, {128, 36}, {112, 36}, {96, 36}, {80, 36}, {64, 36}, {48, 36}, {32, 36}, {16, 36}, {0, 36},
        {208, 48}, {176, 51}, {160, 51}, {144, 51}, {128, 51}, {112, 51}, {96, 51}, {80, 51}, {64, 51}, {48, 51}, {32, 51}, {16, 51}, {0, 51},
        {224, 64}, {192, 64}, {176, 64}, {160, 64}, {144, 64}, {128, 64}, {96, 64}, {48, 64}, {16, 64}, {0, 64},
    },{
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        4, 4, 4, 1, 1, 1, 1, 1, 1, 1,
    }};

void rgb_matrix_indicators_kb(void) {
    // if (host_keyboard_led_state().caps_lock && host_keyboard_led_state().num_lock) {
    //     rgb_matrix_set_color(57, 200, 0, 0);
    //     rgb_matrix_set_color(30, 0, 200, 0);
    // } else if (host_keyboard_led_state().caps_lock) {  // Capslock = RED
    //     rgb_matrix_set_color(57, 200, 0, 0);
    // } else if (biton32(layer_state) == 1) {  // UPPER_LAYER = BLUE
    //     rgb_matrix_set_color(57, 0, 0, 200);
    // } else if (host_keyboard_led_state().num_lock) {
    //     rgb_matrix_set_color(30, 0, 200, 0);
    // } else {
    //     rgb_matrix_enable();
    // }
}


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
