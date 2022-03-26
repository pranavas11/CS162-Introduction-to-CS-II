CC = g++ -std=c++11 -g -Wall
exe_file = a.out
$(exe_file): Point.o prog.o
	$(CC) Point.o prog.o -o $(exe_file)
Point.o: Point.cpp
	$(CC) -c Point.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp

clean:
	rm -f *.out *.o $(exe_file)

.PHONY: clean
