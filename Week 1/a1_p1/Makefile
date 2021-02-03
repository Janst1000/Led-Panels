CC = g++
CFLAGS = -Wall

OBJ = Complex.o test_array_search.o

all : test_array_search

test_array_search : $(OBJ) ;
		  $(CC) $(CFLAGS) -o test_array_search $(OBJ)

test_array_search.o: Complex.h test_array_search.cpp

Complex.o: Complex.h Complex.cpp

clean :
	rm -f test_array_search *.o

cleano :
	rm -f *.o