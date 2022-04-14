#ifdef ENABLE_RGB_MATRIX_BLOOM
RGB_MATRIX_EFFECT(BLOOM)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

typedef struct {
    uint8_t speed;
    HSV hsv;
} flower_t;

static flower_t flowers[224];
static bool reset = false;

void BLOOM_reset(void) {
    for(uint8_t i = 0; i < 224; i++)
    {
        flowers[i].hsv = rgb_matrix_config.hsv;
        flowers[i].hsv.h = rand() % 255;
        flowers[i].speed = rand() % 100 + 100;
    }
}

HSV BLOOM_math(HSV hsv, uint8_t i, uint8_t col, uint8_t row) {
    uint8_t id = row * 28 + col;
    flowers[id].hsv.v = hsv.v;
    flowers[id].hsv.s = hsv.s;
    flowers[id].hsv.h += (flowers[i].speed * rgb_matrix_config.speed / 6000.0);
    return flowers[id].hsv;
}

bool BLOOM(effect_params_t* params) {
    if (!reset) {
        BLOOM_reset();
        reset = true;
    }
    return effect_runner_col_row(params, &BLOOM_math);
}

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
