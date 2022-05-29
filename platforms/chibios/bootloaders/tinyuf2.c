/* Copyright 2021 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#include "bootloader.h"

#include <ch.h>

// From tinyuf2's board_api.h
#define DBL_TAP_MAGIC 0xF01669EF

// defined by linker script
extern uint32_t _board_dfu_dbl_tap[];
#define DBL_TAP_REG _board_dfu_dbl_tap[0]

#ifdef GD32VF103
#define DBGMCU_KEY_UNLOCK 0x4B5A6978
#define DBGMCU_CMD_RESET 0x1
__IO uint32_t *DBGMCU_KEY = (uint32_t *)0xE0042000U + 0x0CU;
__IO uint32_t *DBGMCU_CMD = (uint32_t *)0xE0042000U + 0x08U;
#endif

__attribute__((weak)) void mcu_reset(void) {
    DBL_TAP_REG = DBL_TAP_MAGIC;
#ifndef GD32VF103
    NVIC_SystemReset();
#else
    *DBGMCU_KEY = DBGMCU_KEY_UNLOCK;
    *DBGMCU_CMD = DBGMCU_CMD_RESET;
#endif
}

/* not needed, no two-stage reset */
void enter_bootloader_mode_if_requested(void) {}
