#include "graphics/src/djinn.qgf.c"
#include "graphics/src/lock-caps-ON.qgf.c"
#include "graphics/src/lock-scrl-ON.qgf.c"
#include "graphics/src/lock-num-ON.qgf.c"
#include "graphics/src/lock-caps-OFF.qgf.c"
#include "graphics/src/lock-scrl-OFF.qgf.c"
#include "graphics/src/lock-num-OFF.qgf.c"
#include "graphics/src/thintel15.qff.c"

static painter_image_handle_t djinn_logo;
static painter_image_handle_t lock_caps_on;
static painter_image_handle_t lock_caps_off;
static painter_image_handle_t lock_num_on;
static painter_image_handle_t lock_num_off;
static painter_image_handle_t lock_scrl_on;
static painter_image_handle_t lock_scrl_off;
static painter_font_handle_t  thintel;

//----------------------------------------------------------
// RGB Matrix naming
#include <rgb_matrix.h>

#if defined(RGB_MATRIX_EFFECT)
#    undef RGB_MATRIX_EFFECT
#endif  // defined(RGB_MATRIX_EFFECT)

#define RGB_MATRIX_EFFECT(x) RGB_MATRIX_EFFECT_##x,
enum {
    RGB_MATRIX_EFFECT_NONE,
#include "rgb_matrix_effects.inc"
#undef RGB_MATRIX_EFFECT
#ifdef RGB_MATRIX_CUSTOM_KB
#    include "rgb_matrix_kb.inc"
#endif
#ifdef RGB_MATRIX_CUSTOM_USER
#    include "rgb_matrix_user.inc"
#endif
};

#define RGB_MATRIX_EFFECT(x)    \
    case RGB_MATRIX_EFFECT_##x: \
        return #x;
const char *rgb_matrix_name(uint8_t effect) {
    switch (effect) {
        case RGB_MATRIX_EFFECT_NONE:
            return "NONE";
#include "rgb_matrix_effects.inc"
#undef RGB_MATRIX_EFFECT
#ifdef RGB_MATRIX_CUSTOM_KB
#    include "rgb_matrix_kb.inc"
#endif
#ifdef RGB_MATRIX_CUSTOM_USER
#    include "rgb_matrix_user.inc"
#endif
        default:
            return "UNKNOWN";
    }
}

//----------------------------------------------------------
// UI Initialisation
void keyboard_post_init_display(void) {
    djinn_logo    = qp_load_image_mem(gfx_djinn);
    lock_caps_on  = qp_load_image_mem(gfx_lock_caps_ON);
    lock_caps_off = qp_load_image_mem(gfx_lock_caps_OFF);
    lock_num_on   = qp_load_image_mem(gfx_lock_num_ON);
    lock_num_off  = qp_load_image_mem(gfx_lock_num_OFF);
    lock_scrl_on  = qp_load_image_mem(gfx_lock_scrl_ON);
    lock_scrl_off = qp_load_image_mem(gfx_lock_scrl_OFF);
    thintel       = qp_load_font_mem(font_thintel15);
}

