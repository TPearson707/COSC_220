PROG = prog
CC = g++
OBJS = main.o Point.o
FLAGS = -g -Wall

${PROG} : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(FLAGS) -c main.cpp

Point.o : Point.h
	$(CC) $(FLAGS) -c Point.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
