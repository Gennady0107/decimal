#include "s21_decimal.h"
#include <check.h>
#include <stdlib.h>

// START_TEST(test_func_sum_ab) {
//     // a + b = r
//     int a = 1;
//     int b = 3;
//     int r = 4;
//     s21_decimal *decimal1, *decimal2, *result, *comparative;
//     s21_init_decimal(&decimal1);
//     s21_init_decimal(&decimal2);
//     s21_init_decimal(&result);
//     s21_init_decimal(&comparative);

//     s21_from_int_to_decimal(a, decimal1);
//     s21_from_int_to_decimal(b, decimal2);
//     s21_from_int_to_decimal(r, comparative);
//     simple_sum(decimal1, decimal2, result);

//     ck_assert(s21_decimal_equal(result, comparative) == 0);
// }
// END_TEST

// START_TEST(test_func_sum_ab2) {
//     // a + b = r
//     int a = 9;
//     int b = 0;
//     int r = 9;
//     s21_decimal *decimal1, *decimal2, *result, *comparative;
//     s21_init_decimal(&decimal1);
//     s21_init_decimal(&decimal2);
//     s21_init_decimal(&result);
//     s21_init_decimal(&comparative);

//     s21_from_int_to_decimal(a, decimal1);
//     s21_from_int_to_decimal(b, decimal2);
//     s21_from_int_to_decimal(r, comparative);
//     simple_sum(decimal1, decimal2, result);

//     ck_assert(s21_decimal_equal(result, comparative) == 0);
// }
// END_TEST

START_TEST(test_func_sub_ab) {
    // a - b = r
    int a = 5;
    int b = 1;
    int r = 4;
    s21_decimal *decimal1, *decimal2, *result, *comparative;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);
    s21_init_decimal(&result);
    s21_init_decimal(&comparative);

    s21_from_int_to_decimal(a, decimal1);
    s21_from_int_to_decimal(b, decimal2);
    s21_from_int_to_decimal(r, comparative);
    s21_sub(*decimal1, *decimal2, result);

    ck_assert(s21_decimal_equal(result, comparative) == 0);
}
END_TEST

START_TEST(test_func_sub_ba) {
    // b - a = r
    int a = 1;
    int b = 3;
    int r = -2;
    s21_decimal *decimal1, *decimal2, *result, *comparative;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);
    s21_init_decimal(&result);
    s21_init_decimal(&comparative);

    s21_from_int_to_decimal(a, decimal1);
    s21_from_int_to_decimal(b, decimal2);
    s21_from_int_to_decimal(r, comparative);
    s21_sub(*decimal1, *decimal2, result);

    ck_assert(s21_decimal_equal(result, comparative) == 0);
}
END_TEST

// START_TEST(test_func_sub_aa) {
//     // b - a = r
//     int a = 3;
//     int b = 3;
//     int r = 0;
//     s21_decimal *decimal1, *decimal2, *result, *comparative;
//     s21_init_decimal(&decimal1);
//     s21_init_decimal(&decimal2);
//     s21_init_decimal(&result);
//     s21_init_decimal(&comparative);

//     s21_from_int_to_decimal(a, decimal1);
//     s21_from_int_to_decimal(b, decimal2);
//     s21_from_int_to_decimal(r, comparative);
//     s21_sub(*decimal1, *decimal2, result);

//     ck_assert(s21_decimal_equal(result, comparative) == 0);
// }
// END_TEST

// START_TEST(test_func_sub_a_negative_b) {
//     // a - b = r
//     int a = 5;
//     int b = -1;
//     int r = 6;
//     s21_decimal *decimal1, *decimal2, *result, *comparative;
//     s21_init_decimal(&decimal1);
//     s21_init_decimal(&decimal2);
//     s21_init_decimal(&result);
//     s21_init_decimal(&comparative);

//     s21_from_int_to_decimal(a, decimal1);
//     s21_from_int_to_decimal(b, decimal2);
//     s21_from_int_to_decimal(r, comparative);
//     s21_sub(*decimal1, *decimal2, result);

