/* Copyright 2020 QMK
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

#undef AT32_PWM_USE_TMR1
#define AT32_PWM_USE_TMR1 TRUE

#undef AT32_USB_USE_OTG1
#define AT32_USB_USE_OTG1                     FALSE

#undef AT32_USB_USE_OTG2
#define AT32_USB_USE_OTG2                     TRUE

#define AT32_EDMA_REQUIRED TRUE

#undef AT32_USBCLK_SRC
#define AT32_USBCLK_SRC AT32_USBCLK_SRC_HICK    

#undef AT32_HEXT_ENABLED                  
#define AT32_HEXT_ENABLED                     FALSE

#undef AT32_PLLRCS 
#define AT32_PLLRCS AT32_PLLRCS_HICK