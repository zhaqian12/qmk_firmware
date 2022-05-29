#if defined(ENABLE_RGB_MATRIX_H_STACK) || defined(ENABLE_RGB_MATRIX_V_STACK)

#ifdef ENABLE_RGB_MATRIX_H_STACK
RGB_MATRIX_EFFECT(H_STACK)
#endif

#ifdef ENABLE_RGB_MATRIX_V_STACK
RGB_MATRIX_EFFECT(V_STACK)
#endif

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static uint8_t stack_hue_step = 0;
static double stack_progress = 0.f;

#ifdef ENABLE_RGB_MATRIX_H_STACK
static uint8_t stack_stop_h = 27;
static bool stack_flag_h = false;
#endif

#ifdef ENABLE_RGB_MATRIX_V_STACK
static uint8_t stack_stop_v = 7;
static bool stack_flag_v = false;
#endif

void STACK_update(uint8_t index) {
    float delta_progress = rgb_matrix_config.speed / 50000.0;
#ifdef ENABLE_RGB_MATRIX_H_STACK
    if (index == 0) {
        stack_progress += delta_progress * 28;
        if(stack_progress >= stack_stop_h) {
            if (stack_flag_h) {
                stack_stop_h ++;
            } else {
                stack_stop_h --;
            }
            if(stack_stop_h == 0) {
                stack_flag_h = true;
                stack_progress = 0.f;
            }
            if (stack_stop_h == 27) {
                stack_flag_h = false;
                stack_progress = 0.f;
                stack_hue_step += 5;
            }
            stack_progress = 0.f;
        }
    }
#endif
#ifdef ENABLE_RGB_MATRIX_V_STACK
    if (index == 1) {
        stack_progress += delta_progress * 7;
        if(stack_progress >= stack_stop_v) {
            if (stack_flag_v) {
                stack_stop_v ++;
            } else {
                stack_stop_v --;
            }
            if(stack_stop_v == 0) {
                stack_flag_v = true;
                stack_progress = 0.f;
            }
            if (stack_stop_v == 7) {
                stack_flag_v = false;
                stack_progress = 0.f;
                stack_hue_step += 5;
            }
            stack_progress = 0.f;
        }
    }
#endif
}

#ifdef ENABLE_RGB_MATRIX_H_STACK
HSV H_STACK_math(HSV hsv, uint8_t i, uint8_t col, uint8_t row) {
    if(stack_stop_h < col)
    {
        hsv.h = stack_hue_step;
        return hsv;
    }
    float distance = 0;
    if (stack_flag_h) {
        distance = fabs(col - stack_stop_h + stack_progress);
    } else {
        distance = fabs(stack_progress - col);
    }
    if(distance > 1)
    {
        hsv.v = 0;
    }
    hsv.v *= 1 - distance / 2.0;
    hsv.h = stack_hue_step;
    return hsv;
}

bool H_STACK(effect_params_t* params) {
    STACK_update(0);
    return effect_runner_col_row(params, &H_STACK_math);
}
#endif

#ifdef ENABLE_RGB_MATRIX_V_STACK
HSV V_STACK_math(HSV hsv, uint8_t i, uint8_t col, uint8_t row) {
    if(stack_stop_v < row)
    {
        hsv.h = stack_hue_step;
        return hsv;
    }
    float distance = 0;
    if (stack_flag_v) {
        distance = fabs(row - stack_stop_v + stack_progress);
    } else {
        distance = fabs(stack_progress - row);
    }
    if(distance > 1)
    {
        hsv.v = 0;
    }
    hsv.v *= 1 - distance;
    hsv.h = stack_hue_step;
    return hsv;
}

bool V_STACK(effect_params_t* params) {
    STACK_update(1);
    return effect_runner_col_row(params, &V_STACK_math);
}
#endif

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif
