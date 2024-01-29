PROG = prog
CC = g++
OBJS = main.o Matrix.o
FLAGS = -g -Wall

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(FLAGS) -c main.cpp

Matrix.o : Matrix.h
	$(CC) $(FLAGS) -c Matrix.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
