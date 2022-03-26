# Makefile for application.cpp

CC = g++ -std=c++11
exe_file = geometry
$(exe_file): Shape.o Rectangle.o Square.o Circle.o Application.o
	$(CC) Shape.o Rectangle.o Square.o Circle.o Application.o -o $(exe_file)
Shape.o: Shape.cpp
	$(CC) -c Shape.cpp
Rectangle.o: Rectangle.cpp
	$(CC) -c Rectangle.cpp
Circle.o: Circle.cpp
	$(CC) -c Circle.cpp
Square.o: Square.cpp
	$(CC) -c Square.cpp

clean:
	rm -f *.out *.o $(exe_file)