BUILD_DIR = build
VIEW_DIR = view
MODEL_DIR = model
CALCULATOR_EXE = calculator
TEST_DIR = tests
TEST_EXE = test
TEST_SRC = test.cc
CXX = g++
CFLAGS = -Werror -Wextra -Wall
LIBS =
OS = $(shell uname -s)
MACOS = Darwin

ifeq ($(OS), $(MACOS))
CALCULATOR_EXE = calculator.app
endif

.PHONY: all install dvi uninstall gcov_report test clean valgrind autoformat dist

all: install

dvi:
	open dvi.md

install:
	mkdir -p $(BUILD_DIR)
	cd $(VIEW_DIR) && qmake && make
	mv $(VIEW_DIR)/$(CALCULATOR_EXE) $(BUILD_DIR)

uninstall: clean
	rm -rf $(BUILD_DIR)

tests: model/objreaderfast.o model/scene.o model/transform_matrix.o  model/transform_matrix_builder.o
	mv *.o $(TEST_DIR)
	cd $(TEST_DIR) && $(CXX) $(CFLAGS) *.cc *.o -o $(TEST_EXE) $(LIBS) -lgtest
	$(TEST_DIR)/$(TEST_EXE)

clean_tests:
	rm -rf $(TEST_DIR)/*.o $(TEST_DIR)/$(TEST_EXE)

clean: clean_tests
	cd $(VIEW_DIR) && qmake && make clean
	rm -rf $(VIEW_DIR)/.qmake.stash $(VIEW_DIR)/Makefile
	
autoformat:
	find . -type f -name "*.cc" -o -name "*.h" | xargs clang-format -style=Google -i

dist:
	mkdir -p source
	cp -r Makefile view model controller tests obj_examples main.cc source
	tar -cf source.tar source
	rm -rf source

%.o: %.cc
	$(CXX) -c $(CFLAGS) $<