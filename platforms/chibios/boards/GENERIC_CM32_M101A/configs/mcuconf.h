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

#ifndef MCUCONF_H
#define MCUCONF_H

#define CM32M101A_MCUCONF  TRUE

/*
 * CM32M101A drivers configuration.
 * The following settings override the default settings present in
 * the various device driver implementation headers.
 * Note that the settings for each driver only have effect if the whole
 * driver is enabled in halconf.h.
 *
 * IRQ priorities:
 * 15...0       Lowest...Highest.
 *
 */

/*
 * HAL driver system settings.
 */
#define CM32_NO_INIT                       FALSE
#define CM32_HSI_ENABLED                   TRUE
#define CM32_LSI_ENABLED                   FALSE
#define CM32_HSE_ENABLED                   TRUE
#define CM32_LSE_ENABLED                   FALSE
#define CM32_SW                            CM32_SW_PLL
#define CM32_PLLSRC                        CM32_PLLSRC_HSE
#define CM32_PLLXTPRE                      CM32_PLLXTPRE_DIV1
#define CM32_PLLMUL_VALUE                  12
#define CM32_HPRE                          CM32_HPRE_DIV1
#define CM32_PPRE1                         CM32_PPRE1_DIV4
#define CM32_PPRE2                         CM32_PPRE2_DIV2
#define CM32_USB_CLOCK_REQUIRED            TRUE
#define CM32_USBPRE                        CM32_USBPRE_DIV2
#define CM32_MCOSEL                        CM32_MCOSEL_NOCLOCK
#define CM32_MCOPRE                        CM32_MCOPRE_DIV2
#define CM32_RTCSEL                        CM32_RTCSEL_LSI
#define CM32_PVD_ENABLE                    FALSE
#define CM32_PLS                           CM32_PLS_LEV0

/*
 * ADC driver system settings.
 */
#define CM32_ADC_USE_ADC1                  FALSE
#define CM32_ADC_ADC1_DMA_PRIORITY         2
#define CM32_ADC_ADC1_IRQ_PRIORITY         6

/*
 * CAN driver system settings.
 */
#define CM32_CAN_USE_CAN1                  FALSE
#define CM32_CAN_CAN1_IRQ_PRIORITY         11

/*
 * EXTI driver system settings.
 */
#define CM32_IRQ_EXTI0_PRIORITY            6
#define CM32_IRQ_EXTI1_PRIORITY            6
#define CM32_IRQ_EXTI2_PRIORITY            6
#define CM32_IRQ_EXTI3_PRIORITY            6
#define CM32_IRQ_EXTI4_PRIORITY            6
#define CM32_IRQ_EXTI9_5_PRIORITY          6
#define CM32_IRQ_EXTI15_10_PRIORITY        6
#define CM32_IRQ_EXTI16_PRIORITY           6
#define CM32_IRQ_EXTI17_PRIORITY           6
#define CM32_IRQ_EXTI18_PRIORITY           6
#define CM32_IRQ_EXTI19_PRIORITY           6

/*
 * GPT driver system settings.
 */
#define CM32_GPT_USE_TIM1                  FALSE
#define CM32_GPT_USE_TIM2                  FALSE
#define CM32_GPT_USE_TIM3                  FALSE
#define CM32_GPT_USE_TIM4                  FALSE
#define CM32_GPT_USE_TIM5                  FALSE
#define CM32_GPT_USE_TIM8                  FALSE
#define CM32_GPT_USE_TIM9                  FALSE
#define CM32_GPT_TIM1_IRQ_PRIORITY         7
#define CM32_GPT_TIM2_IRQ_PRIORITY         7
#define CM32_GPT_TIM3_IRQ_PRIORITY         7
#define CM32_GPT_TIM4_IRQ_PRIORITY         7
#define CM32_GPT_TIM5_IRQ_PRIORITY         7
#define CM32_GPT_TIM8_IRQ_PRIORITY         7
#define CM32_GPT_TIM9_IRQ_PRIORITY         7

/*
 * I2C driver system settings.
 */
#define CM32_I2C_USE_I2C1                  FALSE
#define CM32_I2C_USE_I2C2                  FALSE
#define CM32_I2C_BUSY_TIMEOUT              50
#define CM32_I2C_I2C1_IRQ_PRIORITY         5
#define CM32_I2C_I2C2_IRQ_PRIORITY         5

