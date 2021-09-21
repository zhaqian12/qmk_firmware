#include "test12v1.h"

#ifdef ALT_TAB_MARCO_ENABLE
#include "zqlib/alttabmarco.h"
#endif

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {  //
    {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
    },{
        {0, 0}, {74, 0}, {148, 0}, {222, 0},
        {0, 32}, {74, 32}, {148, 32}, {222, 32},
        {0, 64}, {74, 64}, {148, 64}, {222, 64},
        {0, 64}, {224, 64}, {0, 0}, {224, 0},

    },{
        4, 4, 4, 4,
        4, 4, 4, 4,
        4, 4, 4, 4,
        2, 2, 2, 2,
    }};

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

#ifdef VIA_CUSTOM_KEYCODES_ENABLE

void rgb_matrix_indicators_kb(void) {
// COLOR RED RGB VALUE
    HSV hsv = rgb_matrix_config.hsv;
    hsv.h = 0;
    hsv.s = 255;
    RGB rgb = hsv_to_rgb(hsv);
// caps_lock indicator
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(5, rgb.r, rgb.g, rgb.b);
    } else {
        rgb_matrix_enable();
    }
}

#if defined ENCODER_ENABLE && defined ENCODER_TRIGGER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (clockwise) {
		encoder_trigger_kb(dynamic_keymap_get_keycode(biton32(layer_state), 1, 4), (keypos_t){.row = 1, .col = 4});
    } else {
		encoder_trigger_kb(dynamic_keymap_get_keycode(biton32(layer_state), 2, 4), (keypos_t){.row = 2, .col = 4});
	}
	return true;
}
#endif

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
#ifdef VIA_CUSTOM_KEYCODES_ENABLE
    switch(keycode) {
        case ATR:
            if (record->event.pressed) {
                alt_tab_reverse();
            }
            return false;
        case ATF:
            if (record->event.pressed) {
                alt_tab_forward();
            }
            return false;
#ifdef RGB_MATRIX_CONTROL_ENABLE
        case UGLRGBTog:
            if (record->event.pressed) {
                underglow_rgb_toggle();
            }
            return false;
        case KBLRGBTog:
            if (record->event.pressed) {
                key_backlight_rgb_toggle();
            }
            return false;
#endif
#ifdef UNDERGLOW_RGB_MATRIX_ENABLE
        case UGLFIXEDRGBMODF:
            if (record->event.pressed) {
               underglow_rgb_mode_step();
            }
            return false;
        case UGLFIXEDRGBMODR:
            if (record->event.pressed) {
               underglow_rgb_mode_step_reverse();
            }
            return false;
#endif
    }
#endif
    return process_record_user(keycode, record);
};
#endif

