/* Copyright 2022 zhaqian
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

#include <stdint.h>
#include <stdbool.h>

#include "spi_master.h"

#ifndef ST7789_SCL_PIN
#    define ST7789_SCL_PIN B13
#endif

#ifndef ST7789_SDA_PIN
#    define ST7789_SDA_PIN B15
#endif

#ifndef ST7789_RES_PIN
#    define ST7789_RES_PIN B0
#endif

#ifndef ST7789_DC_PIN
#    define ST7789_DC_PIN B1
#endif

#ifndef ST7789_CS_PIN
#    define ST7789_CS_PIN B12
#endif

#ifndef ST7789_BLK_PIN
#    define ST7789_BLK_PIN B4
#endif

#define SPI_SCK_PIN ST7789_SCL_PIN

#define SPI_MOSI_PIN ST7789_SDA_PIN

#ifndef ST7789_DISPLAY_WIDTH
#    define ST7789_DISPLAY_WIDTH 240
#endif

#ifndef ST7789_DISPLAY_HEIGHT
#    define ST7789_DISPLAY_HEIGHT 135
#endif

#ifndef ST7789_MATRIX_SIZE
#    define ST7789_MATRIX_SIZE (ST7789_DISPLAY_HEIGHT / 15 * ST7789_DISPLAY_WIDTH) // 9 * 240
#endif

#ifndef ST7789_BLOCK_TYPE
#    define ST7789_BLOCK_TYPE uint16_t
#endif

#ifndef ST7789_BLOCK_COUNT
#    define ST7789_BLOCK_COUNT (sizeof(ST7565_BLOCK_TYPE) * 8) // 32 (compile time mathed)
#endif

#ifndef ST7789_BLOCK_SIZE
#    define ST7789_BLOCK_SIZE (ST7565_MATRIX_SIZE / ST7565_BLOCK_COUNT) // 32 (compile time mathed)
#endif

// the column address corresponding to the first column in the display hardware
#if !defined(ST7565_COLUMN_OFFSET)
#    define ST7565_COLUMN_OFFSET 0
#endif

// spi clock divisor
#if !defined(ST7565_SPI_CLK_DIVISOR)
#    define ST7565_SPI_CLK_DIVISOR 4
#endif

// Custom font file to use
#if !defined(ST7565_FONT_H)
#    define ST7565_FONT_H "glcdfont.c"
#endif
// unsigned char value of the first character in the font file
#if !defined(ST7565_FONT_START)
#    define ST7565_FONT_START 0
#endif
// unsigned char value of the last character in the font file
#if !defined(ST7565_FONT_END)
#    define ST7565_FONT_END 223
#endif
// Font render width
#if !defined(ST7565_FONT_WIDTH)
#    define ST7565_FONT_WIDTH 6
#endif
// Font render height
#if !defined(ST7565_FONT_HEIGHT)
#    define ST7565_FONT_HEIGHT 8
#endif
// Default contrast level
#if !defined(ST7565_CONTRAST)
#    define ST7565_CONTRAST 32
#endif

#if !defined(ST7565_TIMEOUT)
#    if defined(ST7565_DISABLE_TIMEOUT)
#        define ST7565_TIMEOUT 0
#    else
#        define ST7565_TIMEOUT 60000
#    endif
#endif

#if !defined(ST7565_UPDATE_INTERVAL) && defined(SPLIT_KEYBOARD)
#    define ST7565_UPDATE_INTERVAL 50
#endif
