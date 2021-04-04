CC = g++

FLAGS = -Wall

OBJ_1 = count_sort.o

OBJ_2 = bucket_sort.o

OBJ_3 = word_sort.o

OBJ_RAND = randomize.o

all : count_sort bucket_sort word_sort

count_sort :	$(OBJ_1) ;
			$(CC) $(CFLAGS) -o count_sort $(OBJ_1)

count_sort.o : count_sort.cpp

bucket_sort : $(OBJ_2) ;
			  $(CC) $(CFLAGS) -o bucket_sort $(OBJ_2)

bucket_sort.o : bucket_sort.cpp

word_sort :	$(OBJ_3) ;
			$(CC) $(CFLAGS) -o word_sort $(OBJ_1)

word_sort.o : word_sort.cpp

randomize : $(OBJ_RAND) ;
			$(CC) $(CFLAGS) -o randomize $(OBJ_RAND)

randomize.o : randomize.cpp

clean :
	rm -f *.o *.exe