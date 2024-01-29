# makefile created by Thomas Pearson 12/04/2023
PROG = prog
CC = g++
CPPFLAGS = -g -Wall
OBJS = main.o

${PROG} : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o :
	$(CC) $(CPPFLAGS) -c main.cpp

make clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
