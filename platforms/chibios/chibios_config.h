/* Copyright 2019
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

#ifndef USB_VBUS_PIN
#    define SPLIT_USB_DETECT // Force this on when dedicated pin is not used
#endif

#if defined(MCU_RP)
#    define CPU_CLOCK RP_CORE_CLK
// ChibiOS uses the RP2040 timer peripheral as its real time counter, this timer
// is monotonic and running at 1MHz.
#    define REALTIME_COUNTER_CLOCK 1000000

#    define USE_GPIOV1
#    define PAL_OUTPUT_TYPE_OPENDRAIN _Static_assert(0, "RP2040 has no Open Drain GPIO configuration, setting this is not possible");

/* Aliases for GPIO PWM channels - every pin has at least one PWM channel
 * assigned */
#    define RP2040_PWM_CHANNEL_A 1U
#    define RP2040_PWM_CHANNEL_B 2U

#    ifndef BACKLIGHT_PAL_MODE
#        define BACKLIGHT_PAL_MODE (PAL_MODE_ALTERNATE_PWM | PAL_RP_PAD_DRIVE12 | PAL_RP_GPIO_OE)
#    endif
#    define BACKLIGHT_PWM_COUNTER_FREQUENCY 1000000
#    define BACKLIGHT_PWM_PERIOD BACKLIGHT_PWM_COUNTER_FREQUENCY / 2048

#    ifndef AUDIO_PWM_PAL_MODE
#        define AUDIO_PWM_PAL_MODE (PAL_MODE_ALTERNATE_PWM | PAL_RP_PAD_DRIVE12 | PAL_RP_GPIO_OE)
#    endif
#    define AUDIO_PWM_COUNTER_FREQUENCY 500000

#    define usb_lld_endpoint_fields

#    ifndef I2C1_SCL_PAL_MODE
#        define I2C1_SCL_PAL_MODE (PAL_MODE_ALTERNATE_I2C | PAL_RP_PAD_SLEWFAST | PAL_RP_PAD_PUE | PAL_RP_PAD_DRIVE4)
#    endif
#    ifndef I2C1_SDA_PAL_MODE
#        define I2C1_SDA_PAL_MODE (PAL_MODE_ALTERNATE_I2C | PAL_RP_PAD_SLEWFAST | PAL_RP_PAD_PUE | PAL_RP_PAD_DRIVE4)
#    endif

#    define USE_I2CV1_CONTRIB
#    if !defined(I2C1_CLOCK_SPEED)
#        define I2C1_CLOCK_SPEED 400000
#    endif

#    ifndef SPI_SCK_PAL_MODE
#        define SPI_SCK_PAL_MODE (PAL_MODE_ALTERNATE_SPI | PAL_RP_PAD_SLEWFAST | PAL_RP_PAD_DRIVE4)
#    endif
#    ifndef SPI_MOSI_PAL_MODE
#        define SPI_MOSI_PAL_MODE (PAL_MODE_ALTERNATE_SPI | PAL_RP_PAD_SLEWFAST | PAL_RP_PAD_DRIVE4)
#    endif
#    ifndef SPI_MISO_PAL_MODE
#        define SPI_MISO_PAL_MODE (PAL_MODE_ALTERNATE_SPI | PAL_RP_PAD_SLEWFAST | PAL_RP_PAD_DRIVE4)
#    endif
#endif

// STM32 compatibility
#if defined(MCU_STM32)
#    if defined(STM32_CORE_CK)
#        define CPU_CLOCK STM32_CORE_CK
#    else
#        define CPU_CLOCK STM32_SYSCLK
#    endif

#    if defined(STM32F1XX)
#        define USE_GPIOV1
#        define PAL_MODE_ALTERNATE_OPENDRAIN PAL_MODE_STM32_ALTERNATE_OPENDRAIN
#        define PAL_MODE_ALTERNATE_PUSHPULL PAL_MODE_STM32_ALTERNATE_PUSHPULL
#        define AUDIO_PWM_PAL_MODE PAL_MODE_ALTERNATE_PUSHPULL
#    else
#        define PAL_OUTPUT_TYPE_OPENDRAIN PAL_STM32_OTYPE_OPENDRAIN
#        define PAL_OUTPUT_TYPE_PUSHPULL PAL_STM32_OTYPE_PUSHPULL
#        define PAL_OUTPUT_SPEED_HIGHEST PAL_STM32_OSPEED_HIGHEST
#        define PAL_PUPDR_FLOATING PAL_STM32_PUPDR_FLOATING
#    endif

