CC=g++
CXXFLAGS=-g -std=c++14 

OBJS = src/main.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o main ${OBJS} 

traza: ${OBJS}
	$(CC) src/main.cc -D TRAZA -o main

clean: 
	rm -rf src/*.o main