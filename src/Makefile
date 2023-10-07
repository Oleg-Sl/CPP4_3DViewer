
CC				= g++
CFLAGS			= -Wall -Wextra -Werror -std=c++17

SOURCES			= $(wildcard model/*.cc)
OBJECTS			= $(SOURCES:.cc=.o)
TARGET			= 3d_viewer



build:
	cd view && make clean && make && open 3d_viewer
# .app

run: $(OBJECTS)
	$(CC) $(CFLAGS) -o ./$(TARGET) *.o main.cc
	./$(TARGET)

# g++ -Wall -Wextra -Werror main.cc model/*
# ./a.out

clean:
	cd view && make clean
	rm -rf model/*.gch
	rm -fr *.o
	cd view && make clean

reader: $(OBJECTS)
	cd tests && $(CC) $(CFLAGS) -o ./reader ../*.o reader_test.cc -lgtest
	tests/reader

%.o: %.cc
	$(CC) -c $(CFLAGS) $<

autoformat:
	find . -type f -name "*.cc" -o -name "*.h" | xargs clang-format -style=Google -i