//     ck_assert(s21_decimal_equal(result, comparative) == 0);
// }
// END_TEST

START_TEST(test_func_sub_negative_a_negative_b) {
    // a - b = r
    int a = -5;
    int b = -1;
    int r = -4;
    s21_decimal *decimal1, *decimal2, *result, *comparative;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);
    s21_init_decimal(&result);
    s21_init_decimal(&comparative);

    s21_from_int_to_decimal(a, decimal1);
    s21_from_int_to_decimal(b, decimal2);
    s21_from_int_to_decimal(r, comparative);
    s21_sub(*decimal1, *decimal2, result);

    ck_assert(s21_decimal_equal(result, comparative) == 0);
}
END_TEST

START_TEST(test_func_simple_sub_ab) {
    // a - b = r
    int a = 3;
    int b = 2;
    int r = 1;
    s21_decimal *decimal1, *decimal2, *result, *comparative;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);
    s21_init_decimal(&result);
    s21_init_decimal(&comparative);

    s21_from_int_to_decimal(a, decimal1);
    s21_from_int_to_decimal(b, decimal2);
    s21_from_int_to_decimal(r, comparative);
    simple_sub(*decimal1, *decimal2, result);

    ck_assert(s21_decimal_equal(result, comparative) == 0);
}
END_TEST

START_TEST(test_func_simple_sub_aa) {
    // a - b = r
    int a = 3;
    int b = 3;
    int r = 0;
    s21_decimal *decimal1, *decimal2, *result, *comparative;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);
    s21_init_decimal(&result);
    s21_init_decimal(&comparative);

    s21_from_int_to_decimal(a, decimal1);
    s21_from_int_to_decimal(b, decimal2);
    s21_from_int_to_decimal(r, comparative);
    simple_sub(*decimal1, *decimal2, result);

    ck_assert(s21_decimal_equal(result, comparative) == 0);
}
END_TEST

START_TEST(test_func_simple_sub_a0) {
    // a - b = r
    int a = 3;
    int b = 0;
    int r = 3;
    s21_decimal *decimal1, *decimal2, *result, *comparative;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);
    s21_init_decimal(&result);
    s21_init_decimal(&comparative);

    s21_from_int_to_decimal(a, decimal1);
    s21_from_int_to_decimal(b, decimal2);
    s21_from_int_to_decimal(r, comparative);
    simple_sub(*decimal1, *decimal2, result);

    ck_assert(s21_decimal_equal(result, comparative) == 0);
}
END_TEST

START_TEST(test_func_simple_sub_max_b) {
    // maxbet - b = 111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111010
    int b = 5;
    s21_decimal *decimal1, *decimal2, *result, *comparative;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);
    s21_init_decimal(&result);
    s21_init_decimal(&comparative);

    maxbet_decimal(decimal1);
    s21_from_int_to_decimal(b, decimal2);
    maxbet_decimal(comparative);
    s21_set_bit(comparative, 0, 0);
    s21_set_bit(comparative, 0, 2);
    
    simple_sub(*decimal1, *decimal2, result);

    ck_assert(s21_decimal_equal(result, comparative) == 0);
}
END_TEST

START_TEST(test_func_simple_sub_max_null) {
    // maxbet - b = maxbet
    int b = 0;
    s21_decimal *decimal1, *decimal2, *result, *comparative;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);
    s21_init_decimal(&result);
    s21_init_decimal(&comparative);

    maxbet_decimal(decimal1);
    s21_from_int_to_decimal(b, decimal2);
    maxbet_decimal(comparative);

    simple_sub(*decimal1, *decimal2, result);

    ck_assert(s21_decimal_equal(result, comparative) == 0);
}
END_TEST

