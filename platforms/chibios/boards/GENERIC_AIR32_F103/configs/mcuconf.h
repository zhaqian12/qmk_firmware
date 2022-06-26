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

#define AIR32F10x_MCUCONF  TRUE

/*
 * AIR32F10x drivers configuration.
 * The following settings override the default settings present in
 * the various device driver implementation headers.
 * Note that the settings for each driver only have effect if the whole
 * driver is enabled in halconf.h.
 *
 * IRQ priorities:
 * 3...0       Lowest...Highest.
 *
 */

/*
 * HAL driver system settings.
 */
#define AIR32_NO_INIT                       FALSE
#define AIR32_HSI_ENABLED                   TRUE
#define AIR32_LSI_ENABLED                   FALSE
#define AIR32_HSE_ENABLED                   TRUE
#define AIR32_LSE_ENABLED                   FALSE
#define AIR32_SW                            AIR32_SW_PLL
#define AIR32_PLLSRC                        AIR32_PLLSRC_HSE
#define AIR32_PLLXTPRE                      AIR32_PLLXTPRE_DIV1
#define AIR32_PLLMUL_VALUE                  15
#define AIR32_HPRE                          AIR32_HPRE_DIV1
#define AIR32_PPRE1                         AIR32_PPRE1_DIV2
#define AIR32_PPRE2                         AIR32_PPRE2_DIV1
#define AIR32_ADCPRE                        AIR32_ADCPRE_DIV16
#define AIR32_USB_CLOCK_REQUIRED            TRUE
#define AIR32_USBPRE                        AIR32_USBPRE_DIV2P5
#define AIR32_MCOSEL                        AIR32_MCOSEL_NOCLOCK
#define AIR32_RTCSEL                        AIR32_RTCSEL_HSEDIV
#define AIR32_PVD_ENABLE                    FALSE
#define AIR32_PLS                           AIR32_PLS_LEV0

/*
 * ADC driver system settings.
 */
#define AIR32_ADC_USE_ADC1                  FALSE
#define AIR32_ADC_ADC1_DMA_PRIORITY         2
#define AIR32_ADC_ADC1_IRQ_PRIORITY         2

#define AIR32_ADC_USE_ADC2                  FALSE
#define AIR32_ADC_ADC2_DMA_PRIORITY         2
#define AIR32_ADC_ADC2_IRQ_PRIORITY         2

/*
 * DAC driver system settings.
 */
#define AIR32_DAC_DUAL_MODE                 FALSE
#define AIR32_DAC_USE_DAC1_CH1              FALSE
#define AIR32_DAC_USE_DAC1_CH2              FALSE
#define AIR32_DAC_DAC1_CH1_IRQ_PRIORITY     3
#define AIR32_DAC_DAC1_CH2_IRQ_PRIORITY     3
#define AIR32_DAC_DAC1_CH1_DMA_PRIORITY     3
#define AIR32_DAC_DAC1_CH2_DMA_PRIORITY     3

/*
 * CAN driver system settings.
 */
#define AIR32_CAN_USE_CAN1                  FALSE
#define AIR32_CAN_CAN1_IRQ_PRIORITY         11

/*
 * EXT driver system settings.
 */
#define AIR32_EXT_EXTI0_IRQ_PRIORITY        2
#define AIR32_EXT_EXTI1_IRQ_PRIORITY        2
#define AIR32_EXT_EXTI2_IRQ_PRIORITY        2
#define AIR32_EXT_EXTI3_IRQ_PRIORITY        2
#define AIR32_EXT_EXTI4_IRQ_PRIORITY        2
#define AIR32_EXT_EXTI5_9_IRQ_PRIORITY      2
#define AIR32_EXT_EXTI10_15_IRQ_PRIORITY    2

/*
 * GPT driver system settings.
 */
#define AIR32_GPT_USE_TIM1                  FALSE
#define AIR32_GPT_USE_TIM2                  FALSE
#define AIR32_GPT_USE_TIM3                  FALSE
#define AIR32_GPT_USE_TIM4                  FALSE
#define AIR32_GPT_USE_TIM5                  FALSE
#define AIR32_GPT_TIM1_IRQ_PRIORITY         3
#define AIR32_GPT_TIM2_IRQ_PRIORITY         3
#define AIR32_GPT_TIM3_IRQ_PRIORITY         3
#define AIR32_GPT_TIM4_IRQ_PRIORITY         3
#define AIR32_GPT_TIM5_IRQ_PRIORITY         3

/*
 * I2C driver system settings.
 */
