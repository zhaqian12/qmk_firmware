#include "zq60.h"

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {  //
{
    {1, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    {0, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
},{
    {10, 10},{12, 60},{12, 10}, {200, 10}, {200, 60},
},{
    4, 4, 4, 4, 4,
}};



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

void rgb_matrix_indicators_kb(void) {
// COLOR RED RGB VALUE
    HSV hsv = rgb_matrix_config.hsv;
    hsv.h = 0;
    hsv.s = 255;
    hsv.h = 200;
    RGB rgb = hsv_to_rgb(hsv);
// caps_lock indicator
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(0, rgb.r, rgb.g, rgb.b);
    } else {
        rgb_matrix_set_color(0, 0x00, 0x00, 0x00);
    }
}

#endif
