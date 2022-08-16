#include "version.h"
#include "signalrgb.h"

#ifndef SIGNALRGB_STARTUP_HSV
#    define SIGNALRGB_STARTUP_HSV { 0, 0, 200 }
#endif

RGB signalrgb_colors[DRIVER_LED_TOTAL] = {[0 ... DRIVER_LED_TOTAL - 1] = SIGNALRGB_STARTUP_HSV};

void signal_rgb_command_handler(uint8_t *data, uint8_t length) {
    uint8_t *command_id   = &(data[1]);
    uint8_t *command_data = &(data[2]);

    switch (*command_id) {
        case id_signalrgb_get_protocol_version: {
            signalrgb_get_protocol_version(command_data);
            break;
        }
        case id_signalrgb_get_qmk_version: {
            signalrgb_get_qmk_version(command_data);
            break;
        }
        case id_signalrgb_set_leds: {
            signalrgb_set_leds(command_data);
            break;
        }
        case id_signalrgb_set_effect: {
            signalrgb_set_effect(command_data);
            break;
        }
        default: {
            data[0] = id_unhandled;
            break;
        }
    }
}

void signalrgb_get_protocol_version(uint8_t *data) {
    data[0] = SIGNALRGB_PROTOCOL_VERSION;
}

void signalrgb_get_qmk_version(uint8_t *data) {
    uint8_t i = 0;
    for (i = 0; ((i < 30) && (QMK_VERSION[i] != 0)); i++) {
        data[i + 1] = QMK_VERSION[i];
    }
    data[0] = i;
}

void signalrgb_set_leds(uint8_t *data) {
    uint8_t first_led_index = data[0];
    uint8_t leds_num        = data[1];

    if (leds_num >= 9) {
        data[0] = DEVICE_ERROR_LEDS;
        return;
    }
    uint8_t led_index   = first_led_index;
    uint8_t color_index = 2;
    for (uint8_t i = 0; i < leds_num; ++i, ++led_index, color_index += 3) {
        signalrgb_colors[led_index].r = data[color_index];
        signalrgb_colors[led_index].g = data[color_index + 1];
        signalrgb_colors[led_index].b = data[color_index + 2];
    }
}

void signalrgb_set_effect(uint8_t *data) {
    uint8_t enabled = data[0];
    if (enabled) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SIGNALRGB);
    } else {
        rgb_matrix_reload_from_eeprom();
    }
}
