CC = g++

FLAGS = -Wall

OBJ_1 = count_sort.o

OBJ_RAND = randomize.o

all : count_sort

count_sort :	$(OBJ_1) ;
			$(CC) $(CFLAGS) -o count_sort $(OBJ_1)

count_sort.o : count_sort.cpp

randomize : $(OBJ_RAND) ;
			$(CC) $(CFLAGS) -o randomize $(OBJ_RAND)

randomize.o : randomize.cpp

clean :
	rm -f *.o *.exe