# makefile created by Thomas Pearson 11/25/2023

PROG = prog
CC = g++
CPPFLAGS = -g -Wall
OBJS = main.o Process.o

${PROG} : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o :
	$(CC) $(CPPFLAGS) -c main.cpp

Process.o : Process.h
	$(CC) $(CPPFLAGS) -c Process.cpp

clean :
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
