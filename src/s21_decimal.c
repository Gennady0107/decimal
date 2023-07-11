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

void s21_copy_decimal(s21_decimal* dst, s21_decimal* src) {
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
        s21_copy_decimal(result, &value);
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

// -- ARITHMETICS --

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int error_code = 0;
    int k1, k2;
    s21_reset_decimal(result);
    k1 = s21_get_sign(&value_1);
    k2 = s21_get_sign(&value_2);
    if (k1 == 0 && k2 == 1) {
        s21_set_positive_sign(&value_2);
        error_code = s21_sub(value_1, value_2, result);
    } else if (k1 == 1 && k2 == 0) {
        s21_set_positive_sign(&value_1);
        error_code = s21_sub(value_2, value_1, result);
    } else {
        if (k1 == 1 && k2 == 1) {
            s21_set_negative_sign(result);
            s21_set_positive_sign(&value_1);
            s21_set_positive_sign(&value_2);
        }
        int scl_v1, scl_v2;
        scl_v1 = s21_get_scale(&value_1);
        scl_v2 = s21_get_scale(&value_2);
        if (scl_v1 == scl_v2) {
            simple_sum(&value_1, &value_2, result);
            s21_set_scale(result, scl_v1);
            error_code = 0;
        } else if (scl_v1 > scl_v2) {
            int dif_scl;
            dif_scl = scl_v1 - scl_v2;
            s21_decimal *for_pow_10_n, *tmp_v2;
            s21_init_decimal(&for_pow_10_n);
            s21_init_decimal(&tmp_v2);
            pow_10_n(for_pow_10_n, dif_scl);
            simple_mult(&value_2, for_pow_10_n, tmp_v2);
            simple_sum(&value_1, tmp_v2, result);
            s21_free_decimal(for_pow_10_n);
            s21_free_decimal(tmp_v2);
            s21_set_scale(result, scl_v1);
            error_code = 0;
        } else {
            int dif_scl;
            dif_scl = scl_v2 - scl_v1;
            s21_decimal *for_pow_10_n, *tmp_v1;
            s21_init_decimal(&for_pow_10_n);
            s21_init_decimal(&tmp_v1);
            pow_10_n(for_pow_10_n, dif_scl);
            simple_mult(&value_1, for_pow_10_n, tmp_v1);
            simple_sum(&value_2, tmp_v1, result);
            s21_free_decimal(for_pow_10_n);
            s21_free_decimal(tmp_v1);
            s21_set_scale(result, scl_v2);
            error_code = 0;
        }
    }
    return error_code;
}

void function_body_sub(s21_decimal v1, s21_decimal v2) {
    ;
}

