/* Copyright 2023 zhaqian
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

#include "quantum.h"

#ifndef DEFAULT_WINDOWS_FN_LAYER
#    define DEFAULT_WINDOWS_FN_LAYER 1
#endif

#ifndef DEFAULT_MACOS_FN_LAYER
#    define DEFAULT_MACOS_FN_LAYER 3
#endif

#define WINDOWS_FN DEFAULT_WINDOWS_FN_LAYER
#define MACOS_FN DEFAULT_MACOS_FN_LAYER

#ifdef AUTO_SWITCH_LAYERS_ENABLE

typedef struct __attribute__((packed)) {
    uint8_t windows_layer;
    // uint8_t windows_fn_layer;
    uint8_t macos_layer;
    // uint8_t macos_fn_layer;
} system_layers_t;

extern system_layers_t system_layers;

void eeconfig_read_auto_switch_layers(void);
void eeconfig_update_auto_switch_layers(void);
void auto_switch_layers_init(void);
void auto_switch_layers_task(void);

#define AUTO_SWITCH_LAYERS_SET(var, val)    \
do {                                        \
    system_layers.var = val;                \
    auto_switch_layers_task();              \
} while (0)

#define AUTO_SWITCH_LAYERS_GET(var) system_layers.var

// #define WINDOWS_FN (system_layers.windows_fn_layer)
// #define MACOS_FN (system_layers.macos_fn_layer)

#endif