START_TEST(test_func_simple_ab2) {
    // 10000.. - ..00001 = 011..11
    int b = 1;
    s21_decimal *decimal1, *decimal2, *result, *comparative;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);
    s21_init_decimal(&result);
    s21_init_decimal(&comparative);

    s21_from_int_to_decimal(0, decimal1);
    s21_set_bit(decimal1, 1, END_OF_ARRAY);
    s21_from_int_to_decimal(b, decimal2);
    maxbet_decimal(comparative);
    s21_set_bit(comparative, 0, END_OF_ARRAY);
    // s21_set_bit(comparative, 0, 2); /*не долдно проходить с этим*/

    simple_sub(*decimal1, *decimal2, result);

    ck_assert(s21_decimal_equal(result, comparative) == 0);
}
END_TEST

START_TEST(test_func_simple_a_no_b2) {
    // 10000.. - ..00001 = 011..11
    int b = 1;
    s21_decimal *decimal1, *decimal2, *result, *comparative;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);
    s21_init_decimal(&result);
    s21_init_decimal(&comparative);

    s21_from_int_to_decimal(0, decimal1);
    s21_set_bit(decimal1, 1, END_OF_ARRAY);
    s21_from_int_to_decimal(b, decimal2);
    maxbet_decimal(comparative);
    s21_set_bit(comparative, 0, END_OF_ARRAY);
    s21_set_bit(comparative, 0, 2);

    simple_sub(*decimal1, *decimal2, result);

    ck_assert(s21_decimal_equal(result, comparative) != 0);
}
END_TEST

START_TEST(test_func_s21_decimal_equal_a_no_b) {
    // 1000..0 != 0..0000
    int b = 1;
    s21_decimal *decimal1, *decimal2;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    s21_from_int_to_decimal(0, decimal1);
    s21_set_bit(decimal1, 1, END_OF_ARRAY);
    s21_from_int_to_decimal(0, decimal2);

    ck_assert(s21_decimal_equal(decimal1, decimal2) != 0);
}
END_TEST

START_TEST(test_func_s21_decimal_equal_a_no_b3) {
    // 500001 != 65
    s21_decimal *decimal1, *decimal2;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    s21_from_int_to_decimal(50001, decimal1);
    s21_from_int_to_decimal(65, decimal2);

    ck_assert(s21_decimal_equal(decimal1, decimal2) != 0);
}
END_TEST

START_TEST(test_func_s21_decimal_equal_a_no_b2) {
    // 0000..0 != 0..0001
    int b = 1;
    s21_decimal *decimal1, *decimal2;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    s21_from_int_to_decimal(0, decimal1);
    s21_from_int_to_decimal(0, decimal2);
    s21_set_bit(decimal2, 1, BEGINNING_OF_ARRAY);

    ck_assert(s21_decimal_equal(decimal1, decimal2) != 0);
}
END_TEST

START_TEST(test_func_s21_decimal_equal_a_is_b) {
    // 100..00 == 10..000
    int b = 1;
    s21_decimal *decimal1, *decimal2;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    s21_from_int_to_decimal(0, decimal1);
    s21_from_int_to_decimal(0, decimal2);
    s21_set_bit(decimal1, 1, END_OF_ARRAY);
    s21_set_bit(decimal2, 1, END_OF_ARRAY);

    ck_assert(s21_decimal_equal(decimal1, decimal2) == 0);
}
END_TEST

START_TEST(test_func_s21_decimal_equal_a_is_b2) {
    // 100..01 == 10..001
    int b = 1;
    s21_decimal *decimal1, *decimal2;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    s21_from_int_to_decimal(0, decimal1);
    s21_from_int_to_decimal(0, decimal2);
    s21_set_bit(decimal1, 1, BEGINNING_OF_ARRAY);
    s21_set_bit(decimal2, 1, BEGINNING_OF_ARRAY);
    s21_set_bit(decimal1, 1, END_OF_ARRAY);
    s21_set_bit(decimal2, 1, END_OF_ARRAY);

    ck_assert(s21_decimal_equal(decimal1, decimal2) == 0);
}
END_TEST

