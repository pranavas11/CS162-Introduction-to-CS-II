# Makefile for main.cpp
CC = g++ -std=c++11
exe_file = date
$(exe_file): date.o main.o
	$(CC) date.o main.o -o $(exe_file)
date.o: date.cpp
	$(CC) -c date.cpp
clean:
	rm -f *.out *.o output.* $(exe_file)