#    if defined(STM32F1XX) || defined(STM32F2XX) || defined(STM32F4XX) || defined(STM32L1XX)
#        define USE_I2CV1
#    endif
#endif

// GD32 compatibility
#if defined(MCU_GD32V)
#    define CPU_CLOCK GD32_SYSCLK

#    if defined(GD32VF103)
#        define USE_GPIOV1
#        define USE_I2CV1
#        define PAL_MODE_ALTERNATE_OPENDRAIN PAL_MODE_GD32_ALTERNATE_OPENDRAIN
#        define PAL_MODE_ALTERNATE_PUSHPULL PAL_MODE_GD32_ALTERNATE_PUSHPULL
#        define AUDIO_PWM_PAL_MODE PAL_MODE_GD32_ALTERNATE_PUSHPULL
#    endif
#endif

// WB32 compatibility
#if defined(MCU_WB32)
#    define CPU_CLOCK WB32_MAINCLK

#    if defined(WB32F3G71xx) || defined(WB32FQ95xx)
#        define PAL_OUTPUT_TYPE_OPENDRAIN PAL_WB32_OTYPE_OPENDRAIN
#        define PAL_OUTPUT_TYPE_PUSHPULL PAL_WB32_OTYPE_PUSHPULL
#        define PAL_OUTPUT_SPEED_HIGHEST PAL_WB32_OSPEED_HIGH
#        define PAL_PUPDR_FLOATING PAL_WB32_PUPDR_FLOATING

#        define SPI_SCK_FLAGS PAL_MODE_ALTERNATE(SPI_SCK_PAL_MODE) | PAL_OUTPUT_TYPE_PUSHPULL | PAL_OUTPUT_SPEED_HIGHEST | PAL_WB32_CURRENT_LEVEL3
#    endif
#endif

// AIR32 compatibility
#if defined(MCU_AIR32)
#    define CPU_CLOCK AIR32_SYSCLK

#    if defined(AIR32F10x)
#        define MCU_STM32 // the same registers as stm32
#        define USE_GPIOV1
#        define USE_I2CV1
#        define PAL_MODE_ALTERNATE_OPENDRAIN PAL_MODE_AIR32_ALTERNATE_OPENDRAIN
#        define PAL_MODE_ALTERNATE_PUSHPULL PAL_MODE_AIR32_ALTERNATE_PUSHPULL
#        define AUDIO_PWM_PAL_MODE PAL_MODE_ALTERNATE_PUSHPULL
#        define STM32_DMA_STREAM(stream) AIR32_DMA_STREAM(stream)
#        define STM32_DMA_STREAM_ID(peripheral, channel) AIR32_DMA_STREAM_ID(peripheral, channel)
#        define STM32_DMA_CR_DIR_M2P AIR32_DMA_CR_DIR_M2P
#        define STM32_DMA_CR_MSIZE_BYTE AIR32_DMA_CR_MSIZE_BYTE
#        define STM32_DMA_CR_PSIZE_WORD AIR32_DMA_CR_PSIZE_WORD
#        define STM32_DMA_CR_PSIZE_HWORD AIR32_DMA_CR_PSIZE_HWORD
#        define STM32_DMA_CR_MINC AIR32_DMA_CR_MINC
#        define STM32_DMA_CR_CIRC AIR32_DMA_CR_CIRC
#        define STM32_DMA_CR_PL AIR32_DMA_CR_PL
#        define STM32_DMA_CR_CHSEL AIR32_DMA_CR_CHSEL
#    endif
#endif

// AT32 compatibility
#if defined(MCU_AT32)
#    define CPU_CLOCK AT32_SYSCLK
#    define MCU_STM32 // the same registers as stm32

#    define TIM_DIER_UDE AT32_TMR_IDEN_OVFDEN
#    define TIM_DIER_TDE AT32_TMR_IDEN_TDEN
#    define STM32_PWM_USE_ADVANCED AT32_PWM_USE_ADVANCED
#    define CCR CDT
#    define dier iden
#    define tim tmr

#    define STM32_DMA_STREAM(stream) AT32_DMA_STREAM(stream)
#    define STM32_DMA_STREAM_ID(peripheral, channel) AT32_DMA_STREAM_ID(peripheral, channel)
#    define STM32_DMA_CR_DIR_M2P AT32_DMA_CTRL_DTD_M2P
#    define STM32_DMA_CR_MSIZE_BYTE AT32_DMA_CTRL_MWIDTH_BYTE
#    define STM32_DMA_CR_PSIZE_WORD AT32_DMA_CTRL_PWIDTH_WORD
#    define STM32_DMA_CR_PSIZE_HWORD AT32_DMA_CTRL_PWIDTH_HWORD
#    define STM32_DMA_CR_MINC AT32_DMA_CTRL_MINCM
#    define STM32_DMA_CR_CIRC AT32_DMA_CTRL_LM
#    define STM32_DMA_CR_PL AT32_DMA_CTRL_CHPL
#    define STM32_DMA_CR_CHSEL AT32_DMA_CTRL_CHSEL

