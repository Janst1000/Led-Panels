CC = g++
CFLAGS = -Wall

OBJ_1 = problem_1.o

OBJ_2 = problem_2.o

OBJ_3 = WindGauge.o testWindGauge.o

OBJ_4 = problem_4.o

OBJ_5 = problem_5.o

all: problem_1 problem_2 problem_3 problem_4 problem_5

problem_1:	$(OBJ_1) ;
			$(CC) $(CFLAGS) -o problem_1 $(OBJ_1)

problem_1.o :	problem_1.cpp

problem_2:	$(OBJ_2) ;
			$(CC) $(CFLAGS) -o problem_2 $(OBJ_2)

problem_2.o :	problem_2.cpp

problem_3:	$(OBJ_3) ;
			$(CC) $(CFLAGS) -o testWindGauge $(OBJ_3)

WindGauge.o :	WindGauge.h WindGauge.cpp

testWindGauge.o :	WindGauge.h testWindGauge.cpp

problem_4 :	$(OBJ_4) ;
			$(CC) $(CFLAGS) -o problem_4 $(OBJ_4)

problem_4.o:	problem_4.cpp

problem_5 :	$(OBJ_5) ;
			$(CC) $(CFLAGS) -o problem_5 $(OBJ_5)

clean :
	rm -f *.o *.exe