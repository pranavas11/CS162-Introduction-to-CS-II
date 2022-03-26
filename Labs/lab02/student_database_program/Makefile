# Makefile for main.cpp

CC = g++ -Wall -std=c++11
exe_file = student_db
$(exe_file): student_db.o main.o
	$(CC) student_db.o main.o -o $(exe_file)
student_db.o: student_db.cpp
	$(CC) -c student_db.cpp
main.o: main.cpp
	$(CC) -c main.cpp
 
clean:
	rm -f *.out *.o outputs.* $$(exe_file)