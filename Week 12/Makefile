CC = g++

CFLAGS = -Wall

OBJ_1 = problem1.o

OBJ_2 = Triangle.o problem2.o

all : problem2

problem1 :	$(OBJ_1) ;
			$(CC) $(CFLAGS) -o problem1 $(OBJ_1)

problem1.o : problem1.cpp

problem2 :	$(OBJ_2) ;
			$(CC) $(CFLAGS) -o problem2 $(OBJ_2)

problem2.o : Triangle.h problem2.cpp

Triangle.o : Triangle.h Triangle.cpp

clean :
	rm -f *.o *.exe