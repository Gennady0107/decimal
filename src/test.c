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

Suite* create_suite()
{
    Suite *suite_s21_dec;
    TCase *tc_core_sub;

    suite_s21_dec = suite_create("s21_decimal");

    /* Core test case */
    tc_core_sub = tcase_create("s21_sub");


    tcase_add_test(tc_core_sub, test_func_simple_sub_ab);
    tcase_add_test(tc_core_sub, test_func_simple_sub_aa);
    tcase_add_test(tc_core_sub, test_func_simple_sub_a0);
    tcase_add_test(tc_core_sub, test_func_sub_ab);
    tcase_add_test(tc_core_sub, test_func_sub_ba);
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