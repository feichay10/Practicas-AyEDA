CC=g++
CXXFLAGS=-g -std=c++14

OBJS = src/main.o src/functions.o src/calculator.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o main ${OBJS}

clean: 
	rm -rf src/*.o main