
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

clear:
	rm -rf model/*.gch
	rm -fr *.o
	cd view && make clean

%.o: %.cc
	$(CC) -c $(CFLAGS) $<

