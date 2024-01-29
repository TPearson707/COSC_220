PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o IntArrayList.o

$(PROG) : $(OBJS)
	$(CC) -o $(CPPFLAGS) -c main.cpp

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Array2D.o : IntArrayList.h IntArrayList.cpp
	$(CC) $(CPPFLAGS) -c IntArrayList.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
