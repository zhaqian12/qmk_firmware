static HSV STT_WIDE_RAINBOW_GRADIENT_math(HSV hsv, uint8_t i, uint8_t time) {
    hsv.h = (g_led_config.point[i].x / 3) - time;
    return hsv;
}

// e.g: A simple effect, self-contained within a single method
static bool STT_WIDE_RAINBOW_GRADIENT(effect_params_t* params) {
  return effect_runner_i(params, &STT_WIDE_RAINBOW_GRADIENT_math);
}
