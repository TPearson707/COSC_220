# makefile created by Thomas Pearson on 11/06/2023

PROG = prog
CC = g++
FLAGS = -g -Wall
OBJS = main.o

${PROG} : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o :
	$(CC) $(FLAGS) -c main.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
