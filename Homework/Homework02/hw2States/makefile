PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o StateData.o

$(PROG) : $(OBJS)
	$(CC) -o $(CPPFLAGS) -c main.cpp

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

StateData.o : StateData.h StateData.cpp
	$(CC) $(CPPFLAGS) -c StateData.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
