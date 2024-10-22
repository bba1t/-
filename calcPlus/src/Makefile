BD=build
APP=$(BD)SmartCalc_v2_0.app
PATHTOAPP=./$(BD)/SmartCalc_v2_0.app/Contents/MacOS/SmartCalc_v2_0
CC=gcc
FLAGS= -Wall -Werror -Wextra -std=c++17 -lstdc++ -lgtest
TEST = ./SmartCalc_v2_0/googletests.cc
OUT= test
SOURCE = ./SmartCalc_v2_0/model.cc ./SmartCalc_v2_0/controller.cc ./SmartCalc_v2_0/creditModel.cc ./SmartCalc_v2_0/depositModel.cc
GCOVFLAGS= -fprofile-arcs -ftest-coverage
CC1 := $(CC)
LIBS= -I/usr/local/lib/QtWidgets.framework/Versions/A/Headers
UNITOUT = unit_tests
GCOVINFO = . --output-file test.info

all: clean tests gcov_report

install:
	@mkdir $(BD)
	@cd $(BD); cmake ../SmartCalc_v2_0
	@cd $(BD); make

run:
	@$(PATHTOAPP)

tests:
	@$(CC) $(FLAGS) $(LIBS) -o test $(SOURCE) $(TEST)
	@leaks -atExit -- ./test

gcov_report:
	@$(CC) $(FLAGS) $(GCOVFLAGS) $(LIBS) -o $(UNITOUT) $(SOURCE) $(TEST)	
	@./$(UNITOUT)
	@$(LCOV_PATH) --capture --directory $(GCOVINFO)
	@geninfo --ignore-errors mismatch $(GCOVINFO)
	@genhtml -o report test.info
	@open report/index.html

dvi:
	@doxygen Doxyfile && mv html documentation
	@open documentation/index.html

dist: clean
	@mkdir SmartCalc
	@cp SmartCalc_v2_0/*.cc SmartCalc_v2_0/*.h SmartCalc_v2_0/*.ui SmartCalc_v2_0/CMakeLists.txt SmartCalc_v2_0/CMakeLists.txt Makefile Doxyfile SmartCalc
	@tar -cvzf dist.tar.gz SmartCalc
	@-rm -rf SmartCalc

uninstall:
	@rm -rf $(BD)

clean: 
	@rm -rf $(OUT) *.a *.gch *.gcno *.gcna *.gcda *.info *.dSYM test_html .qmake.stash unit_tests report documentation latex *.gz