WWW =  -Wall -Wextra -Wall -std=c++17
G = g++

all: clean s21_matrix_oop.a test

test: clean
	$(G) $(WWW) s21_matrix_oop.cc s21_matrix_tests.cc -o test -lgtest -pthread
	./test

s21_matrix_oop.a:
	$(G) $(WWW) -c s21_matrix_oop.cc s21_matrix_oop.h
	ar r s21_matrix_oop.a *.o
	rm *.o

style_i:
	clang-format -style=google -i *.cc *.h

style_n:
	clang-format -style=google -n *.cc *.h

clean:
	rm -rf test *.o *.a *.gch *.gcno *.gcna *.gcda *.info test_html test.DSYM

valgrind:
	valgrind --leak-check=full --leak-resolution=med ./test

leaks:
	leaks -atExit -- ./test
