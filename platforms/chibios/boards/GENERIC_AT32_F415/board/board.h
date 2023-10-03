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
 */
#define VAL_GPIOACFGLR            0x88888888      /*  PA7...PA0 */
#define VAL_GPIOACFGHR            0x88888888      /* PA15...PA8 */
#define VAL_GPIOAODT              0xFFFFFFFF

/*
 * Port B setup.
 * Everything input with pull-up except:
 */
#define VAL_GPIOBCFGLR            0x88888888      /*  PB7...PB0 */
#define VAL_GPIOBCFGHR            0x88888888      /* PB15...PB8 */
#define VAL_GPIOBODT              0xFFFFFFFF

/*
 * Port C setup.
 * Everything input with pull-up except:
 */
#define VAL_GPIOCCFGLR            0x88888888      /*  PC7...PC0 */
#define VAL_GPIOCCFGHR            0x88888888      /* PC15...PC8 */
#define VAL_GPIOCODT              0xFFFFFFFF

/*
 * Port D setup.
 * Everything input with pull-up except:
 * PD0  - Normal input (XTAL).
 * PD1  - Normal input (XTAL).
 */
#define VAL_GPIODCFGLR            0x88888844      /*  PD7...PD0 */
#define VAL_GPIODCFGHR            0x88888888      /* PD15...PD8 */
#define VAL_GPIODODT              0xFFFFFFFF

/*
 * Port F setup.
 * Everything input with pull-up except:
 */
#define VAL_GPIOFCFGLR            0x88888888      /*  PF7...PF0 */
#define VAL_GPIOFCFGHR            0x88888888      /* PF15...PF8 */
#define VAL_GPIOFODT              0xFFFFFFFF

/*
 * Board identifier.
 */
#define BOARD_AT32F415xx
#define BOARD_NAME                  "AT32F415"

#define AT32F415xB
#define AT32F415CBT7

#if !defined(AT32F415xx)
#define AT32F415xx
#endif

/*
 * Board oscillators-related settings.
 */
#if !defined(AT32_LEXTCLK)
#define AT32_LEXTCLK              32768U
#endif

#if !defined(AT32_HEXTCLK)
#define AT32_HEXTCLK              8000000U
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