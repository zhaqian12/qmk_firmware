/* Copyright 2022 ZhaQian
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

#pragma once

#define MCU_STM32

/* FLASH redefines */
#if defined(EEPROM_ENABLE)
#    define SR STS
#    define FLASH_SR_BSY FLASH_STS_BUSY
#    define FLASH_SR_PGERR FLASH_STS_PGERR
#    define FLASH_SR_EOP FLASH_STS_EOP
#    define FLASH_SR_WRPRTERR FLASH_STS_WRPERR
#    define FLASH_SR_WRPERR FLASH_STS_WRPERR
#    define FLASH_OBR_OPTERR FLASH_OB_OBERR
#    define AR ADD
#    define CR CTRL
#    define FLASH_CR_PER FLASH_CTRL_PER
#    define FLASH_CR_STRT FLASH_CTRL_START
#    define FLASH_CR_LOCK FLASH_CTRL_LOCK
#    define FLASH_CR_PG FLASH_CTRL_PG
// #    define FLASH_KEY1 0x45670123U
// #    define FLASH_KEY2 0xCDEF89ABU
#endif


