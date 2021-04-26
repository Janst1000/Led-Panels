CC = g++

CFLAGS = -Wall

OBJ_1 = problem1.o Node.o HashTable.o

all : problem1

problem1 :	$(OBJ_1) ;
			$(CC) $(CFLAGS) -o problem1 $(OBJ_1)

problem1.o : Node.h problem1.cpp 

Node.o : Node.h Node.cpp

HashTable.o : Node.h HashTable.cpp

clean :
	rm -f *.o *.exe