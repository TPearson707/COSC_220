# Created by Thomas Pearson 10/19/2023

PROG = prog
OBJS = main.o Dice.o
CC = g++
FLAGS = -g -Wall

${PROG} : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o :
	$(CC) $(FLAGS) -c main.cpp

Dice.o : Dice.h
	$(CC) $(FLAGS) -c Dice.cpp

clean :
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make

