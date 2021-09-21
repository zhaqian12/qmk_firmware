#include "alttabmarco.h"

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void matrix_scan_kb(void) {
	if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1000) {
            unregister_code16(KC_LALT);
            is_alt_tab_active = false;
        }
    }
    return matrix_scan_user();
}

void alt_tab_reverse(void) {
    if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code16(KC_LALT);
    }
    alt_tab_timer = timer_read();
    tap_code16(S(KC_TAB));

}

void alt_tab_forward(void) {
	if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code16(KC_LALT);
    }
    alt_tab_timer = timer_read();
    tap_code16(KC_TAB);
}
