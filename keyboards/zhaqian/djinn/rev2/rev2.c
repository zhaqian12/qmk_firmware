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

#include <hal.h>
#include <quantum.h>
#include "rev2.h"

// Delays can be shorter than 30us.
void matrix_io_delay(void) {
    for (int i = 0; i < 10; ++i) __asm__ volatile("nop\nnop\nnop\n");
}

bool is_keyboard_master(void) {
    static bool determined = false;
    static bool is_master;
    if (!determined) {
        determined = true;
        setPinInput(SPLIT_PLUG_DETECT_PIN);
        wait_ms(50);
        is_master = readPin(SPLIT_PLUG_DETECT_PIN) ? true : false;
        if (!is_master) {
            usbStop(&USBD1);
        }
    }

    return is_master;
}

#ifdef RGB_MATRIX_ENABLE
// clang-format off
#define RLO 43
#define LLI(x) (x)
#define LLP(x,y) {(x),(y)}
#define RLI(x) (RLO+(x))
#define RLP(x,y) {(224-(x)),((y))}
led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        { LLI(36), LLI(37), LLI(38), LLI(39), LLI(40), LLI(41), LLI(42) },
        { LLI(35), LLI(34), LLI(33), LLI(32), LLI(31), LLI(30), LLI(29) },
        { LLI(22), LLI(23), LLI(24), LLI(25), LLI(26), LLI(27), LLI(28) },
        { LLI(21), LLI(20), LLI(19), LLI(18), LLI(17), LLI(16), LLI(15) },
        {  NO_LED,  NO_LED,  NO_LED, LLI(11), LLI(12), LLI(13), LLI(14) },
        {  NO_LED,  NO_LED,  NO_LED,  NO_LED, NO_LED,  NO_LED,  NO_LED, },
        { RLI(36), RLI(37), RLI(38), RLI(39), RLI(40), RLI(41), RLI(42) },
        { RLI(35), RLI(34), RLI(33), RLI(32), RLI(31), RLI(30), RLI(29) },
        { RLI(22), RLI(23), RLI(24), RLI(25), RLI(26), RLI(27), RLI(28) },
        { RLI(21), RLI(20), RLI(19), RLI(18), RLI(17), RLI(16), RLI(15) },
        {  NO_LED,  NO_LED,  NO_LED, RLI(11), RLI(12), RLI(13), RLI(14) },
        {  NO_LED,  NO_LED,  NO_LED,  NO_LED, NO_LED,  NO_LED,  NO_LED, },
    },
    {
        // LED Index to Physical Position
        // Underglow left
        LLP(110, 30), LLP(110, 80), LLP(110, 130), LLP(95, 180), LLP(75, 195), LLP(60, 210), LLP(45, 190), LLP(35, 175), LLP(20, 160), LLP(5, 160), LLP(5, 160),
        // Matrix left
        LLP( 78, 150), LLP(104, 150), LLP(130, 150), LLP(156, 150),
        LLP(156, 120), LLP(130, 120), LLP(104, 120), LLP( 78, 120), LLP( 52, 120), LLP( 26, 120), LLP(  0, 120),
        LLP(  0,  90), LLP( 26,  90), LLP( 52,  90), LLP( 78,  90), LLP(104,  90), LLP(130,  90), LLP(156,  90),
        LLP(156,  60), LLP(130,  60), LLP(104,  60), LLP( 78,  60), LLP( 52,  60), LLP( 26,  60), LLP(  0,  60),
        LLP(  0,  30), LLP( 26,  30), LLP( 52,  30), LLP( 78,  30), LLP(104,  30), LLP(130,  30), LLP(156,  30),
        // Underglow right
        RLP(110, 30), RLP(110, 80), RLP(110, 130), RLP(95, 180), RLP(75, 195), RLP(60, 210), RLP(45, 190), RLP(35, 175), RLP(20, 160), RLP(5, 160), RLP(5, 160),
        // Matrix right
        RLP( 78, 150), RLP(104, 150), RLP(130, 150), RLP(156, 150),
        RLP(156, 120), RLP(130, 120), RLP(104, 120), RLP( 78, 120), RLP( 52, 120), RLP( 26, 120), RLP(  0, 120),
        RLP(  0,  90), RLP( 26,  90), RLP( 52,  90), RLP( 78,  90), RLP(104,  90), RLP(130,  90), RLP(156,  90),
        RLP(156,  60), RLP(130,  60), RLP(104,  60), RLP( 78,  60), RLP( 52,  60), RLP( 26,  60), RLP(  0,  60),
        RLP(  0,  30), RLP( 26,  30), RLP( 52,  30), RLP( 78,  30), RLP(104,  30), RLP(130,  30), RLP(156,  30),
    },
    {
        // LED Index to Flag
        // Underglow left
        LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
        // Matrix left
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        // Underglow right
        LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
        // Matrix right
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    }
};
// clang-format on
#endif  // RGB_MATRIX_ENABLE
