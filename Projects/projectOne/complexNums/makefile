# created by Thomas Pearson 10/13/2023

PROG = prog
CC = g++
OBJS = main.o Complex.o
FLAGS = -g -Wall

${PROG} : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp

Complex.o : Complex.h
	$(CC) $(FLAGS) -c Complex.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