START_TEST(test_func_pow_10_n) {
    //  pow(1010, 2) == 1100100
    int n = 1;
    s21_decimal *decimal1, *decimal2;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    s21_from_int_to_decimal(10, decimal1);
    s21_from_int_to_decimal(100, decimal2);
    // s21_set_bit(decimal1, 1, 1);
    // s21_set_bit(decimal1, 1, 3);
    // s21_set_bit(decimal2, 1, 2);
    // s21_set_bit(decimal2, 1, 5);
    // s21_set_bit(decimal2, 1, 6);

    pow_10_n(decimal1, 2);

    ck_assert(s21_decimal_equal(decimal1, decimal2) == 0);
}
END_TEST

START_TEST(test_func_pow_10_n2) {
    //  pow_10_n(1010, 3) == 1111101000
    int n = 1;
    s21_decimal *decimal1, *decimal2;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    s21_from_int_to_decimal(0, decimal1);
    s21_from_int_to_decimal(0, decimal2);

    s21_set_bit(decimal2, 1, 3);
    s21_set_bit(decimal2, 1, 5);
    s21_set_bit(decimal2, 1, 6);
    s21_set_bit(decimal2, 1, 7);
    s21_set_bit(decimal2, 1, 8);
    s21_set_bit(decimal2, 1, 9);

    pow_10_n(decimal1, 3);

    ck_assert(s21_decimal_equal(decimal1, decimal2) == 0);
}
END_TEST

START_TEST(test_func_mult_a_a) {
    //  simple_mult(1010, 1010) == 1100100
    int n = 1;
    s21_decimal *decimal1, *decimal2, *comparative, *result;
    s21_init_decimal(&result);
    s21_init_decimal(&comparative);
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    s21_from_int_to_decimal(10, decimal1);
    s21_from_int_to_decimal(10, decimal2);
    s21_from_int_to_decimal(0, result);
    s21_from_int_to_decimal(100, comparative);

    simple_mult(decimal1, decimal2, result);

    ck_assert(s21_decimal_equal(result, comparative) == 0);
}
END_TEST

START_TEST(test_func_mult_a_b) {
    //  simple_mult(10111, 10001) == 110000111
    int n = 1;
    s21_decimal *decimal1, *decimal2, *comparative, *result;
    s21_init_decimal(&result);
    s21_init_decimal(&comparative);
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    s21_from_int_to_decimal(23, decimal1);
    s21_from_int_to_decimal(17, decimal2);
    s21_from_int_to_decimal(0, result);
    s21_from_int_to_decimal(391, comparative);

    simple_mult(decimal1, decimal2, result);

    ck_assert(s21_decimal_equal(result, comparative) == 0);
}
END_TEST

START_TEST(test_func_simple_div_10_10) {
    //  simple_div(1010, 1010) == 0
    s21_decimal *decimal1, *decimal2, *comparative, *result;
    s21_init_decimal(&result);
    s21_init_decimal(&comparative);
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    s21_from_int_to_decimal(10, decimal1);
    s21_from_int_to_decimal(10, decimal2);
    s21_from_int_to_decimal(0, result);
    s21_from_int_to_decimal(0, comparative);

    simple_div(decimal1, decimal2, result);

    ck_assert(s21_decimal_equal(result, comparative) == 0);
}
END_TEST

START_TEST(test_func_simple_div_20_10) {
    //  simple_div(1100100 2, 1010) == 1010
    s21_decimal *decimal1, *decimal2, *comparative, *result;
    s21_init_decimal(&result);
    s21_init_decimal(&comparative);
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    s21_from_int_to_decimal(20, decimal1);
    s21_from_int_to_decimal(10, decimal2);
    s21_from_int_to_decimal(0, result);
    s21_from_int_to_decimal(2, comparative);

    simple_div(decimal1, decimal2, result);

    ck_assert(s21_decimal_equal(result, comparative) == 0);
}
END_TEST

