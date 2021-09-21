#include "comb67.h"

#ifdef RGB_MATRIX_ENABLE

bool flag = false;
bool flag1 = false;
led_config_t g_led_config = {  
    {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14},
        {29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15},
        {30, NO_LED, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43},
        {NO_LED, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44},
        {58, 59, NO_LED, 60, NO_LED, NO_LED, 61, NO_LED, NO_LED, 62, 63, NO_LED, 64, 65, 66}
    },{
        {0, 0}, {16, 0}, {32, 0}, {48, 0}, {64, 0}, {80, 0}, {96, 0}, {112, 0}, {128, 0}, {144, 0}, {160, 0}, {176, 0}, {192, 0}, {208, 0}, {224, 0}, 
        {224, 16}, {208, 16}, {192, 16}, {176, 16}, {160, 16}, {144, 16}, {128, 16}, {112, 16}, {96, 16}, {80, 16}, {64, 16}, {48, 16}, {32, 16}, {16, 16}, {0, 16},
        {0, 32}, {32, 32}, {48, 32}, {64, 32}, {80, 32}, {96, 32}, {112, 32}, {128, 32}, {144, 32}, {160, 32}, {176, 32}, {192, 32}, {208, 32}, {224, 32}, 
        {224, 48}, {208, 48}, {192, 48}, {176, 48}, {160, 48}, {144, 48}, {128, 48}, {112, 48}, {96, 48}, {80, 48}, {64, 48}, {48, 48}, {32, 48}, {16, 48}, 
        {0, 64}, {16, 64}, {48, 64}, {96, 64}, {144, 64}, {160, 64}, {192, 64}, {208, 64}, {224, 64}, 
        {1, 10}, {20, 10}, {54, 10}, {100, 10}, {132,10}, {150, 10}, {182, 10}, {224, 10},
        {224, 60}, {182, 60}, {150, 60}, {132, 60}, {100, 60}, {54, 60}, {20, 60}, {1, 60} 
    },{
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 4, 
        4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 4, 
        4, 4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 
        1, 1, 1, 1, 1, 1, 4, 4, 4, 
        2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2
    }
};

void BLRGBToggle(void){
    if (flag1){
        flag1 = false;
    } else {
        flag1 = true;
    }
}

void UGRGBToggle(void){
    if (flag){
        flag = false;
    } else {
        flag = true;
    }
}

void rgb_matrix_indicators_kb(void) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(30, 200, 0, 0);
    } else {
        rgb_matrix_enable();
    }
    for (int i = 0; i < 67; i++) {
        if (flag)
             rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
        else
            rgb_matrix_enable();
    }
    for (int i = 67; i < 83; i++) {
        if (flag1)
             rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
        else
            rgb_matrix_enable();
    }
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


bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
#ifdef VIA_CUSTOM_KEYCODES
    switch(keycode) {
        case BLRGBTog:
            if (record->event.pressed) {
                BLRGBToggle();
            }
            return false;
        case UGRGBTog:
            if (record->event.pressed) {
                UGRGBToggle();
            }
            return false;
    }
#endif
    return process_record_user(keycode, record);
};