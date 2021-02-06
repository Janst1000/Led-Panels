CC = g++
CFLAGS = -Wall

OBJ_1 = Complex.o test_array_search.o

OBJ_2 = testStack.o

all : problem_1 problem_2

problem_1 : $(OBJ_1) ;
		  $(CC) $(CFLAGS) -o test_array_search $(OBJ_1)

test_array_search.o: Complex.h test_array_search.cpp

Complex.o: Complex.h Complex.cpp


problem_2 : $(OBJ_2) ;
			$(CC) $(CFLAGS) -o testStack $(OBJ_2)

testStack.o : Stack.h testStack.cpp

clean :
	rm -f *.o