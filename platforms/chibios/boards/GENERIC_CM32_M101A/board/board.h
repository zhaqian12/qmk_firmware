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
 * Board identifier.
 */
#define BOARD_CMIOT_CM32M101A
#define BOARD_NAME                  "CMIOT CM32M101A"

#define CM32M101A
#if !defined(CM32M101A)
  #define CM32M101A
#endif

/*
 * Board oscillators-related settings.
 * NOTE: LSE not fitted.
 */
#if !defined(CM32_LSECLK)
#define CM32_LSECLK                0U
#endif

#if !defined(CM32_HSECLK)
#define CM32_HSECLK                8000000U
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