START_TEST(test_func_simple_div_2147483647_10) {
    //  simple_div(2147483647 (1111111111111111111111111111111), 1010) == 214748364(1100110011001100110011001100)
    s21_decimal *decimal1, *decimal2, *comparative, *result;
    s21_init_decimal(&result);
    s21_init_decimal(&comparative);
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    s21_from_int_to_decimal(2147483647, decimal1);
    s21_from_int_to_decimal(10, decimal2);
    s21_from_int_to_decimal(0, result);
    s21_from_int_to_decimal(214748364, comparative);

    simple_div(decimal1, decimal2, result);

    ck_assert(s21_decimal_equal(result, comparative) == 0);
}
END_TEST

START_TEST(test_func_simple_div_100_10) {
    //  simple_div(1100100 2, 1010) == 1010
    s21_decimal *decimal1, *decimal2, *comparative, *result;
    s21_init_decimal(&result);
    s21_init_decimal(&comparative);
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    s21_from_int_to_decimal(100, decimal1);
    s21_from_int_to_decimal(10, decimal2);
    s21_from_int_to_decimal(0, result);
    s21_from_int_to_decimal(10, comparative);

    simple_div(decimal1, decimal2, result);

    ck_assert(s21_decimal_equal(result, comparative) == 0);
}
END_TEST

START_TEST(test_func_simple_div_1232_4) {
    //  simple_div(1100100 2, 1010) == 1010
    s21_decimal *decimal1, *decimal2, *comparative, *result;
    s21_init_decimal(&result);
    s21_init_decimal(&comparative);
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    s21_from_int_to_decimal(1232, decimal1);
    s21_from_int_to_decimal(4, decimal2);
    s21_from_int_to_decimal(0, result);
    s21_from_int_to_decimal(308, comparative);

    simple_div(decimal1, decimal2, result);

    ck_assert(s21_decimal_equal(result, comparative) == 0);
}
END_TEST

START_TEST(test_func_simple_div_1000_10) {
    s21_decimal *decimal1, *decimal2, *comparative, *result;
    s21_init_decimal(&result);
    s21_init_decimal(&comparative);
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    s21_from_int_to_decimal(1000, decimal1);
    s21_from_int_to_decimal(10, decimal2);
    s21_from_int_to_decimal(0, result);
    s21_from_int_to_decimal(100, comparative);

    simple_div(decimal1, decimal2, result);

    ck_assert(s21_decimal_equal(result, comparative) == 0);
}
END_TEST

START_TEST(test_func_simple_div_1xx0_10) {
    //  simple_mult(+000000000000000000000000000000000111111111111111111111111111111111111111111111111111111111111111, 1010) == 10000011000100100110111010010111100011010101000011010
    s21_decimal *decimal1, *decimal2, *comparative, *result;
    s21_init_decimal(&result);
    s21_init_decimal(&comparative);
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    maxbet_decimal(decimal1);
    for (int i = END_OF_ARRAY; i >= 63; i--) {
        s21_set_bit(decimal1, 0, i);
    }
    
    s21_from_int_to_decimal(10, decimal2);
    s21_from_int_to_decimal(0, result);
    s21_from_int_to_decimal(3539053082, comparative);
    s21_set_bit(comparative, 1, 33);
    
    s21_set_bit(comparative, 1, 35);
    s21_set_bit(comparative, 1, 36);
    s21_set_bit(comparative, 1, 39);
    s21_set_bit(comparative, 1, 42);
    s21_set_bit(comparative, 1, 46);
    s21_set_bit(comparative, 1, 47);
    s21_set_bit(comparative, 1, 53);
    
    print_dec(decimal1);
    print_dec(decimal2);
    print_dec(comparative);

    simple_div(decimal1, decimal2, result);
    print_dec(result);

    ck_assert(s21_decimal_equal(result, comparative) == 0);
}
END_TEST

START_TEST(test_func_simple_compare_max_max) {
    s21_decimal *decimal1, *decimal2;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    maxbet_decimal(decimal1);
    maxbet_decimal(decimal2);
    
    ck_assert(simple_compare(decimal1, decimal2) == 0);
}
END_TEST

