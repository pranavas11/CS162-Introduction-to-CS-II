# Makefile for Linked_List_Program.cpp

CC = g++ -Wall -Wextra -Werror -Wfatal-errors -pedantic -g -std=c++11

exe_file = linked_list

$(exe_file): Node.o Linked_List.o
	$(CC) Node.o Linked_List.o Linked_List_Program.cpp -o $(exe_file)

Node.o: Node.cpp
	$(CC) -c Node.cpp

Linked_List.o: Linked_List.cpp
	$(CC) -c Linked_List.cpp

clean:
	rm -f *.out *.o $(exe_file)

.PHONY: clean