#    define cr1 ctrl1
#    define cr2 ctrl2
#    define cr3 ctrl3

#    if HAL_USE_ADC
#        define smpr1 spt1
#        define smpr2 spt2

#        define sqr1 osq1
#        define sqr2 osq2
#        define sqr3 osq3

#        define ADC_SMPR2_SMP_AN0 ADC_SPT2_CSPT0
#        define ADC_SMPR2_SMP_AN1 ADC_SPT2_CSPT1
#        define ADC_SMPR2_SMP_AN2 ADC_SPT2_CSPT2
#        define ADC_SMPR2_SMP_AN3 ADC_SPT2_CSPT3
#        define ADC_SMPR2_SMP_AN4 ADC_SPT2_CSPT4
#        define ADC_SMPR2_SMP_AN5 ADC_SPT2_CSPT5
#        define ADC_SMPR2_SMP_AN6 ADC_SPT2_CSPT6
#        define ADC_SMPR2_SMP_AN7 ADC_SPT2_CSPT7
#        define ADC_SMPR2_SMP_AN8 ADC_SPT2_CSPT8
#        define ADC_SMPR2_SMP_AN9 ADC_SPT2_CSPT9
#        define ADC_SMPR1_SMP_AN10 ADC_SPT1_CSPT10
#        define ADC_SMPR1_SMP_AN11 ADC_SPT1_CSPT11
#        define ADC_SMPR1_SMP_AN12 ADC_SPT1_CSPT12
#        define ADC_SMPR1_SMP_AN13 ADC_SPT1_CSPT13
#        define ADC_SMPR1_SMP_AN14 ADC_SPT1_CSPT14
#        define ADC_SMPR1_SMP_AN15 ADC_SPT1_CSPT15
#        define ADC_SQR3_SQ1_N ADC_OSQ3_OSN1_N
#        if defined(AT32F435_7xx) || defined(AT32F423xx)
#            define ADC_SMPR_SMP_1P5 ADC_SAMPLE_2P5
#            define ADC_SMPR_SMP_7P5 ADC_SAMPLE_6P5
#            define ADC_SMPR_SMP_13P5 ADC_SAMPLE_12P5
#            define ADC_SMPR_SMP_28P5 ADC_SAMPLE_24P5
#            define ADC_SMPR_SMP_41P5 ADC_SAMPLE_47P5
#            define ADC_SMPR_SMP_55P5 ADC_SAMPLE_92P5
#            define ADC_SMPR_SMP_71P5 ADC_SAMPLE_247P5
#            define ADC_SMPR_SMP_239P5 ADC_SAMPLE_640P5
#        endif
#        if defined(AT32F423xx)
#            define smpr3 spt3
#            define sqr4 osq4
#            define sqr5 osq5
#            define sqr6 osq6
#            define ADC_SMPR3_SMP_AN20 ADC_SPT1_CSPT20
#            define ADC_SMPR3_SMP_AN21 ADC_SPT1_CSPT21
#            define ADC_SMPR3_SMP_AN22 ADC_SPT1_CSPT22
#            define ADC_SMPR3_SMP_AN23 ADC_SPT1_CSPT23
#            define ADC_SMPR3_SMP_AN24 ADC_SPT1_CSPT24
#            define ADC_SMPR3_SMP_AN25 ADC_SPT1_CSPT25
#            define ADC_SMPR3_SMP_AN26 ADC_SPT1_CSPT26
#            define ADC_SMPR3_SMP_AN27 ADC_SPT1_CSPT27
#        endif
#    endif

#    if HAL_USE_SERIAL
#        if !defined(SERIAL_USART_CR1)
#            define SERIAL_USART_CR1 (USART_CTRL1_PEN | USART_CTRL1_PSEL | USART_CTRL1_DBN)
#        endif
#        if !defined(SERIAL_USART_CR2)
#            define SERIAL_USART_CR2 USART_CTRL2_STOPBN_2_BITS
#        endif
#        if !defined(SERIAL_USART_CR3)
#            define SERIAL_USART_CR3 0x0
#        endif
#        define USART_CR3_HDSEL USART_CTRL3_SLBEN

