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

#include "auto_switch_layers.h"
#include "os_detection.h"
#include "eeprom.h"

system_layers_t system_layers;

#ifndef DEFAULT_WINDOWS_LAYER
#    define DEFAULT_WINDOWS_LAYER 0
#endif

#ifndef DEFAULT_MACOS_LAYER
#    define DEFAULT_MACOS_LAYER 2
#endif

void eeconfig_read_auto_switch_layers(void) {
    eeprom_read_block(&system_layers, EECONFIG_AUTO_SWITCH_LAYERS, sizeof(system_layers));
}

void eeconfig_update_auto_switch_layers(void) {
    eeprom_update_block(&system_layers, EECONFIG_AUTO_SWITCH_LAYERS, sizeof(system_layers));
}

void eeconfig_update_auto_switch_layers_default(void) {
    system_layers.windows_layer = DEFAULT_WINDOWS_LAYER;
    // system_layers.windows_fn_layer = DEFAULT_WINDOWS_FN_LAYER;
    system_layers.macos_layer = DEFAULT_MACOS_LAYER;
    // system_layers.macos_fn_layer = DEFAULT_MACOS_FN_LAYER;
    eeconfig_update_auto_switch_layers();
};

void auto_switch_layers_init(void) {
    if (!eeconfig_is_enabled()) {
        eeconfig_init();
        eeconfig_update_auto_switch_layers_default();
    }
    eeconfig_read_auto_switch_layers();
    auto_switch_layers_task();
}

void auto_switch_layers_task(void) {
    os_variant_t os = detected_host_os();
    switch (os) {
        case OS_WINDOWS: {
            default_layer_set(system_layers.windows_layer);
            break;
        }
        case OS_MACOS: {
            default_layer_set(system_layers.macos_layer);
            break;
        }
        default: {
            default_layer_set(0);
            break;
        }
    }
}
