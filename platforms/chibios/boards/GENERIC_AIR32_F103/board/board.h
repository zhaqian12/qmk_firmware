#pragma once
/*
    Copyright (C)
    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at
        http://www.apache.org/licenses/LICENSE-2.0
    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/*
 * This file has been automatically generated using ChibiStudio board
 * generator plugin. Do not edit manually.
 */

#ifndef BOARD_H
#define BOARD_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*
 * Setup board.
 */
/*
 * Port A setup.
 * Everything input with pull-up except:
 * PA2  - Alternate output  (USART2 TX).
 * PA3  - Normal input      (USART2 RX).
 * PA9  - Alternate output  (USART1 TX).
 * PA10 - Normal input      (USART1 RX).
 * PA11 - Alternate output  (DP PUUP).
 */
#define VAL_GPIOACRL            0x88884B88      /*  PA7...PA0 */
#define VAL_GPIOACRH            0x8888F4B8      /* PA15...PA8 */
#define VAL_GPIOAODR            0xFFFFF7FF

/*
 * Port B setup.
 * Everything input with pull-up except:
 * PB10    - Push Pull output  (USB switch).
 */
#define VAL_GPIOBCRL            0x88888888      /*  PB7...PB0 */
#define VAL_GPIOBCRH            0x88888388      /* PB15...PB8 */
#define VAL_GPIOBODR            0xFFFFFFFF

/*
 * Port C setup.
 * Everything input with pull-up except:
 * PC13    - Push Pull output  (LED).
 */
#define VAL_GPIOCCRL            0x88888888      /*  PC7...PC0 */
#define VAL_GPIOCCRH            0x88388888      /* PC15...PC8 */
#define VAL_GPIOCODR            0xFFFFFFFF

/*
 * Port D setup.
 * Everything input with pull-up except:
 * PD0  - Normal input (XTAL).
 * PD1  - Normal input (XTAL).
 */
#define VAL_GPIODCRL            0x88888844      /*  PD7...PD0 */
#define VAL_GPIODCRH            0x88888888      /* PD15...PD8 */
#define VAL_GPIODODR            0xFFFFFFFF
/*
 * Board identifier.
 */
#define BOARD_AIR32F103
#define BOARD_NAME                  "AIR32F103"

#define AIR32F103xB

#if !defined(AIR32F10x)
  #define AIR32F10x
#endif

/*
 * Board oscillators-related settings.
 * NOTE: LSE not fitted.
 */
#if !defined(AIR32_LSECLK)
#define AIR32_LSECLK                0U
#endif

#if !defined(AIR32_HSECLK)
#define AIR32_HSECLK                8000000U
#endif
/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* BOARD_H */