/*
 * ICU driver system settings.
 */
#define CM32_ICU_USE_TIM1                  FALSE
#define CM32_ICU_USE_TIM2                  FALSE
#define CM32_ICU_USE_TIM3                  FALSE
#define CM32_ICU_USE_TIM4                  FALSE
#define CM32_ICU_USE_TIM5                  FALSE
#define CM32_ICU_USE_TIM8                  FALSE
#define CM32_ICU_USE_TIM9                  FALSE
#define CM32_ICU_TIM1_IRQ_PRIORITY         7
#define CM32_ICU_TIM2_IRQ_PRIORITY         7
#define CM32_ICU_TIM3_IRQ_PRIORITY         7
#define CM32_ICU_TIM4_IRQ_PRIORITY         7
#define CM32_ICU_TIM5_IRQ_PRIORITY         7
#define CM32_ICU_TIM8_IRQ_PRIORITY         7
#define CM32_ICU_TIM9_IRQ_PRIORITY         7

/*
 * PWM driver system settings.
 */
#define CM32_PWM_USE_ADVANCED              FALSE
#define CM32_PWM_USE_TIM1                  FALSE
#define CM32_PWM_USE_TIM2                  FALSE
#define CM32_PWM_USE_TIM3                  FALSE
#define CM32_PWM_USE_TIM4                  FALSE
#define CM32_PWM_USE_TIM5                  FALSE
#define CM32_PWM_USE_TIM8                  FALSE
#define CM32_PWM_USE_TIM9                  FALSE
#define CM32_PWM_TIM1_IRQ_PRIORITY         7
#define CM32_PWM_TIM2_IRQ_PRIORITY         7
#define CM32_PWM_TIM3_IRQ_PRIORITY         7
#define CM32_PWM_TIM4_IRQ_PRIORITY         7
#define CM32_PWM_TIM5_IRQ_PRIORITY         7
#define CM32_PWM_TIM8_IRQ_PRIORITY         7
#define CM32_PWM_TIM9_IRQ_PRIORITY         7

/*
 * RTC driver system settings.
 */
#define CM32_RTC_IRQ_PRIORITY              15

/*
 * SERIAL driver system settings.
 */
#define CM32_SERIAL_USE_USART1             FALSE
#define CM32_SERIAL_USE_USART2             FALSE
#define CM32_SERIAL_USE_USART3             FALSE
#define CM32_SERIAL_USE_UART4              FALSE
#define CM32_SERIAL_USE_UART5              FALSE
#define CM32_SERIAL_USART1_PRIORITY        12
#define CM32_SERIAL_USART2_PRIORITY        12
#define CM32_SERIAL_USART3_PRIORITY        12
#define CM32_SERIAL_UART4_PRIORITY         12
#define CM32_SERIAL_UART5_PRIORITY         12

/*
 * SPI driver system settings.
 */
#define CM32_SPI_USE_SPI1                  FALSE
#define CM32_SPI_USE_SPI2                  FALSE
#define CM32_SPI_SPI1_IRQ_PRIORITY         10
#define CM32_SPI_SPI2_IRQ_PRIORITY         10

/*
 * ST driver system settings.
 */
#define CM32_ST_IRQ_PRIORITY                8
#define CM32_ST_USE_TIMER                   2

/*
 * UART driver system settings.
 */
#define CM32_UART_USE_USART1               FALSE
#define CM32_UART_USE_USART2               FALSE
#define CM32_UART_USE_USART3               FALSE
#define CM32_UART_USART1_IRQ_PRIORITY      12
#define CM32_UART_USART2_IRQ_PRIORITY      12
#define CM32_UART_USART3_IRQ_PRIORITY      12

/*
 * USB driver system settings.
 */
#define CM32_USB_USE_USB1                  TRUE
#define CM32_USB_LOW_POWER_ON_SUSPEND      FALSE
#define CM32_USB_USB1_HP_IRQ_PRIORITY      13
#define CM32_USB_USB1_LP_IRQ_PRIORITY      14


#endif /* MCUCONF_H */