#    endif

#    if defined(AT32F415xx) || defined(AT32F413xx) || defined(AT32F403_7xx)
#        define USE_GPIOV1
#        define USE_I2CV1
#        define PAL_MODE_ALTERNATE_OPENDRAIN PAL_MODE_AT32_ALTERNATE_OPENDRAIN
#        define PAL_MODE_ALTERNATE_PUSHPULL PAL_MODE_AT32_ALTERNATE_PUSHPULL
#        define AUDIO_PWM_PAL_MODE PAL_MODE_ALTERNATE_PUSHPULL

#        if HAL_USE_SERIAL
#            define AFIO IOMUX
#            define MAPR REMAP
#            define AFIO_MAPR_USART1_REMAP IOMUX_REMAP_USART1_MUX
#            define AFIO_MAPR_USART3_REMAP_PARTIALREMAP IOMUX_REMAP_USART3_MUX_PARTIALREMAP
#            define AFIO_MAPR_USART3_REMAP_FULLREMAP IOMUX_REMAP_USART3_MUX_FULLREMAP
#        endif

#    endif

#    if defined(AT32F402_5xx) || defined(AT32F435_7xx) || defined(AT32F423xx)
#        define PAL_OUTPUT_TYPE_OPENDRAIN PAL_AT32_OMODE_OPENDRAIN
#        define PAL_OUTPUT_TYPE_PUSHPULL PAL_AT32_OMODE_PUSHPULL
#        define PAL_OUTPUT_SPEED_HIGHEST PAL_AT32_ODRV_STRONGER
#        define PAL_PUPDR_FLOATING PAL_AT32_PULL_FLOATING

#        if HAL_USE_ADC
#            define ADC_CR2_SWSTART ADC_CTRL2_OCSWTRG
#        endif

#        if HAL_USE_SERIAL
#            if !defined(USART_CR1_M0)
#                define USART_CR1_M0 USART_CTRL1_DBN0
#            endif
#            define USART_CR2_SWAP USART_CTRL2_TRPSWAP
#        endif

#    endif

#endif

#if defined(GD32VF103)
/* This chip has the same API as STM32F103, but uses different names for literally the same thing.
 * As of 4.7.2021 QMK is tailored to use STM32 defines/names, for compatibility sake
 * we just redefine the GD32 names. */
#    include "gd32v_compatibility.h"
#endif

// teensy compatibility
#if defined(MCU_KINETIS)
#    define CPU_CLOCK KINETIS_SYSCLK_FREQUENCY

#    if defined(K20x) || defined(K60x) || defined(KL2x)
#        define USE_I2CV1
#        define USE_I2CV1_CONTRIB // for some reason a bunch of ChibiOS-Contrib boards only have clock_speed
#        define USE_GPIOV1
#    endif
#endif

#if defined(MCU_MIMXRT1062)
#    include "clock_config.h"
#    define CPU_CLOCK BOARD_BOOTCLOCKRUN_CORE_CLOCK
#endif

#if defined(HT32)
#    define CPU_CLOCK HT32_CK_SYS_FREQUENCY
#    define PAL_MODE_ALTERNATE PAL_HT32_MODE_AF
#    define PAL_OUTPUT_TYPE_OPENDRAIN (PAL_HT32_MODE_OD | PAL_HT32_MODE_DIR)
#    define PAL_OUTPUT_TYPE_PUSHPULL PAL_HT32_MODE_DIR
#    define PAL_OUTPUT_SPEED_HIGHEST 0
#endif

#if !defined(REALTIME_COUNTER_CLOCK)
#    define REALTIME_COUNTER_CLOCK CPU_CLOCK
#endif

// SPI Fallbacks
#ifndef SPI_SCK_FLAGS
#    define SPI_SCK_FLAGS PAL_MODE_ALTERNATE(SPI_SCK_PAL_MODE) | PAL_OUTPUT_TYPE_PUSHPULL | PAL_OUTPUT_SPEED_HIGHEST
#endif

#ifndef SPI_MOSI_FLAGS
#    define SPI_MOSI_FLAGS PAL_MODE_ALTERNATE(SPI_MOSI_PAL_MODE) | PAL_OUTPUT_TYPE_PUSHPULL | PAL_OUTPUT_SPEED_HIGHEST
#endif

#ifndef SPI_MISO_FLAGS
#    define SPI_MISO_FLAGS PAL_MODE_ALTERNATE(SPI_MISO_PAL_MODE) | PAL_OUTPUT_TYPE_PUSHPULL | PAL_OUTPUT_SPEED_HIGHEST
#endif