START_TEST(test_func_simple_compare_max_max0) {
    s21_decimal *decimal1, *decimal2;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    maxbet_decimal(decimal1);
    maxbet_decimal(decimal2);
    s21_set_bit(decimal2, 0, 0);
    
    ck_assert(simple_compare(decimal1, decimal2) == 1);
}
END_TEST

START_TEST(test_func_simple_compare_000_100) {
    s21_decimal *decimal1, *decimal2;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    s21_from_int_to_decimal(0, decimal1);
    s21_from_int_to_decimal(0, decimal2);
    
    s21_set_bit(decimal2, 1, END_OF_ARRAY);
    
    // s21_set_bit(decimal1, 0, 94);
    
    ck_assert(simple_compare(decimal1, decimal2) == 2);
}
END_TEST

START_TEST(test_func_simple_compare_10_max) {
    s21_decimal *decimal1, *decimal2;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    s21_from_int_to_decimal(10, decimal1);
    maxbet_decimal(decimal2);
    
    ck_assert(simple_compare(decimal1, decimal2) == 2);
}
END_TEST

START_TEST(test_func_check_for_possibility_pow_10) {
    //  check_for_possibility_pow_10 (1010) == 1010
    s21_decimal *decimal1;
    s21_init_decimal(&decimal1);
    s21_from_int_to_decimal(10, decimal1);
    ck_assert(check_for_possibility_pow_10 (decimal1) == 0);
}
END_TEST

START_TEST(test_func_check_for_possibility_pow_10_max) {
    //  check_for_possibility_pow_10 (111..11) != result(0)
    s21_decimal *decimal1;
    s21_init_decimal(&decimal1);
    maxbet_decimal(decimal1);
    ck_assert(check_for_possibility_pow_10(decimal1) == 1);
}
END_TEST

START_TEST(test_func_check_for_possibility_div_max) {
    //  check_for_possibility_div_10_non_zero (111..11) == result(0)
    s21_decimal *decimal1;
    s21_init_decimal(&decimal1);
    maxbet_decimal(decimal1);
    ck_assert(check_for_possibility_div_10_non_zero(decimal1) == 0);
}
END_TEST

START_TEST(test_func_check_for_possibility_div_10) {
    //  check_for_possibility_div_10_non_zero (10) == result(!10)
    s21_decimal *decimal1;
    s21_init_decimal(&decimal1);
    s21_from_int_to_decimal(10, decimal1);
    ck_assert(check_for_possibility_div_10_non_zero(decimal1) == 1);
}
END_TEST


START_TEST(test_func_equalize_scale_max_10) {
    //  equalize_scale (111..11,7  1010,2) != result(0)
    s21_decimal *decimal1;
    s21_decimal *decimal2;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    maxbet_decimal(decimal1);
    s21_from_int_to_decimal(10, decimal2);
    s21_set_scale(decimal1, 7);
    s21_set_scale(decimal2, 2);

    ck_assert(equalize_scale(decimal1, decimal2) == 0);
}
END_TEST

START_TEST(test_func_equalize_scale_10_max) {
    //  equalize_scale (1010,2  111..11,0) != result(1)
    s21_decimal *decimal1;
    s21_decimal *decimal2;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    s21_from_int_to_decimal(10, decimal1);
    maxbet_decimal(decimal2);
    s21_set_scale(decimal1, 2);
    s21_set_scale(decimal2, 0);

    ck_assert(equalize_scale(decimal1, decimal2) == 1);
    // printf("scale1 = %d : scale2 = %d\n", s21_get_scale(decimal1), s21_get_scale(decimal2));
}
END_TEST

START_TEST(test_func_equalize_scale_max_10_2) {
    //  equalize_scale (111..11,5  1010,0) != result(0)
    s21_decimal *decimal1;
    s21_decimal *decimal2;
    s21_init_decimal(&decimal1);
    s21_init_decimal(&decimal2);

    maxbet_decimal(decimal1);
    s21_from_int_to_decimal(10, decimal2);
    s21_set_scale(decimal1, 5);
    s21_set_scale(decimal2, 0);

    ck_assert(equalize_scale(decimal1, decimal2) == 0);
    // printf("scale1 = %d : scale2 = %d\n", s21_get_scale(decimal1), s21_get_scale(decimal2));
}
END_TEST


