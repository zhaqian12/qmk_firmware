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

#include_next <mcuconf.h>

// Used for audio
#undef STM32_PWM_USE_TIM1
#undef STM32_GPT_USE_TIM6
#undef STM32_GPT_USE_TIM7
#undef STM32_GPT_USE_TIM8
#define STM32_PWM_USE_TIM1 TRUE
#define STM32_GPT_USE_TIM6 TRUE
#define STM32_GPT_USE_TIM7 TRUE
#define STM32_GPT_USE_TIM8 TRUE

// Used for backlight
#undef STM32_PWM_USE_TIM17
#define STM32_PWM_USE_TIM17 TRUE

// Used for SK6812 chain
#undef STM32_PWM_USE_TIM20
#define STM32_PWM_USE_TIM20 TRUE

// Used for split comms
#if defined(SERIAL_DRIVER_USART) || defined(SERIAL_DRIVER_USART_DUPLEX_ALT)
#undef STM32_SERIAL_USE_USART3
#define STM32_SERIAL_USE_USART3 TRUE
#endif  // defined(SERIAL_DRIVER_USART) || defined(SERIAL_DRIVER_USART_DUPLEX_ALT)

#if defined(SERIAL_DRIVER_USART_DUPLEX)
#undef STM32_UART_USE_USART3
#define STM32_UART_USE_USART3 TRUE
#endif  // defined(SERIAL_DRIVER_USART_DUPLEX)

// Used for EEPROM
#undef STM32_SPI_USE_SPI3
#define STM32_SPI_USE_SPI3 TRUE

