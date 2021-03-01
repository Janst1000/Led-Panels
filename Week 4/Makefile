CC = g++

FLAGS = -Wall

OBJ_1 = problem1.o

OBJ_2 = worstcase.o

all : problem1 worstcase

problem1 :	$(OBJ_1) ;
			$(CC) $(CFLAGS) -o problem1 $(OBJ_1)

problem1.o : problem1.cpp

worstcase :	$(OBJ_2) ;
			$(CC) $(CFLAGS) -o worstcase $(OBJ_2)

worstcase.o : worstcase.cpp

clean :
	rm -f *.o *.exe