#define AIR32_I2C_USE_I2C1                  FALSE
#define AIR32_I2C_USE_I2C2                  FALSE
#define AIR32_I2C_BUSY_TIMEOUT              50
#define AIR32_I2C_I2C1_IRQ_PRIORITY         5
#define AIR32_I2C_I2C2_IRQ_PRIORITY         5
#define AIR32_I2C_I2C1_DMA_PRIORITY         3
#define AIR32_I2C_I2C2_DMA_PRIORITY         3
#define AIR32_I2C_DMA_ERROR_HOOK(i2cp)      osalSysHalt("DMA failure")

/*
 * ICU driver system settings.
 */
#define AIR32_ICU_USE_TIM1                  FALSE
#define AIR32_ICU_USE_TIM2                  FALSE
#define AIR32_ICU_USE_TIM3                  FALSE
#define AIR32_ICU_USE_TIM4                  FALSE
#define AIR32_ICU_USE_TIM5                  FALSE
#define AIR32_ICU_TIM1_IRQ_PRIORITY         3
#define AIR32_ICU_TIM2_IRQ_PRIORITY         3
#define AIR32_ICU_TIM3_IRQ_PRIORITY         3
#define AIR32_ICU_TIM4_IRQ_PRIORITY         3
#define AIR32_ICU_TIM5_IRQ_PRIORITY         3

/*
 * PWM driver system settings.
 */
#define AIR32_PWM_USE_ADVANCED              FALSE
#define AIR32_PWM_USE_TIM1                  FALSE
#define AIR32_PWM_USE_TIM2                  FALSE
#define AIR32_PWM_USE_TIM3                  FALSE
#define AIR32_PWM_USE_TIM4                  FALSE
#define AIR32_PWM_USE_TIM5                  FALSE
#define AIR32_PWM_TIM1_IRQ_PRIORITY         3
#define AIR32_PWM_TIM2_IRQ_PRIORITY         3
#define AIR32_PWM_TIM3_IRQ_PRIORITY         3
#define AIR32_PWM_TIM4_IRQ_PRIORITY         3
#define AIR32_PWM_TIM5_IRQ_PRIORITY         3

/*
 * RTC driver system settings.
 */
#define AIR32_RTC_IRQ_PRIORITY              3

/*
 * SERIAL driver system settings.
 */
#define AIR32_SERIAL_USE_USART1             FALSE
#define AIR32_SERIAL_USE_USART2             FALSE
#define AIR32_SERIAL_USE_USART3             FALSE
#define AIR32_SERIAL_USART1_PRIORITY        6
#define AIR32_SERIAL_USART2_PRIORITY        6
#define AIR32_SERIAL_USART3_PRIORITY        6

/*
 * SPI driver system settings.
 */
#define AIR32_SPI_USE_SPI1                  FALSE
#define AIR32_SPI_USE_SPI2                  FALSE
#define AIR32_SPI_USE_SPI3                  FALSE
#define AIR32_SPI_SPI1_DMA_PRIORITY         1
#define AIR32_SPI_SPI2_DMA_PRIORITY         1
#define AIR32_SPI_SPI3_DMA_PRIORITY         1
#define AIR32_SPI_SPI1_IRQ_PRIORITY         6
#define AIR32_SPI_SPI2_IRQ_PRIORITY         6
#define AIR32_SPI_SPI3_IRQ_PRIORITY         6
#define AIR32_SPI_DMA_ERROR_HOOK(spip)      osalSysHalt("DMA failure")

/*
 * ST driver system settings.
 */
#define AIR32_ST_IRQ_PRIORITY               4
#define AIR32_ST_USE_TIMER                  2

/*
 * UART driver system settings.
 */
#define AIR32_UART_USE_USART1               FALSE
#define AIR32_UART_USE_USART2               FALSE
#define AIR32_UART_USE_USART3               FALSE
#define AIR32_UART_USART1_IRQ_PRIORITY      6
#define AIR32_UART_USART2_IRQ_PRIORITY      6
#define AIR32_UART_USART3_IRQ_PRIORITY      6
#define AIR32_UART_USART1_DMA_PRIORITY      0
#define AIR32_UART_USART2_DMA_PRIORITY      0
#define AIR32_UART_USART3_DMA_PRIORITY      0
#define AIR32_UART_DMA_ERROR_HOOK(uartp)    osalSysHalt("DMA failure")

/*
 * USB driver system settings.
 */
#define AIR32_USB_USE_USB1                  TRUE
#define AIR32_USB_LOW_POWER_ON_SUSPEND      FALSE
#define AIR32_USB_USB1_HP_IRQ_PRIORITY      5
#define AIR32_USB_USB1_LP_IRQ_PRIORITY      6


#endif /* MCUCONF_H */
