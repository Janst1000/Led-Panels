CC = g++

FLAGS = -Wall

OBJ_1 = problem1.o

OBJ_RAND = randomize.o

all : problem1

problem1 :	$(OBJ_1) ;
			$(CC) $(CFLAGS) -o problem1 $(OBJ_1)

problem1.o : problem1.cpp

randomize : $(OBJ_RAND) ;
			$(CC) $(CFLAGS) -o randomize $(OBJ_RAND)

randomize.o : randomize.cpp

clean :
	rm -f *.o *.exe