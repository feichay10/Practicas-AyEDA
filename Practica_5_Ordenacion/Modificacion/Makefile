CC=g++
CXXFLAGS=-g -std=c++14 

OBJS = src/main.o
MOD = src/main_modification.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o main ${OBJS} 

traza: ${OBJS}
	$(CC) src/main.cc -D TRAZA -o main_traza

modificacion: ${MOD}
	$(CC) src/main_modification.cc -o main_modification

clean: 
	rm -rf src/*.o main* 