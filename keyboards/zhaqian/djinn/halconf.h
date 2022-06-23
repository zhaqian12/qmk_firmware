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

#define HAL_USE_GPT TRUE
#define HAL_USE_PWM TRUE
#define HAL_USE_SPI TRUE

#define SERIAL_BUFFERS_SIZE 256

// This enables interrupt-driven moe
#define PAL_USE_WAIT TRUE

#if defined(SERIAL_DRIVER_USART) || defined(SERIAL_DRIVER_USART_DUPLEX_ALT)
#define HAL_USE_SERIAL TRUE
#endif  // defined(SERIAL_DRIVER_USART) || defined(SERIAL_DRIVER_USART_DUPLEX_ALT)

#if defined(SERIAL_DRIVER_USART_DUPLEX)
#define HAL_USE_UART TRUE
#define UART_USE_WAIT TRUE
#endif  // defined(SERIAL_DRIVER_USART_DUPLEX)

#include_next <halconf.h>

