CC = g++ -std=c++11 -g -Wall
exe_file = profit
$(exe_file): catalog.o prog.o
	$(CC) catalog.o prog.o -o $(exe_file)
catalog.o: catalog.cpp
	$(CC) -c catalog.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp

clean:
	rm -f *.out *.o $(exe_file)

.PHONY: clean
