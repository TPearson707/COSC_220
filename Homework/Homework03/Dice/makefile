/*
 * Name: Thomas Pearson
 * Date of Creation: 9/26/2023
 * Date of Last Update: 9/28/2023
 */

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Array2D.o Dice.o

${PROG} : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Array2D.o : Array2D.h Array2D.cpp
	$(CC) $(CPPFLAGS) -c Array2D.cpp

Dice.o : Dice.h Dice.cpp
	$(CC) $(CPPFLAGS) -c Dice.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
