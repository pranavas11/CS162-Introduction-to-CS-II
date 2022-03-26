CC = g++ -std=c++11 -g -Wall
exe_file = a.out
$(exe_file): House.o Person.o prog.o
	$(CC) House.o Person.o prog.o -o $(exe_file)
House.o: House.cpp
	$(CC) -c House.cpp
Person.o: Person.cpp
	$(CC) -c Person.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp

clean:
	rm -f *.out *.o $(exe_file)

.PHONY: clean
