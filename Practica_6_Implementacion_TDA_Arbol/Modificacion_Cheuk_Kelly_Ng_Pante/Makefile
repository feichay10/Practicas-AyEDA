CC=g++
CXXFLAGS=-g -std=c++14 

OBJS = src/main.o
MOD = src/main_modificacion.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o main ${OBJS} 

traza: ${OBJS}
	$(CC) src/main.cc -D TRAZA -o main_traza

modificacion: ${MOD}
	$(CC) src/main_modificacion.cc -o main_modificacion

clean: 
	rm -rf src/*.o main* 