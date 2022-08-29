#include "quantum.h"
#include "raw_hid.h"

void hidrgb_hid_receive(uint8_t *data, uint8_t length) {
    bool send = false;
    switch (*data) {
#ifdef OPENRGB_ENABLE
        case 1 ... 9: {
            send = openrgb_command_handler(data, length); 
            break;
        }
#endif
#ifdef SIGNALRGB_ENABLE
        case id_signalrgb_prefix: {
            send = signal_rgb_command_handler(data, length);
            break;
        }
#endif
        default: {
            // id_unhandled
            break;
        }
    }
    if (send) {
        hidrgb_hid_send(data, length);
    }
}