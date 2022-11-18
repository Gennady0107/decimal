#include "s21_decimal.h"

void print_dec(s21_decimal* dec) {
    for (int i = 0; i < 4; i++) {
        printf("%d: ", i);
        print_bit(dec->bits[i]);
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

int main () {
    int v1 = 7;
    int v2 = 7;
    s21_decimal* value_1;
    s21_decimal* value_2;
    s21_decimal* result;

    s21_init_decimal(&value_1);
    s21_init_decimal(&value_2);
    s21_init_decimal(&result);

    s21_from_int_to_decimal(v1, value_1);
    s21_from_int_to_decimal(v2, value_2);
    simple_sum(value_1, value_2, result);

    printf("\n");
    return 0;
}


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
