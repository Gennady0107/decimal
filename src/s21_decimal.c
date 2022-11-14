#include "s21_decimal.h"

void print_bit(int x) {
    for (int idx = 31; idx >= 0; idx--)
        printf("%d", x & (1u << idx) ? 1 : 0);
    printf("\n");
}

// -- FOUNDATION --
void s21_init_decimal(s21_decimal** dec) {
    *dec = malloc(sizeof(s21_decimal));
    s21_reset_decimal(*dec);
}

void s21_free_decimal(s21_decimal* dec) {
    free(dec);
}

void s21_reset_decimal(s21_decimal* dec) {
    dec->bits[0] &= 0; // dec->bits[0] = dec->bits[0] & 0;
    dec->bits[1] &= 0;
    dec->bits[2] &= 0;
    dec->bits[3] &= 0;
}

int s21_get_bit(s21_decimal* dec, int idx) {
    return dec->bits[ARR_NUM(idx)] & (1u << ARR_LOC(idx)) ? 1 : 0;
}

void s21_set_bit(s21_decimal* dec, int bit, int idx) {
    if (bit) {
        dec->bits[ARR_NUM(idx)] = dec->bits[ARR_NUM(idx)] | (1 << ARR_LOC(idx));
    } else {
        dec->bits[ARR_NUM(idx)] = dec->bits[ARR_NUM(idx)] & ~(1 << ARR_LOC(idx));
    }
}

void s21_set_negative_sign(s21_decimal* dec) {
    dec->bits[ARR_SIGN] = dec->bits[ARR_SIGN] | SIGN_BIT;
}

void s21_set_positive_sign(s21_decimal* dec) {
    dec->bits[ARR_SIGN] = dec->bits[ARR_SIGN] & ~SIGN_BIT;
}

int s21_get_sign(s21_decimal* dec) {
    int sign = dec->bits[ARR_SIGN] & SIGN_BIT;
    return sign ? 1 : 0;
}

int s21_get_scale(s21_decimal* dec) {
    int scale = dec->bits[ARR_SCALE] & SCALE_BITS;
    scale = SHIFT_SCALE_TO_START(scale);
    return scale;
}

void s21_set_scale(s21_decimal* dec, int scale) {
    dec->bits[ARR_SCALE] = dec->bits[ARR_SCALE] & SIGN_BIT; // reset prev scale bits
    dec->bits[ARR_SCALE] = dec->bits[ARR_SCALE] | SHIFT_SCALE_TO_DEF(scale);
}

int s21_is_correct_decimal(s21_decimal* dec) {
    int res;
    if (dec == NULL) {
        res = 0;
    } else {
        res = 1;
        int service_bit = dec->bits[ARR_SIGN];
        int scale = s21_get_scale(dec);
        if (scale < 0 || scale > 28) {
            res = 0;
        }
        for (int idx = 0; idx < 16 && res; idx++) {
            if (GET_BIT(service_bit, idx) != 0) {
                res = 0;
            }
        }
        for (int idx = 24; idx < 31 && res; idx++) {
            if (GET_BIT(service_bit, idx) != 0) {
                res = 0;
            }
        }
    }
    return res;
}
// -- END FOUNDATION --

// -- CONVERTERS --
int s21_from_int_to_decimal(int src, s21_decimal* dst) {
    int result;
    if (!src) {
        result = CONVERSION_ERROR;
    } else {
        s21_reset_decimal(dst);
        int scale = 0;
        if (src < 0 && src != MIN_INT_NUM) {
            s21_set_negative_sign(dst);
            src = abs(src);
        }
        dst->bits[0] = src;
        s21_set_scale(dst, scale);
        result = OK;
    }
    return result;
}

int s21_get_float_scale(float src) {
    int scale;
    float_exp_notation tmp;
    tmp.fl = src;
    scale = tmp.en & FLOAT_SCALE_BITS;
    scale = SHIFT_FLOAT_SCALE_TO_START(scale);
    scale = scale - 127;
    return scale;
}

// TODO: if src > MAX_FLOAT_NUM or src is inf, when how to define decimal?
int s21_from_float_to_decimal(float src, s21_decimal* dst) {
    int result = OK;
    s21_reset_decimal(dst);
    if (isinf(src) || isnan(src) || fabsf(src) < MIN_FLOAT_NUM || fabsf(src) > MAX_FLOAT_NUM) {
        result = CONVERSION_ERROR;
    }
    if (src != 0.f && result != CONVERSION_ERROR) {
        if (src < 0.f) {
            s21_set_negative_sign(dst);
            src = fabsf(src);
        }
        float start_src = src;
        int num_of_digits = 0;
        while (src >= 1.) {
            src = src / 10.f;
            num_of_digits++;
        }
        int num_of_meaningful_digits = 7;
        src = src * 1e7f;
        src = roundf(src);
        while (fmodf(src, 10.f) == 0 && src > start_src) {
            src = src / 10.f;
            num_of_meaningful_digits--;
        }
        int scale = (num_of_meaningful_digits - num_of_digits) >= 0 ? (num_of_meaningful_digits - num_of_digits) : 0;
        s21_set_scale(dst, scale);
        int float_scale = s21_get_float_scale(src);
        float_exp_notation exp_notation;
        exp_notation.fl = src;
        for (int pos = 0, idx = 23 - float_scale; pos < float_scale; pos++, idx++) {
            s21_set_bit(dst, GET_BIT(exp_notation.en, idx), pos);
        }
        s21_set_bit(dst, 1, float_scale);
        result = OK;
    }
    return result;
}

int s21_from_decimal_to_int(s21_decimal src, int* dst) {
//    if (!src && src == INF && src == NAN) {
//        ERROR;
//    }
//    if (!ERROR) {
//        trancate_src = trancate(src);
//        if (trancate_src > MAX_INT_NUM || trancate_src < MAX_INT_NUM) {
//            ERROR;
//        } else {
//            int sign = s21_get_sign(&src);
//            *dst = src.bits[0];
//            *dst *= pow(-1, sign);
//        }
//    }
//    return OK;
}

int s21_from_decimal_to_float(s21_decimal src, float* dst) {

}
// -- END CONVERTERS --

// -- OTHERS --
int s21_floor(s21_decimal value, s21_decimal *result) {
    return OK;
}

int s21_round(s21_decimal value, s21_decimal *result) {
    return OK;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
    return OK;
}

void s21_copy_decimal(s21_decimal* src, s21_decimal* dst) {
    s21_reset_decimal(dst);
    int size_bits_in_decimal = 4;
    int num_bits = 32;
    for (int idx = 0; idx < size_bits_in_decimal * num_bits; idx++) {
        int bit = s21_get_bit(src, idx);
        s21_set_bit(dst, bit, idx);
    }
}

int s21_negate(s21_decimal value, s21_decimal *result){
    int res;
    if (s21_is_correct_decimal(&value)) {
        s21_reset_decimal(result);
        s21_copy_decimal(&value, result);
        if (s21_get_sign(result) == 0) {
            s21_set_negative_sign(result);
        } else {
            s21_set_positive_sign(result);
        }
        res = OK;
    } else {
        res = CALCULATION_ERROR;
    }
    return res;
}
// -- END OTHERS --