int s21_div(s21_decimal value_1, s21_decimal value2, s21_decimal result) {
    
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
    int k1, k2;
    int bit_v_1, bit_v_2;
    int flag = 0;
    int idx_tmp = 0;
    s21_decimal* tmp_value_1;
    s21_init_decimal(&tmp_value_1);
    s21_copy_decimal(tmp_value_1, &value_1);

    k1 = s21_get_sign(tmp_value_1);
    k2 = s21_get_sign(&value_2);
    
    if (k1 == 1 && k2 == 1) {
        s21_set_positive_sign(&value_1);
        s21_set_positive_sign(&value_2);
        simple_sum(&value_1, &value_2, result);
    } else if (k1 == 0 && k2 == 0) {
        if (simple_compare(tmp_value_1, &value_2) == 0) {
           s21_reset_decimal(result);
        } else if (simple_compare(tmp_value_1, &value_2) == 1) {
            printf("v1 > v2\n");
            for (int idx = 0; idx <= END_OF_ARRAY; idx++) {
                bit_v_1 = s21_get_bit(tmp_value_1, idx);
                bit_v_2 = s21_get_bit(&value_2, idx);
                if (bit_v_1 == 1 && bit_v_2 == 0) {
                    s21_set_bit(result, 1, idx);
                } else if (bit_v_1 == 1 && bit_v_2 == 1) {
                    s21_set_bit(result, 0, idx);
                } else if (bit_v_1 == 0 && bit_v_2 == 1) {
                    for (idx_tmp = idx; idx_tmp <= END_OF_ARRAY && s21_get_bit(tmp_value_1, idx_tmp) == 0; idx_tmp++) {
                        flag = 1;
                        s21_set_bit(tmp_value_1, flag, idx_tmp);
                    }
                        flag = 0;
                        s21_set_bit(tmp_value_1, flag, idx_tmp);
                        idx_tmp = 0;
                    s21_set_bit(result, 1, idx);
                } else if (bit_v_1 == 0 && bit_v_1 == 0) {
                    s21_set_bit(result, 0, idx);
                }
            }
        } else if (simple_compare(tmp_value_1, &value_2) == 2) {
            for (int idx = 0; idx <= END_OF_ARRAY; idx++) {
                bit_v_1 = s21_get_bit(&value_2, idx);
                bit_v_2 = s21_get_bit(tmp_value_1, idx);
                if (bit_v_1 == 1 && bit_v_2 == 0) {
                    s21_set_bit(result, 1, idx);
                } else if (bit_v_1 == 1 && bit_v_2 == 1) {
                    s21_set_bit(result, 0, idx);
                } else if (bit_v_1 == 0 && bit_v_2 == 1) {
                    for (idx_tmp = idx; idx_tmp <= END_OF_ARRAY && s21_get_bit(&value_2, idx_tmp) == 0; idx_tmp++) {
                        flag = 1;
                        s21_set_bit(&value_2, flag, idx_tmp);
                    }
                    flag = 0;
                    s21_set_bit(&value_2, flag, idx_tmp);
                    idx_tmp = 0;
                    s21_set_bit(result, 1, idx);
                } else if (bit_v_1 == 0 && bit_v_1 == 0) {
                    s21_set_bit(result, 0, idx);
                }
            }
            s21_set_negative_sign(result);
        }
    }
    if (k1 == 0 && k2 == 1) {
        s21_set_positive_sign(&value_2);
        s21_add(value_1, value_2, result);
    } if (k1 == 1 && k2 == 0) {
        s21_set_positive_sign(&value_1);
        s21_add(value_1, value_2, result);
        s21_set_negative_sign(result);
    }
}

void pow_10_n(s21_decimal* result, int n) {
    int src = 10;
    s21_decimal* a, *tmp_value;
    s21_init_decimal(&a);
    s21_init_decimal(&tmp_value);
    s21_from_int_to_decimal(src, a);
    s21_from_int_to_decimal(src, result);

    if (n == 0) { 
        s21_from_int_to_decimal(1, result);
    } else {
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < 10; j++) {
                s21_copy_decimal(tmp_value, result);
                simple_sum(tmp_value, a, result);
            }
            s21_copy_decimal(a, result);
        }
    }
    s21_free_decimal(a);
    s21_free_decimal(tmp_value);
}

int simple_compare (s21_decimal* value_1, s21_decimal* value_2) {
    int flag = 0;
    int v1, v2;
    for (int idx = 95; idx >= 0 && flag == 0; idx--) {
        v1 = s21_get_bit(value_1, idx);
        v2 = s21_get_bit(value_2, idx);
        if (v1 > v2) {
            flag = 1;
        } else if (v2 > v1) {
            flag = 2;
        } else {
            flag = 0;
        }
    }
    return flag;
}

void simple_sum(s21_decimal* value_1, s21_decimal* value_2, s21_decimal* result) {
    char bit_in_mind = 0;
    int v1, v2, r;
    int last_idx = 95;

    for (int idx = 0; idx <= last_idx; idx++) {
        v1 = s21_get_bit(value_1, idx);
        //printf("%d+", v1);
        v2 = s21_get_bit(value_2, idx);
        //printf("%d", v2);
        r = v1 + v2 + bit_in_mind;
        switch (r) {
            case 3:
                bit_in_mind = 1, r = 1;
                break;
            case 2:
                bit_in_mind = 1, r = 0;
                break;
            case 1:
                bit_in_mind = 0, r = 1;
                break;
            case 0:
                bit_in_mind = 0, r = 0;
                break;   
            default:
                printf("error!");
                break;
        }
        s21_set_bit(result, r, idx);
    }
    if (bit_in_mind == 1) {
    }
}

