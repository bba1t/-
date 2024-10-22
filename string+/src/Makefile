WWW = -Werror -Wextra -Wall
G = gcc
OS = $(shell uname)

ifeq ($(OS), Linux)
	FLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
	FLAGS = -lcheck
endif

all : clean s21_string.a test gcov_report

clean: 
	rm -rf *.o *.a *.gch *.gcno *.gcna *.gcda *.info test test_html

test: clean
	$(G) $(WWW) s21_*.c unit_test.c $(FLAGS) -o test
	./test

s21_string.a:
	$(G) $(WWW) -c s21_*.c
	ar r s21_string.a *.o
	rm *.o

gcov_report:
	$(G) $(WWW) -fprofile-arcs -ftest-coverage unit_test.c s21_*.c $(FLAGS) -o test
	./test
	lcov -t "test_html" -o unit_test.info -c -d .
	genhtml -o test_html unit_test.info
	open test_html/index.html

leaks:
	leaks -atExit -- ./test
