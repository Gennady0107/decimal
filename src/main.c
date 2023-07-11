#include "s21_decimal.h"

void print_sign(s21_decimal* sign);
// void print_dec(s21_decimal* dec) {
//     for (int i = 0; i < 4; i++) {
//         printf("%d: ", i);
//         print_bit(dec->bits[i]);
//     }
// }

void print_dec(s21_decimal* dec) {
    print_sign(dec);
    for (int idx = 95; idx >= 0; idx--) {
        int bit = s21_get_bit(dec, idx);
        printf("%d", bit);
    }
    printf("\n");
}

void print_sign(s21_decimal* sign) {
    int sign_int = s21_get_sign(sign);
    if (sign_int == 1) {
        printf("-");
    } else{
        printf("+");
    }
}

typedef struct {
    int a;
    char c;
} stru;

// int main() {
//     s21_decimal* dec;
//     s21_decimal x;
    
//     stru s;
//     stru b;
//     stru k;

//     s.a = 5;
//     s.c = 'a';

//     stru* h = malloc(sizeof(stru));
//     (*h).a = 5;
//     (*h).c = 'a';

//     h->a = 5;
//     h->c = 'a'; 


    

//     printf("init decimal\n");
//     s21_init_decimal(&dec);
//     print_dec(dec);
//     printf("sizeof(*dec) = %ld\n", sizeof(dec));
//     printf("sizeof(dec) = %ld\n", sizeof(*dec));
//     printf("\n");
    

//     printf("set positive sign\n");
//     s21_set_positive_sign(dec);
//     print_dec(dec);
//     printf("get sign = %d\n", s21_get_sign(dec));
//     printf("\n");

//     printf("set negative sign\n");
//     s21_set_negative_sign(dec);
//     print_dec(dec);
//     printf("get sign = %d\n", s21_get_sign(dec));
//     printf("\n");

//     printf("set scale 5\n");
//     s21_set_scale(dec, 5);
//     print_dec(dec);
//     printf("get scale = %d\n", s21_get_scale(dec));
//     printf("\n");

//     printf("reset decimal\n");
//     s21_reset_decimal(dec);
//     print_dec(dec);
//     printf("\n");

//     for (int idx = 5; idx <= 95; idx += 10) {
//         printf("set bit 1 in idx = %d\n", idx);
//         s21_set_bit(dec, 1, idx);
//         print_dec(dec);
//         printf("get bit from idx %d = %d\n", idx, s21_get_bit(dec, idx));
//         printf("\n");
//     }

//     for (int idx = 5; idx <= 95; idx += 10) {
//         printf("set bit 0 in idx = %d\n", idx);
//         s21_set_bit(dec, 0, idx);
//         print_dec(dec);
//         printf("get bit from idx %d = %d\n", idx, s21_get_bit(dec, idx));
//         printf("\n");
//     }

//     s21_free_decimal(dec);
//     return 0;
// }

// int main () {
//     int v1 = 7;
//     int v2 = -7;
//     s21_decimal* value_1;
//     s21_decimal* value_2;

//     s21_init_decimal(&value_1);
//     s21_init_decimal(&value_2);

//     s21_from_int_to_decimal(v1, value_1);
//     s21_from_int_to_decimal(v2, value_2);

//     printf("sign v1 %d\n", s21_get_sign(value_1));
//     printf("sign v2 %d\n", s21_get_sign(value_2));

//     printf("\n");
//     return 0;
// }

int main() {
    // 10^0 = 1
    // 10^1 = 1010
    // 10^5 = 11000011010100000
    // 10^27 = 110011101100101110001111001001111111010000100000000011110011101000000000000000000000000000
    // 10^28 = 1000000100111111001110010111100011111000100101000000100110000100010000000000000000000000000000
    s21_decimal *v1;
    s21_decimal *v2, *result;
    int flag;
    s21_init_decimal(&v1);
    s21_init_decimal(&v2);
    s21_init_decimal(&result);

    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    s21_from_int_to_decimal(x, v1);
    s21_from_int_to_decimal(y, v2);
    // s21_set_scale(v1, 0);
    // s21_set_scale(v2, 0);
    // s21_add(*v1, *v2, result);
    print_dec(v1);
    print_dec(v2);
    // int n = s21_get_scale(result);
    // printf("scale - %d\n", n);
    flag = simple_compare(v1, v2);
    // print_dec(result);
    if (flag == 1) {
        printf("(x) %d ", x);
        printf(">");
        printf(" %d (y)\n", y);
    } else if (flag == 2) {
        printf("(y) %d ", y);
        printf(">");
        printf(" %d (x)\n", x);
    } else if (flag == 0) {
        printf("(x) %d ", x);
        printf("=");
        printf(" %d (y)\n", y);
    }
    s21_sub(*v1, *v2, result);
    print_dec(result);
    return 0;
}
// 10000000000000000000000000000000000000000000000000000000000000000001110111001101011001010001
// int main() {
//     int x = 5;
//     for (int idx = 31; idx >= 0; idx--) {
//         printf("idx = %d:%d\n", idx, GET_BIT(x, idx));
//     }
//     printf("\n");
//     return 0;
// }
//    float f = 100.5;
//    int i = *((int*)&f);
//    float k = *((float*)&i);