// int simple_mult(s21_decimal* value_1, s21_decimal* value_2, s21_decimal* result) {
//     int error = 0;

//     s21_decimal *tmp1, *tmp2;
//     s21_init_decimal(&tmp1);
//     s21_init_decimal(&tmp2);

//     s21_copy_decimal(result, value_1);
//     s21_copy_decimal(tmp2, value_1);
//     for (int idx = 0; idx < 96 && error != 1; idx++) {
//         s21_copy_decimal(tmp1, result);
//         error = simple_decimal_shift(tmp2);
//         if ((s21_get_bit(value_2, idx) == 1) && error != 1) {
//             simple_sum(tmp1, tmp2, result);
//         }      
//     }
//     s21_free_decimal(tmp1);
//     s21_free_decimal(tmp2);
//     return error;
// }

int simple_mult(s21_decimal* value_1, s21_decimal* value_2, s21_decimal* result) {
    int error = 0;

    s21_decimal *tmp1, *tmp2, *shifted_value_1;
    s21_init_decimal(&tmp1);
    s21_init_decimal(&tmp2);
    s21_init_decimal(&shifted_value_1);

    s21_copy_decimal(shifted_value_1, value_1);
    s21_reset_decimal(result);
    for (int idx = 0; idx < 96 && error != 1; idx++) {
        if (s21_get_bit(value_2, idx) == 0) {
            s21_reset_decimal(tmp1);
        }
        if (s21_get_bit(value_2, idx) == 1) {
            s21_copy_decimal(tmp1, shifted_value_1);
        }
        s21_copy_decimal(tmp2, result);
        simple_sum(tmp1, tmp2, result);
        simple_decimal_shift(shifted_value_1);  
    }
    s21_free_decimal(tmp1);
    s21_free_decimal(tmp2);
    s21_free_decimal(shifted_value_1);
    return error;
}

int simple_decimal_shift(s21_decimal* value_1) {
    int idx_last_jun_bit = 31;
    int idx_first_midl_bit = 32;
    int idx_last_midl_bit = 63;
    int idx_first_old_bit = 64;
    int idx_last_old_bit = 95;
    int error = 0;

    if (s21_get_bit(value_1, idx_last_old_bit) == 1) {
        error = 1;
    } else {
        value_1->bits[OLD_BITS] = value_1->bits[OLD_BITS] << 1;
        s21_set_bit(value_1, s21_get_bit(value_1, idx_last_midl_bit), idx_first_old_bit);
        value_1->bits[MIDL_BITS] = value_1->bits[MIDL_BITS] << 1;
        s21_set_bit(value_1, s21_get_bit(value_1, idx_last_jun_bit), idx_first_midl_bit);
        value_1->bits[JUN_BITS] = value_1->bits[JUN_BITS] << 1;
    }
    return error;
}


// 10101010001001010
//   в числе х 128 бит
//   в числе у 128 бит
//   есть бит в уме (1 или 0)

//   складываем числа х и у справа налево
//   если встречаем 0 и 0, то в новое число кладем 0 (бит в уме равен 0)
//   если встречаем 1 и 0 (0 и 1), то в новое число кладем 1 (бит в уме равен 0)
//   если встречаем 1 и 1, то в нове число кладем 0 (бит в уме равен 1)

//   после того, как положили в новое число результат предыдущей операции
//   смотрим на бит в уме, если бит в уме равен 0, то результа не меняем
  
//   если бит в уме равен 1, то результат надо поменять
//   если результат предыдущей операции равен 0, то меняем на 1, а бит в уме обнуляем
//   если результат предыдущей операции равен 1, то меняем на 0, а бит в уме остается 1 на следующий шаг

//   в конце, если бит в уме есть, то сносим его на самое крайнее левое положение
//   если бита нет, то не сносим
// }
// -- END ARITHMETICS --