//11001002 (100)
//111111111111111111111111111111111111111111111111111111110100101 (922337203685477571710)
//10000011000100100110111010010111100011010101000011010

Suite* create_suite()
{
    Suite *suite_s21_dec;
    TCase *tc_core_sub;

    suite_s21_dec = suite_create("s21_decimal");

    /* Core test case */
    tc_core_sub = tcase_create("s21_sub");

    //

    tcase_add_test(tc_core_sub, test_func_check_for_possibility_div_10); // проверка возможности деления на 10
    tcase_add_test(tc_core_sub, test_func_check_for_possibility_div_max);  //проверка возможности деления 
    // tcase_add_test(tc_core_sub, test_func_equalize_scale_10_max);
    tcase_add_test(tc_core_sub, test_func_equalize_scale_max_10_2);
    // tcase_add_test(tc_core_sub, test_func_equalize_scale_max_10);
    tcase_add_test(tc_core_sub, test_func_check_for_possibility_pow_10_max);
    tcase_add_test(tc_core_sub, test_func_check_for_possibility_pow_10);
    tcase_add_test(tc_core_sub, test_func_simple_compare_max_max);
    tcase_add_test(tc_core_sub, test_func_simple_compare_max_max0);
    tcase_add_test(tc_core_sub, test_func_simple_compare_000_100);
    tcase_add_test(tc_core_sub, test_func_simple_compare_10_max);

    // tcase_add_test(tc_core_sub, test_func_simple_div_1xx0_10);
    tcase_add_test(tc_core_sub, test_func_simple_div_1000_10);
    tcase_add_test(tc_core_sub, test_func_simple_div_100_10);
    tcase_add_test(tc_core_sub, test_func_simple_div_1232_4);
    tcase_add_test(tc_core_sub, test_func_simple_div_2147483647_10);
    tcase_add_test(tc_core_sub, test_func_simple_div_20_10);
    tcase_add_test(tc_core_sub, test_func_simple_div_10_10);
    tcase_add_test(tc_core_sub, test_func_mult_a_b);
    tcase_add_test(tc_core_sub, test_func_mult_a_a);
    tcase_add_test(tc_core_sub, test_func_pow_10_n2);
    tcase_add_test(tc_core_sub, test_func_pow_10_n);
    tcase_add_test(tc_core_sub, test_func_s21_decimal_equal_a_is_b);
    tcase_add_test(tc_core_sub, test_func_s21_decimal_equal_a_no_b2);
    tcase_add_test(tc_core_sub, test_func_s21_decimal_equal_a_no_b);
    tcase_add_test(tc_core_sub, test_func_s21_decimal_equal_a_no_b3);
    tcase_add_test(tc_core_sub, test_func_simple_a_no_b2);
    tcase_add_test(tc_core_sub, test_func_simple_ab2);
    tcase_add_test(tc_core_sub, test_func_simple_sub_max_null);
    tcase_add_test(tc_core_sub, test_func_simple_sub_ab);
    tcase_add_test(tc_core_sub, test_func_simple_sub_aa);
    tcase_add_test(tc_core_sub, test_func_simple_sub_a0);
    tcase_add_test(tc_core_sub, test_func_sub_ab);
    tcase_add_test(tc_core_sub, test_func_sub_ba);
    tcase_add_test(tc_core_sub, test_func_simple_sub_max_b);
    // tcase_add_test(tc_core_sub, test_func_sub_aa);
    tcase_add_test(tc_core_sub, test_func_sub_negative_a_negative_b);
    // tcase_add_test(tc_core_sub, test_func_sub_a_negative_b);
    // tcase_add_test(tc_core_sub, test_func_sum_ab);
    // tcase_add_test(tc_core_sub, test_func_sum_ab2);

    suite_add_tcase(suite_s21_dec, tc_core_sub);

    return suite_s21_dec;
}



int main()
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = create_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}