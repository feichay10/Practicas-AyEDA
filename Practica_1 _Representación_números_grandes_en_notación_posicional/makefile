text0 = 
text1 = Se procedera a compilar la práctica...
text2 = Modo de empleo:
text3 = ./main [OPCION]
text4 = Se ha eliminado el fichero ejecutable y los ficheros objetos.

CC=g++
CXXFLAGS=-g -std=c++14 

OBJS = main.o bigint.o

all: ${OBJS}
	@echo $(text0)
	@echo $(text1)
	$(CC) $(CXXFLAGS) -o main ${OBJS}

	@echo $(text0)
	@echo $(text2)
	@echo $(text3)

clean: 
	rm -rf *.o main
	@echo $(text4)