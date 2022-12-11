#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <math.h>
#include <stdlib.h>
#include <stdio.h>


typedef union {
    float fl;
    unsigned int en;
} float_exp_notation;

#define SIGN_BIT 0x80000000 // 1000 0000 0000 0000 0000 0000 0000 0000
#define SCALE_BITS 0x007F8000 // 0000 0000 0111 1111 1000 0000 0000 0000
#define FLOAT_SCALE_BITS 0x7F800000 // 0111 1111 1000 0000 0000 0000 0000 0000
#define SHIFT_SCALE_TO_DEF(x) ((x) << 16)
#define SHIFT_SCALE_TO_START(x) ((x) >> 16)
#define SHIFT_FLOAT_SCALE_TO_DEF(x) ((x) << 23)
#define SHIFT_FLOAT_SCALE_TO_START(x) ((x) >> 23)
#define GET_BIT(x, idx) ((x) & (1 << (idx)) ? 1 : 0)
#define ARR_LOC(x) ((x) % 32)
#define ARR_NUM(x) ((x) / 32)
#define ARR_SIGN 3
#define ARR_SCALE 3
#define OLD_BITS 2
#define MIDL_BITS 1
#define JUN_BITS 0




#define OK 0
#define CONVERSION_ERROR 1
#define CALCULATION_ERROR 1

#define MIN_FLOAT_NUM 1e-28f
#define MAX_FLOAT_NUM 79228162514264337593543950335.0
#define MIN_INT_NUM -2147483648
#define MAX_INT_NUM 2147483647

typedef struct {
    int bits[4];
} s21_decimal;

// -- FOUNDATION --
void s21_init_decimal(s21_decimal** dec);
void s21_free_decimal(s21_decimal* dec);
void s21_reset_decimal(s21_decimal* dec);
int s21_get_bit(s21_decimal* dec, int idx);
void s21_set_bit(s21_decimal* dec, int bit, int idx);
void s21_set_negative_sign(s21_decimal* dec);
void s21_set_positive_sign(s21_decimal* dec);
int s21_get_sign(s21_decimal* dec);
int s21_get_scale(s21_decimal* dec);
void s21_set_scale(s21_decimal* dec, int scale);
void s21_copy_decimal(s21_decimal* dst, s21_decimal* src);
int s21_is_correct_decimal(s21_decimal* dec);
int simple_decimal_shift(s21_decimal* value_1);
// -- END FOUNDATION --

// -- CONVERTERS --
int s21_get_float_scale(float src);
int s21_from_int_to_decimal(int src, s21_decimal* dst);
int s21_from_float_to_decimal(float src, s21_decimal* dst);
int s21_from_decimal_to_int(s21_decimal src, int* dst);
int s21_from_decimal_to_float(s21_decimal src, float* dst);
// -- END CONVERTERS --

// -- OTHERS --
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
// -- END OTHERS --

// -- ARITHMETICS --
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void pow_10_n(s21_decimal* result, int n);
void simple_sum(s21_decimal *value_1, s21_decimal *value_2, s21_decimal *result);
int simple_mult(s21_decimal* value_1, s21_decimal* value_2, s21_decimal* result);
// -- END ARITHMETICS --

void print_bit(int x);

#endif  // SRC_S21_DECIMAL_H_