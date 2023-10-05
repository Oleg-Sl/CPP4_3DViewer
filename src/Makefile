
CC				= g++
CFLAGS			= -Wall -Wextra -Werror -std=c++17

SOURCES			= $(wildcard model/*.cc)
OBJECTS			= $(SOURCES:.cc=.o)
TARGET			= 3d_viewer



run: $(OBJECTS)
	$(CC) $(FLAGS) -o ./$(TARGET) *.o main.cc
	./$(TARGET)

# g++ -Wall -Wextra -Werror main.cc model/*
# ./a.out

clear:
	rm -rf model/*.gch
	rm -fr *.o

%.o: %.cc
	$(CC) -c $(CFLAGS) $<

