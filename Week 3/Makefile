CC = g++

FLAGS = -Wall

OBJ_2 = problem_2.o

RAND = randomize.o

all: problem_2

problem_2:	$(OBJ_2) ;
			$(CC) $(CFLAGS) -o problem_2 $(OBJ_2)

problem_2.o :	problem_2.cpp

random:		$(RAND) ;
			$(CC) $(CFLAGS) -o randomize $(RAND)

randomize.o:	randomize.cpp

clean :
	rm -f *.o *.exe