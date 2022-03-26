# Makefile for zoo_tycoon.cpp

CC = g++ -std=c++11
exe_file = zoo_tycoon

$(exe_file): Animal.o Bear.o Lemur.o Tiger.o Zoo.o Zoo_tycoon.o
	$(CC) Animal.o Bear.o Lemur.o Tiger.o Zoo.o Zoo_tycoon.o -o $(exe_file)

Animal.o: Animal.cpp
	$(CC) -c Animal.cpp

Bear.o: Bear.cpp
	$(CC) -c Bear.cpp

Lemur.o: Lemur.cpp
	$(CC) -c Lemur.cpp

Tiger.o: Tiger.cpp
	$(CC) -c Tiger.cpp

Zoo.o: Zoo.cpp
	$(CC) -c Zoo.cpp

clean:
	rm -f *.out *.o $(exe_file)

.PHONY: clean
