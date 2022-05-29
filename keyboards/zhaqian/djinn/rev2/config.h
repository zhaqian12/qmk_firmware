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

#pragma once

// Split configuration
#define SPLIT_HAND_PIN B9

#if defined(SERIAL_DRIVER_USART)
#    define SERIAL_USART_DRIVER SD3
#    define SERIAL_USART_PIN_SWAP
#    define SERIAL_USART_TX_PIN B10
#    define SERIAL_USART_TX_PAL_MODE 7
#    define SERIAL_USART_RX_PIN B11
#    define SERIAL_USART_RX_PAL_MODE 7
#    ifndef SERIAL_USART_SPEED
#        define SERIAL_USART_SPEED 1200000
#    endif  // SERIAL_USART_SPEED
#    define SERIAL_USART_FULL_DUPLEX
#endif  // defined(SERIAL_DRIVER_USART)

// RGB configuration
#define RGB_POWER_ENABLE_PIN B0
#define RGB_CURR_1500mA_OK_PIN C5
#define RGB_CURR_3000mA_OK_PIN C4
#define RGBLED_NUM 86
#define RGBLED_SPLIT \
    { 43, 43 }

// EEPROM configuration
#define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN B5
#define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR 8  // (160MHz/8) => 20MHz
#define EXTERNAL_EEPROM_BYTE_COUNT 8192
#define EXTERNAL_EEPROM_PAGE_SIZE 64  // it's FRAM, so it doesn't actually matter, this just sets the RAM buffer

// External flash config
#define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN A8
#define EXTERNAL_FLASH_SPI_CLOCK_DIVISOR 8           // (160MHz/8) => 20MHz
#define EXTERNAL_FLASH_BYTE_COUNT (4 * 1024 * 1024)  // 32Mb/4MB capacity
#define EXTERNAL_FLASH_PAGE_SIZE (4 * 1024)          // 4kB pages

// Fault indicators
#define BOARD_POWER_FAULT_PIN C9
#define RGB_POWER_FAULT_PIN C4

// Limit the backlight brightness
#define BACKLIGHT_LIMIT_VAL 144