/* Copyright 2021 zhaiqian
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "ugrgbmatrixeffect.h"
#include <lib/lib8tion/lib8tion.h>

// define the center of rgb matrix
#ifndef RGB_MATRIX_CENTER
static const led_point_t m_rgb_matrix_center = {112, 32};
#else
static const led_point_t m_rgb_matrix_center = RGB_MATRIX_CENTER;
#endif

// a array of undefglow rgb matrix effects which are enabled
static const uint8_t ug_rgb_matrix_effect_index[] = {
// default effect synchronize with qmk rgb matrix effects
    0,
#ifdef UG_RGB_MATRIX_BREATHING
    1,
#endif

#ifdef UG_RGB_MATRIX_CYCLEBREATHING
    2,
#endif

#ifdef UG_RGB_MATRIX_CYCLEBANDVAL
    3,
#endif

#ifdef UG_RGB_MATRIX_CYCLEBANDPINWHEELVAL
    4,
#endif

#ifdef UG_RGB_MATRIX_CYCLEALL
    5,
#endif

#ifdef UG_RGB_MATRIX_CYCLELEFTRIGHT
    6,
#endif

#ifdef UG_RGB_MATRIX_CYCLEUPDOWN
    7,
#endif

#ifdef UG_RGB_MATRIX_CYCLEOUTIN
    8,
#endif

#ifdef UG_RGB_MATRIX_RAINBOWPINWHEEL
    9,
#endif

#ifdef UG_RGB_MATRIX_CYCLESPIRAL
    10,
#endif
};

// internal variables
// index of underglow rgb matrix effects
static uint8_t underglow_rgblight_fixed_status = 0;
// length of underglow rgb matrix effects which are enabled
static const uint8_t ug_rgb_matrix_effect_num = sizeof(ug_rgb_matrix_effect_index)/sizeof(uint8_t);

// underglow rgb matrix effects initialized by reading from eeprom
void underglow_rgb_matrix_init(void) {
    underglow_rgblight_fixed_status = eeprom_read_byte((void*)ZQ_EEPROM_ADDR + 4);
}

// underglow rgb matrix effects handling
void rgb_matrix_indicators_underglowrgbmatrix(void) {
    switch (ug_rgb_matrix_effect_index[underglow_rgblight_fixed_status]) {
#ifdef UG_RGB_MATRIX_BREATHING
        case 1: Breathing(); break;
#endif
#ifdef UG_RGB_MATRIX_CYCLEBREATHING
        case 2: CycleBreathing(); break;
#endif
#ifdef UG_RGB_MATRIX_CYCLEBANDVAL
        case 3: CycleBandVal(); break;
#endif
#ifdef UG_RGB_MATRIX_CYCLEBANDPINWHEELVAL
        case 4: CycleBandPinwheelVal(); break;
#endif
#ifdef UG_RGB_MATRIX_CYCLEALL
        case 5: CycleAll(); break;
#endif
#ifdef UG_RGB_MATRIX_CYCLELEFTRIGHT
        case 6: CycleLeftRight(); break;
#endif
#ifdef UG_RGB_MATRIX_CYCLEUPDOWN
        case 7: CycleUpDown(); break;
#endif
#ifdef UG_RGB_MATRIX_CYCLEOUTIN
        case 8: CycleOutIn(); break;
#endif
#ifdef UG_RGB_MATRIX_RAINBOWPINWHEEL
        case 9: RainbowPinwheel(); break;
#endif
#ifdef UG_RGB_MATRIX_CYCLESPIRAL
        case 10: CycleSpiral(); break;
#endif
        default: rgb_matrix_enable(); break;
    }
}

// modes of underglow rgb matrix effects step function
void underglow_rgb_mode_step(void) {
    if ((underglow_rgblight_fixed_status ++) >= ug_rgb_matrix_effect_num)
        underglow_rgblight_fixed_status = 0;
    eeprom_write_byte((void*)ZQ_EEPROM_ADDR + 4, underglow_rgblight_fixed_status);
}

#ifdef UG_RGB_MATRIX_BREATHING
void Breathing(void) {
    HSV      hsv  = rgb_matrix_config.hsv;
    uint16_t time = g_rgb_timer * (rgb_matrix_config.speed / 8) / 256;
    hsv.v         = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
    RGB rgb       = hsv_to_rgb(hsv);
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW) || HAS_FLAGS(g_led_config.flags[i], LED_FLAG_INDICATOR))
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
}
#endif

#ifdef UG_RGB_MATRIX_CYCLEBREATHING
static uint8_t is_breathing_highest = 1;
static uint8_t is_breathing_lowest = 1;
static uint8_t hue_index = 0;
static uint8_t val_index = 0;
static uint8_t hue_stepper = 0;

void CycleBreathing() {
    HSV      hsv  = rgb_matrix_config.hsv;
    uint16_t time = g_rgb_timer * (rgb_matrix_config.speed / 8) / 256;
    hsv.v         = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
    if (is_breathing_lowest){
        val_index = hsv.v;
        hue_index = hue_stepper;
        hue_stepper += 8;
        is_breathing_lowest ^= 1;
    } else {
        if (hsv.v >= val_index && is_breathing_highest) {
            is_breathing_highest ^= 1;
        } else {
            if (hsv.v <= 0 && !is_breathing_highest) {
                is_breathing_highest ^= 1;
                is_breathing_lowest  ^= 1;
            }
        }
    }
    hsv.h = hue_index;
    RGB rgb       = hsv_to_rgb(hsv);
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW) || HAS_FLAGS(g_led_config.flags[i], LED_FLAG_INDICATOR))
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
}
#endif

#ifdef UG_RGB_MATRIX_CYCLEBANDVAL
void CycleBandVal(void) {
    uint8_t time = g_rgb_timer * qadd8(rgb_matrix_config.speed / 4, 1) / 256;
     for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW) || HAS_FLAGS(g_led_config.flags[i], LED_FLAG_INDICATOR)) {
            HSV  hsv  = rgb_matrix_config.hsv;
            int16_t v = hsv.v - abs(scale8(g_led_config.point[i].x, 228) + 28 - time) * 8;
            hsv.v     = scale8(v < 0 ? 0 : v, hsv.v);
            hsv.h = time;
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
}
#endif

#ifdef UG_RGB_MATRIX_CYCLEBANDPINWHEELVAL
void CycleBandPinwheelVal(void) {
    uint8_t time = g_rgb_timer * (rgb_matrix_config.speed / 2) / 256;
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW) || HAS_FLAGS(g_led_config.flags[i], LED_FLAG_INDICATOR)) {
            HSV  hsv  = rgb_matrix_config.hsv;
            int16_t dx  = g_led_config.point[i].x - m_rgb_matrix_center.x;
            int16_t dy  = g_led_config.point[i].y - m_rgb_matrix_center.y;
	        hsv.h = time;
            hsv.v = scale8(hsv.v - time - atan2_8(dy, dx) * 3, hsv.v);
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
}
#endif

#ifdef UG_RGB_MATRIX_CYCLEALL
void CycleAll(void) {
    uint8_t time = g_rgb_timer * qadd8(rgb_matrix_config.speed / 4, 1) / 256;
    HSV  hsv  = rgb_matrix_config.hsv;
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW) || HAS_FLAGS(g_led_config.flags[i], LED_FLAG_INDICATOR)) {
	        hsv.h = time;
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
}
#endif

#ifdef UG_RGB_MATRIX_CYCLELEFTRIGHT
void CycleLeftRight(void) {
    uint8_t time = g_rgb_timer * qadd8(rgb_matrix_config.speed / 4, 1) / 256;
    HSV  hsv  = rgb_matrix_config.hsv;
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW) || HAS_FLAGS(g_led_config.flags[i], LED_FLAG_INDICATOR)) {
	        hsv.h = g_led_config.point[i].x - time;
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
}
#endif

#ifdef UG_RGB_MATRIX_CYCLEUPDOWN
void CycleUpDown(void) {
    uint8_t time = g_rgb_timer * qadd8(rgb_matrix_config.speed / 4, 1) / 256;
    HSV  hsv  = rgb_matrix_config.hsv;
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW) || HAS_FLAGS(g_led_config.flags[i], LED_FLAG_INDICATOR) ) {
	        hsv.h = g_led_config.point[i].y - time;
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
}
#endif

#ifdef UG_RGB_MATRIX_CYCLEOUTIN
void CycleOutIn(void) {
    uint8_t time = g_rgb_timer * (rgb_matrix_config.speed / 2) / 256;
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW) || HAS_FLAGS(g_led_config.flags[i], LED_FLAG_INDICATOR)) {
            int16_t dx   = g_led_config.point[i].x - m_rgb_matrix_center.x;
            int16_t dy   = g_led_config.point[i].y - m_rgb_matrix_center.y;
            uint8_t dist = sqrt16(dx * dx + dy * dy);
            HSV hsv = rgb_matrix_config.hsv;
            hsv.h = 3 * dist / 2 + time;
            RGB rgb  = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
}
#endif

#ifdef UG_RGB_MATRIX_RAINBOWPINWHEEL
void RainbowPinwheel(void) {
    uint16_t time =  g_rgb_timer * (rgb_matrix_config.speed / 4) / 256;
    int8_t   cos1  = cos8(time) - 128;
    int8_t   sin1  = sin8(time) - 128;
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW) || HAS_FLAGS(g_led_config.flags[i], LED_FLAG_INDICATOR)) {
            HSV hsv = rgb_matrix_config.hsv;
            hsv.h += ((g_led_config.point[i].y - m_rgb_matrix_center.y) * 3 * cos1 + (56 - abs8(g_led_config.point[i].x - m_rgb_matrix_center.x)) * 3 * sin1) / 128;
            RGB rgb  = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
}
#endif

#ifdef UG_RGB_MATRIX_CYCLESPIRAL
void CycleSpiral(void) {
    uint8_t time = g_rgb_timer * (rgb_matrix_config.speed / 2) / 256;
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW) || HAS_FLAGS(g_led_config.flags[i], LED_FLAG_INDICATOR)) {
            int16_t dx   = g_led_config.point[i].x - m_rgb_matrix_center.x;
            int16_t dy   = g_led_config.point[i].y - m_rgb_matrix_center.y;
            uint8_t dist = sqrt16(dx * dx + dy * dy);
            HSV hsv = rgb_matrix_config.hsv;
            hsv.h = dist - time - atan2(dy, dx);
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
}
#endif

