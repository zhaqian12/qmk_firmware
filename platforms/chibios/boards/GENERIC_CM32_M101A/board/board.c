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

#include "hal.h"
/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static void cm32_gpio_init(void) {

#if CM32_HAS_GPIOA
  rccEnableAPB2(RCC_APB2PCLKEN_IOPAEN, false);
#endif

#if CM32_HAS_GPIOB
  rccEnableAPB2(RCC_APB2PCLKEN_IOPBEN, false);
#endif

#if CM32_HAS_GPIOC
  rccEnableAPB2(RCC_APB2PCLKEN_IOPCEN, false);
#endif

#if CM32_HAS_GPIOD
  rccEnableAPB2(RCC_APB2PCLKEN_IOPDEN, false);
#endif
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/
/*
 * Early initialization code.
 * This initialization must be performed just after stack setup and before
 * any other initialization.
 */
void __early_init(void) {
  cm32_clock_init();
  cm32_gpio_init();
}
/**
 * @brief   Board-specific initialization code.
 * @note    You can add your board-specific code here.
 */
void boardInit(void) {

}
