CC = g++

FLAGS = -Wall

OBJ_1 = count_sort.o

OBJ_2 = bucket_sort.o

OBJ_RAND = randomize.o

all : count_sort bucket_sort

count_sort :	$(OBJ_1) ;
			$(CC) $(CFLAGS) -o count_sort $(OBJ_1)

count_sort.o : count_sort.cpp

bucket_sort : $(OBJ_2) ;
			  $(CC) $(CFLAGS) -o bucket_sort $(OBJ_2)

bucket_sort.o : bucket_sort.cpp

randomize : $(OBJ_RAND) ;
			$(CC) $(CFLAGS) -o randomize $(OBJ_RAND)

randomize.o : randomize.cpp

clean :
	rm -f *.o *.exe