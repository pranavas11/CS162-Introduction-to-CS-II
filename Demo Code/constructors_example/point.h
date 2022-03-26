#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point {
	private:
		int x;
		int y;

	public:
		// Point();      // default constructor
		// Point(int, int);      // alternate constructor 1
		Point(int a = 0, int b = 0);      // alternate constructor 2

		void init();
		int get_x();
		void set_x(int);
		int get_y();
		void set_y(int);
		void set_location(int, int);
		void move_left(int);
		void print_point();
};

#endif