//----------------------------------------------------------
// UI Drawing
void draw_ui_user(void) {
    bool            hue_redraw = false;
    static uint16_t last_hue   = 0xFFFF;
    uint8_t         curr_hue   = rgblight_get_hue();
    if (last_hue != curr_hue) {
        last_hue   = curr_hue;
        hue_redraw = true;
    }

    bool            layer_state_redraw = false;
    static uint32_t last_layer_state   = 0;
    if (last_layer_state != layer_state) {
        last_layer_state   = layer_state;
        layer_state_redraw = true;
    }

    bool                     power_state_redraw = false;
    static usbpd_allowance_t last_current_state = (usbpd_allowance_t)(~0);
    if (last_current_state != kb_state.current_setting) {
        last_current_state = kb_state.current_setting;
        power_state_redraw = true;
    }

    bool            scan_redraw      = false;
    static uint32_t last_scan_update = 0;
    if (timer_elapsed32(last_scan_update) > 125) {
        last_scan_update = timer_read32();
        scan_redraw      = true;
    }

    bool            wpm_redraw      = false;
    static uint32_t last_wpm_update = 0;
    if (timer_elapsed32(last_wpm_update) > 125) {
        last_wpm_update = timer_read32();
        wpm_redraw      = true;
    }

#if defined(RGB_MATRIX_ENABLE)
    bool            rgb_effect_redraw = false;
    static uint16_t last_effect       = 0xFFFF;
    uint8_t         curr_effect       = rgb_matrix_config.mode;
    if (last_effect != curr_effect) {
        last_effect       = curr_effect;
        rgb_effect_redraw = true;
    }
#endif  // defined(RGB_MATRIX_ENABLE)

    // Show the Djinn logo and two vertical bars on both sides
    if (hue_redraw) {
        qp_drawimage_recolor(lcd, 120 - djinn_logo->width / 2, 32, djinn_logo, curr_hue, 255, 255, curr_hue, 255, 0);
        qp_rect(lcd, 0, 0, 8, 319, curr_hue, 255, 255, true);
        qp_rect(lcd, 231, 0, 239, 319, curr_hue, 255, 255, true);
    }

    int ypos = 4;

    // Show layer info on the left side
    if (is_keyboard_left()) {
        char buf[32] = {0};
        int  xpos    = 16;

#if defined(RGB_MATRIX_ENABLE)
        if (hue_redraw || rgb_effect_redraw) {
            static int max_rgb_xpos = 0;
            xpos                    = 16;
            snprintf_(buf, sizeof(buf), "rgb: %s", rgb_matrix_name(curr_effect));

            for (int i = 5; i < sizeof(buf); ++i) {
                if (buf[i] == 0)
                    break;
                else if (buf[i] == '_')
                    buf[i] = ' ';
                else if (buf[i - 1] == ' ')
                    buf[i] = toupper(buf[i]);
                else if (buf[i - 1] != ' ')
                    buf[i] = tolower(buf[i]);
            }

            xpos += qp_drawtext_recolor(lcd, xpos, ypos, thintel, buf, curr_hue, 255, 255, curr_hue, 255, 0);
            if (max_rgb_xpos < xpos) {
                max_rgb_xpos = xpos;
            }
            qp_rect(lcd, xpos, ypos, max_rgb_xpos, ypos + thintel->line_height, 0, 0, 0, true);
        }

        ypos += thintel->line_height + 4;
#endif  // defined(RGB_MATRIX_ENABLE)

        if (hue_redraw || layer_state_redraw) {
            const char *layer_name = "unknown";
            switch (get_highest_layer(layer_state)) {
                case _QWERTY:
                    layer_name = "qwerty";
                    break;
                case _LOWER:
                    layer_name = "lower";
                    break;
                case _RAISE:
                    layer_name = "raise";
                    break;
                case _ADJUST:
                    layer_name = "adjust";
                    break;
            }

            static int max_layer_xpos = 0;
            xpos                      = 16;
            snprintf_(buf, sizeof(buf), "layer: %s", layer_name);
            xpos += qp_drawtext_recolor(lcd, xpos, ypos, thintel, buf, curr_hue, 255, 255, curr_hue, 255, 0);
            if (max_layer_xpos < xpos) {
                max_layer_xpos = xpos;
            }
            qp_rect(lcd, xpos, ypos, max_layer_xpos, ypos + thintel->line_height, 0, 0, 0, true);
        }

        ypos += thintel->line_height + 4;

        if (hue_redraw || power_state_redraw) {
            static int max_power_xpos = 0;
            xpos                      = 16;
            snprintf_(buf, sizeof(buf), "power: %s", usbpd_str(kb_state.current_setting));
            xpos += qp_drawtext_recolor(lcd, xpos, ypos, thintel, buf, curr_hue, 255, 255, curr_hue, 255, 0);
            if (max_power_xpos < xpos) {
                max_power_xpos = xpos;
            }
            qp_rect(lcd, xpos, ypos, max_power_xpos, ypos + thintel->line_height, 0, 0, 0, true);
        }

        ypos += thintel->line_height + 4;

        if (hue_redraw || scan_redraw) {
            static int max_scans_xpos = 0;
            xpos                      = 16;
            snprintf_(buf, sizeof(buf), "scans: %d", (int)user_state.scan_rate);
            xpos += qp_drawtext_recolor(lcd, xpos, ypos, thintel, buf, curr_hue, 255, 255, curr_hue, 255, 0);
            if (max_scans_xpos < xpos) {
                max_scans_xpos = xpos;
            }
            qp_rect(lcd, xpos, ypos, max_scans_xpos, ypos + thintel->line_height, 0, 0, 0, true);
        }

        ypos += thintel->line_height + 4;

        if (hue_redraw || wpm_redraw) {
            static int max_wpm_xpos = 0;
            xpos                    = 16;
            snprintf_(buf, sizeof(buf), "wpm: %d", (int)get_current_wpm());
            xpos += qp_drawtext_recolor(lcd, xpos, ypos, thintel, buf, curr_hue, 255, 255, curr_hue, 255, 0);
            if (max_wpm_xpos < xpos) {
                max_wpm_xpos = xpos;
            }
            qp_rect(lcd, xpos, ypos, max_wpm_xpos, ypos + thintel->line_height, 0, 0, 0, true);
        }

        ypos += thintel->line_height + 4;
    }

    // Show LED lock indicators on the right side
    if (!is_keyboard_left()) {
        static led_t last_led_state = {0};
        if (hue_redraw || last_led_state.raw != host_keyboard_led_state().raw) {
            last_led_state.raw = host_keyboard_led_state().raw;
            qp_drawimage_recolor(lcd, 239 - 12 - (32 * 3), 0, last_led_state.caps_lock ? lock_caps_on : lock_caps_off, curr_hue, 255, last_led_state.caps_lock ? 255 : 32, curr_hue, 255, 0);
            qp_drawimage_recolor(lcd, 239 - 12 - (32 * 2), 0, last_led_state.num_lock ? lock_num_on : lock_num_off, curr_hue, 255, last_led_state.num_lock ? 255 : 32, curr_hue, 255, 0);
            qp_drawimage_recolor(lcd, 239 - 12 - (32 * 1), 0, last_led_state.scroll_lock ? lock_scrl_on : lock_scrl_off, curr_hue, 255, last_led_state.scroll_lock ? 255 : 32, curr_hue, 255, 0);
        }
    }

#if 0
    // Test code
    if (redraw_required) {
        qp_line(lcd, 8, 0, 32, 319, curr_hue, 255, 255);
        qp_line(lcd, 32, 0, 8, 319, curr_hue, 255, 255);
        for (int i = 0; i < 8; ++i) qp_circle(lcd, 20, (i * 40) + 20, 10, curr_hue, 255, 255, (i % 2) == 0);
        qp_drawtext(lcd, 0, 0, font_noto16, "So this is a test of font rendering");
        qp_drawtext_recolor(lcd, 0, font_noto16->line_height, font_noto16, "with Quantum Painter...", 0, 255, 255, 0, 255, 0);
        qp_drawtext_recolor(lcd, 0, 2 * font_noto16->line_height, font_noto16, "Perhaps a different background?", 43, 255, 255, 169, 255, 255);
        qp_drawtext(lcd, 0, 3 * font_noto16->line_height, font_noto28, "Unicode: ĄȽɂɻɣɈʣ");
        qp_drawtext(lcd, 0, 3 * font_noto16->line_height + font_noto28->line_height, thintel, "And here we are, with another font!");
    }
#endif
}