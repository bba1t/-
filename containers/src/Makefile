CC=g++
# FLAGS=-Wall -Werror -Wextra -std=c++17 - Bait's make presets
# TEST_FLAGS = -lgtest -pthread -lgtest_main

CFLAGS = -Wall -Werror -Wextra -std=c++17 -lstdc++
TEST_FLAGS = -lgtest_main -lgtest
TEST_TARGET = testing_exe

all: test

test: 
	# @echo --------------------- START ---------------------
	# $(CC) -c $(FLAGS) ./tests/test_containers.cc -o ./tests/test_containers.o -pedantic -fsanitize=address
	# $(CC) ./tests/test_containers.o -o ./tests/test_containers -L/path/to/gtest/lib -lgtest -lstdc++ -std=c++17 -lm -pedantic 
	# ./tests/test_containers
	# @echo -------------------- SUCCESS --------------------

	@$(CC) $(CFLAGS) tests/*.cc $(TEST_FLAGS) -o $(TEST_TARGET) && ./$(TEST_TARGET)


leaks: test
	leaks -atExit -- ./test_containers


clang:
	cp ../materials/linters/.clang-format ../src
	clang-format --style=google -i s21_containersplus.h
	clang-format --style=google -n s21_containersplus.h
	clang-format --style=google -i s21_containers/s21_stack.h
	clang-format --style=google -n s21_containers/s21_stack.h
	clang-format --style=google -i s21_containers/vector/*
	clang-format --style=google -n s21_containers/vector/*
	clang-format --style=google -i s21_containers_extra/array/*
	clang-format --style=google -n s21_containers_extra/array/*
	clang-format --style=google -i tests/*
	clang-format --style=google -n tests/*
	rm -rf .clang-format

clean:
	rm -rf a.out containers/*.gch tests/*.o tests/test_containers .clang-format *.gcno *.html *.css
