CC=g++
CXXFLAGS=-g -std=c++14 -Wall

OBJS = src/main.o src/bigint.o src/checkparameters.o src/board.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o main ${OBJS}

clean: 
	rm -rf src/*.o main