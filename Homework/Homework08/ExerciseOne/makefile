# makefile created by Thomas Pearson on 11/06/2023

PROG = prog
CC = g++
FLAGS = -g -Wall
OBJS = StackQueueTest.o

${PROG} : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

StackQueueTest.o :
	$(CC) $(FLAGS) -c StackQueueTest.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
