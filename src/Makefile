
CC				= g++
CFLAGS			= -Wall -Wextra -Werror -std=c++17

SOURCES			= $(wildcard model/*.cc)
OBJECTS			= $(SOURCES:.cc=.o)
TARGET			= 3d_viewer



run: $(OBJECTS)
	$(CC) $(CFLAGS) -o ./$(TARGET) *.o main.cc
	./$(TARGET)

# g++ -Wall -Wextra -Werror main.cc model/*
# ./a.out

clean:
	rm -rf model/*.gch
	rm -fr *.o

reader: $(OBJECTS)
	cd tests && $(CC) $(CFLAGS) -o ./reader ../*.o reader_test.cc -lgtest
	tests/reader

%.o: %.cc
	$(CC) -c $(CFLAGS) $<

