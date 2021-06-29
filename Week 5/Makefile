CC = g++

FLAGS = -Wall

OBJ_1 = fibonacci.o

all : fibonacci

fibonacci :	$(OBJ_1) ;
			$(CC) $(CFLAGS) -o fibonacci $(OBJ_1)

fibonacci.o : fibonacci.cpp

clean :
	rm -f *.o *.exe