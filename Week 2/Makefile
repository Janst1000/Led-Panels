CC = g++
CFLAGS = -Wall

OBJ_1 = problem_1.o

OBJ_2 = problem_2.o

all: problem_1 problem_2

problem_1:	$(OBJ_1) ;
			$(CC) $(CFLAGS) -o problem_1 $(OBJ_1)

problem_1.o :	problem_1.cpp

problem_2:	$(OBJ_2) ;
			$(CC) $(CFLAGS) -o problem_2 $(OBJ_2)

problem_2.o :	problem_2.cpp

clean :
	rm -f *.o *.exe