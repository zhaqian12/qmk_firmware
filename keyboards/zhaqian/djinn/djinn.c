/* Copyright 2021 Nick Brassel (@tzarc)
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

#include <string.h>
#include <quantum.h>
#include <hal_pal.h>

#include "djinn.h"
#include "serial.h"
#include "split_util.h"

#include "qp_ili9341.h"

painter_device_t lcd;

kb_runtime_config kb_state;
uint32_t          last_slave_sync_time = 0;

void board_init(void) { usbpd_init(); }

__attribute__((weak)) void draw_ui_user(void) {}

const char* usbpd_str(usbpd_allowance_t allowance) {
    switch (allowance) {
        default:
        case USBPD_500MA:
            return "500mA";
        case USBPD_1500MA:
            return "1500mA";
        case USBPD_3000MA:
            return "3000mA";
    }
}

void usbpd_update(void) {
    static uint32_t last_read = 0;
    if (timer_elapsed32(last_read) > 250) {
        last_read = timer_read32();
        switch (usbpd_get_allowance()) {
            case USBPD_500MA:
                if (kb_state.current_setting != USBPD_500MA) {
                    dprintf("Transitioning UCPD1 %s -> %s\n", usbpd_str(kb_state.current_setting), usbpd_str(USBPD_500MA));
                    kb_state.current_setting = USBPD_500MA;
                }
                break;
            case USBPD_1500MA:
                if (kb_state.current_setting != USBPD_1500MA) {
                    dprintf("Transitioning UCPD1 %s -> %s\n", usbpd_str(kb_state.current_setting), usbpd_str(USBPD_1500MA));
                    kb_state.current_setting = USBPD_1500MA;
                }
                break;
            case USBPD_3000MA:
                if (kb_state.current_setting != USBPD_3000MA) {
                    dprintf("Transitioning UCPD1 %s -> %s\n", usbpd_str(kb_state.current_setting), usbpd_str(USBPD_3000MA));
                    kb_state.current_setting = USBPD_3000MA;
                }
                break;
        }
    }
}

void kb_state_update(void) {
    if (is_keyboard_master()) {
        // Modify allowed current limits
        usbpd_update();

        // Turn off the LCD if there's been no matrix activity
        kb_state.lcd_power = (last_input_activity_elapsed() < LCD_ACTIVITY_TIMEOUT) ? 1 : 0;
    }
}

void kb_state_sync(void) {
    if (!is_transport_connected()) return;

    if (is_keyboard_master()) {
        // Keep track of the last state, so that we can tell if we need to propagate to slave
        static kb_runtime_config last_kb_state;
        static uint32_t          last_sync;
        bool                     needs_sync = false;

        // Check if the state values are different
        if (memcmp(&kb_state, &last_kb_state, sizeof(kb_runtime_config))) {
            needs_sync = true;
            memcpy(&last_kb_state, &kb_state, sizeof(kb_runtime_config));
        }

        // Send to slave every 500ms regardless of state change
        if (timer_elapsed32(last_sync) > 500) {
            needs_sync = true;
        }

        // Perform the sync if requested
        if (needs_sync) {
            if (transaction_rpc_send(RPC_ID_SYNC_STATE_KB, sizeof(kb_runtime_config), &kb_state)) {
                last_sync = timer_read32();
            } else {
                dprint("Failed to perform data transaction\n");
            }
        }
    }
}

void kb_state_sync_slave(uint8_t initiator2target_buffer_size, const void* initiator2target_buffer, uint8_t target2initiator_buffer_size, void* target2initiator_buffer) {
    if (initiator2target_buffer_size == sizeof(kb_runtime_config)) {
        memcpy(&kb_state, initiator2target_buffer, sizeof(kb_runtime_config));
    }
}

#define MATRIX_ROW_PINS \
    { B13, B14, B15, C6, C7, C8 }
#define MATRIX_COL_PINS \
    { C0, C1, C2, C3, A0, A1, A2 }

void housekeeping_task_kb(void) {
    // Update kb_state so we can send to slave
    kb_state_update();

    // Data sync from master to slave
    kb_state_sync();

    // Work out if we've changed our current limit, update the limiter circuit switches
    static uint8_t current_setting = USBPD_500MA;
    if (current_setting != kb_state.current_setting) {
        current_setting = kb_state.current_setting;
        switch (current_setting) {
            default:
            case USBPD_500MA:
                writePinLow(RGB_CURR_1500mA_OK_PIN);
                writePinLow(RGB_CURR_3000mA_OK_PIN);
                break;
#ifdef DJINN_SUPPORTS_3A_FUSE
            case USBPD_1500MA:
                writePinHigh(RGB_CURR_1500mA_OK_PIN);
                writePinLow(RGB_CURR_3000mA_OK_PIN);
                break;
            case USBPD_3000MA:
                writePinHigh(RGB_CURR_1500mA_OK_PIN);
                writePinHigh(RGB_CURR_3000mA_OK_PIN);
                break;
#else
            case USBPD_1500MA:
            case USBPD_3000MA:
                writePinHigh(RGB_CURR_1500mA_OK_PIN);
                writePinLow(RGB_CURR_3000mA_OK_PIN);
                break;
#endif
        }

        // Toggle rgblight on and off, if it's already on, to force a brightness update on all LEDs
        if (is_keyboard_master() && rgblight_is_enabled()) {
            rgblight_disable_noeeprom();
            rgblight_enable_noeeprom();
        }
    }

    // Turn on/off the LCD
    static bool lcd_on = false;
    if (lcd_on != (bool)kb_state.lcd_power) {
        lcd_on = (bool)kb_state.lcd_power;
        qp_power(lcd, lcd_on);
    }

    // Enable/disable RGB
    if (lcd_on) {
        // Enable EEPROM so that we've got some colour data already being transmitted, by the time we turn on the RGB_PWR line
        if (rgblight_is_enabled() != lcd_on) {
            rgblight_enable_noeeprom();
        }
        // Turn on RGB_PWR
        writePinHigh(RGB_POWER_ENABLE_PIN);
    } else {
        // Turn off RGB_PWR
        writePinLow(RGB_POWER_ENABLE_PIN);
        // Disable the PWM output for the RGB
        if (rgblight_is_enabled() != lcd_on) {
            rgblight_disable_noeeprom();
        }
    }

    // Match the backlight to the LCD state
    if (is_keyboard_master() && is_backlight_enabled() != lcd_on) {
        if (lcd_on)
            backlight_enable();
        else
            backlight_disable();
    }

    // Draw the UI
    if (kb_state.lcd_power) {
        draw_ui_user();
    }

    // Go into low-scan interrupt-based mode if we haven't had any matrix activity in the last 5 seconds
    if (last_input_activity_elapsed() > 5000) {
        // ROW2COL
        const pin_t row_pins[] = MATRIX_ROW_PINS;
        const pin_t col_pins[] = MATRIX_COL_PINS;

        // Set up row/col pins and attach callback
        for (int i = 0; i < sizeof(col_pins) / sizeof(pin_t); ++i) {
            setPinOutput(col_pins[i]);
            writePinLow(col_pins[i]);
        }
        for (int i = 0; i < sizeof(row_pins) / sizeof(pin_t); ++i) {
            setPinInputHigh(row_pins[i]);
            palEnableLineEvent(row_pins[i], PAL_EVENT_MODE_BOTH_EDGES);
        }

        // Wait for an interrupt
        __WFI();

        // Now that the interrupt has woken us up, reset all the row/col pins back to defaults
        for (int i = 0; i < sizeof(row_pins) / sizeof(pin_t); ++i) {
            palDisableLineEvent(row_pins[i]);
            writePinHigh(row_pins[i]);
            setPinInputHigh(row_pins[i]);
        }
        for (int i = 0; i < sizeof(col_pins) / sizeof(pin_t); ++i) {
            writePinHigh(col_pins[i]);
            setPinInputHigh(col_pins[i]);
        }
    }
}

//----------------------------------------------------------
// Initialisation

void keyboard_post_init_kb(void) {
    // Register keyboard state sync split transaction
    transaction_register_rpc(RPC_ID_SYNC_STATE_KB, kb_state_sync_slave);

    // Reset the initial shared data value between master and slave
    memset(&kb_state, 0, sizeof(kb_state));

    // Turn off increased current limits
    setPinOutput(RGB_CURR_1500mA_OK_PIN);
    writePinLow(RGB_CURR_1500mA_OK_PIN);
    setPinOutput(RGB_CURR_3000mA_OK_PIN);
    writePinLow(RGB_CURR_3000mA_OK_PIN);

    // Turn on the RGB
    setPinOutput(RGB_POWER_ENABLE_PIN);
    writePinHigh(RGB_POWER_ENABLE_PIN);

#ifdef EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN
    setPinOutput(EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN);
    writePinHigh(EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN);
#endif  // EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN

    // Turn on the LCD
    setPinOutput(LCD_POWER_ENABLE_PIN);
    writePinHigh(LCD_POWER_ENABLE_PIN);

    // Let the LCD get some power...
    wait_ms(50);

    // Initialise the LCD
    lcd = qp_ili9341_make_spi_device(320, 240, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 4, 0);
    qp_init(lcd, QP_ROTATION_0);

    // Turn on the LCD and clear the display
    kb_state.lcd_power = 1;
    qp_power(lcd, true);
    qp_rect(lcd, 0, 0, 239, 319, HSV_BLACK, true);

    // Turn on the LCD backlight
    backlight_enable();
    backlight_level(BACKLIGHT_LEVELS);

    // Allow for user post-init
    keyboard_post_init_user();
}

//----------------------------------------------------------
// QMK overrides

// Read the ports in one go
#define GPIOB_BITMASK (1 << 13 | 1 << 14 | 1 << 15)  // B13, B14, B15
#define GPIOB_OFFSET 13
#define GPIOB_COUNT 3
#define GPIOC_BITMASK (1 << 6 | 1 << 7 | 1 << 8)  // C6, C7, C8
#define GPIOC_OFFSET 6

// Pin definitions
static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static const pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;

void matrix_init_pins(void) {
    for (int i = 0; i < MATRIX_ROWS; ++i) setPinInputHigh(row_pins[i]);
    for (int i = 0; i < MATRIX_COLS; ++i) setPinInputHigh(col_pins[i]);
}

void matrix_read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col, matrix_row_t row_shifter) {
    // Setup the output column pin
    setPinOutput(col_pins[current_col]);
    writePinLow(col_pins[current_col]);
    rtcnt_t start = chSysGetRealtimeCounterX();
    rtcnt_t end   = start + 500;
    while (chSysIsCounterWithinX(chSysGetRealtimeCounterX(), start, end))
        if (readPin(col_pins[current_col]) == 0) break;

    // Read the row ports
    uint32_t gpio_b = palReadPort(GPIOB);
    uint32_t gpio_c = palReadPort(GPIOC);

    // Unselect the row pin
    setPinInputHigh(col_pins[current_col]);

    // Consutrct the packed bitmask for the pins
    uint32_t readback = ~(((gpio_b & GPIOB_BITMASK) >> GPIOB_OFFSET) | (((gpio_c & GPIOC_BITMASK) >> GPIOC_OFFSET) << GPIOB_COUNT));

    // Inject values into the matrix
    for (int i = 0; i < MATRIX_ROWS; ++i) {
        if (readback & (1 << i))
            current_matrix[i] |= (1ul << current_col);
        else
            current_matrix[i] &= ~(1ul << current_col);
    }

    // Wait for readback of each port to go high -- unselecting the row would have been completed
    start = chSysGetRealtimeCounterX();
    end   = start + 500;
    while (chSysIsCounterWithinX(chSysGetRealtimeCounterX(), start, end))
        if ((palReadPort(GPIOB) & GPIOB_BITMASK) == GPIOB_BITMASK) break;
    while (chSysIsCounterWithinX(chSysGetRealtimeCounterX(), start, end))
        if ((palReadPort(GPIOC) & GPIOC_BITMASK) == GPIOC_BITMASK) break;
}

#if defined(RGB_MATRIX_ENABLE)
#    define rgb_to_hsv_hook_func rgb_matrix_hsv_to_rgb
#elif defined(RGBLIGHT_ENABLE)
#    define rgb_to_hsv_hook_func rgblight_hsv_to_rgb
#endif
RGB rgb_to_hsv_hook_func(HSV hsv) {
    float scale;
    switch (kb_state.current_setting) {
        default:
        case USBPD_500MA:
            scale = 0.35f;
            break;
#ifdef DJINN_SUPPORTS_3A_FUSE
        case USBPD_1500MA:
            scale = 0.75f;
            break;
        case USBPD_3000MA:
            scale = 1.0f;
            break;
#else
        case USBPD_1500MA:
        case USBPD_3000MA:
            scale = 0.75f;
            break;
#endif
    }

    hsv.v = (uint8_t)(hsv.v * scale);
    return hsv_to_rgb(hsv);
}
