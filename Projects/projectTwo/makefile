# makefile created by Thomas Pearson 10/31/2023

PROG = prog
CC = g++
CPPFLAGS = -g -Wall
OBJS = main.o Date.o FeetInches.o Person.o NBAPlayer.o NFLPlayer.o

${PROG} : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o :
	$(CC) $(CPPFLAGS) -c main.cpp

Date.o : Date.h
	$(CC) $(CPPFLAGS) -c Date.cpp

FeetInches.o : FeetInches.h
	$(CC) $(CPPFLAGS) -c FeetInches.cpp

Person.o : Person.h
	$(CC) $(CPPFLAGS) -c Person.cpp

NBAPlayer.o : NBAPlayer.h
	$(CC) $(CPPFLAGS) -c NBAPlayer.cpp

NFLPlayer.o : NFLPlayer.h
	$(CC) $(CPPFLAGS) -c NFLPlayer.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
