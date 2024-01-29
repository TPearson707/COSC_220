# Created by Thomas Pearson 10/24/2023

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o NumberList.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

NumberList.o : NumberList.h NumberList.cpp
	$(CC) $(CPPFLAGS) -c NumberList.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
