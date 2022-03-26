#Makefile for prog_fileio.cpp
CC = g++ -std=c++11
exe_file = book_app

$(exe_file): book.o prog_fileio.o
	$(CC) book.o prog_fileio.o -o $(exe_file)

book.o: book.cpp
	$(CC) -c book.cpp

prog_fileio.o: prog_fileio.cpp
	$(CC) -c prog_fileio.cpp

clean:
	rm -f *.out *.o $(exe_file)

.PHONY: clean