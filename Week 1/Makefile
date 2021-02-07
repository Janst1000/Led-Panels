CC = g++
CFLAGS = -Wall

OBJ_1 = Complex.o test_array_search.o

OBJ_2 = testStack.o

OBJ_3 = testLinkedList.o

OBJ_4 = vectors1.o

all : problem_1 problem_2 problem_3

problem_1 : $(OBJ_1) ;
		  $(CC) $(CFLAGS) -o test_array_search $(OBJ_1)

test_array_search.o: Complex.h test_array_search.cpp

Complex.o: Complex.h Complex.cpp


problem_2 : $(OBJ_2) ;
			$(CC) $(CFLAGS) -o testStack $(OBJ_2)

testStack.o : Stack.h testStack.cpp

problem_3 : $(OBJ_3) ;
			$(CC) $(CFLAGS) -o testLinkedList $(OBJ_3)

testLinkedList.o : LinkedList.h testLinkedList.cpp

problem_4 : $(OBJ_4) ;
			$(CC) $(CFLAGS) -o vectors1 $(OBJ_4)

vectors1.o: vectors1.cpp

clean :
	rm -f *.o