

all: s21_decimal.o libdecimal.a index test.o test run_test clean

main: s21_decimal.c s21_decimal.h main.c
	gcc main.c s21_decimal.c -lm -o main

clean:
	rm -rf *.o *.out *.a *.gcno *.gcda GcovReport* main report libdecimal.a test.o test

s21_decimal.o:
	gcc -g -c s21_decimal.c

libdecimal.a:
	ar rc libdecimal.a s21_decimal.o

index:
	ranlib libdecimal.a

test.o:
	gcc -g -c test.c
	
test:
	gcc test.o -o test -L. -ldecimal -lcheck -pthread -lm -lsubunit
	# gcc test.c -o test -lcheck -pthread -lm -lsubunit

run_test:
	./test
