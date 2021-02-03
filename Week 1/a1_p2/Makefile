CC = g++
CFLAGS = -Wall

OBJ = testStack.o

all : testStack

testStack : $(OBJ) ;
		  $(CC) $(CFLAGS) -o testStack $(OBJ)

testStack.o: Stack.h testStack.cpp

clean :
	rm -f testStack *.o

cleano :
	rm -f *.o