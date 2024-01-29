# Name: Thomas Pearson
# Date of Creation: 10/11/2023
# Date of Last Update: 10/11/2023


PROG = prog
CC = g++
OBJS = main.o PersonData.o CustomerData.o PreferredCustomer.o
FLAGS = -g -Wall

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)
	
main.o : main.cpp
	$(CC) $(FLAGS) -c main.cpp
	
PersonData.o : PersonData.h
	$(CC) $(FLAGS) -c PersonData.cpp

CustomerData.o : CustomerData.h
	$(CC) $(FLAGS) -c CustomerData.cpp

PreferredCustomer.o : PreferredCustomer.h
	$(CC) $(FLAGS) -c PreferredCustomer.cpp

clean:
	rm -f core $(PROG) $(OBJS)
	
rebuild:
	make clean
	make
