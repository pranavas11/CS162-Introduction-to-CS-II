#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point {
	private:
		int x;
		int y;
		static int count;

	public:
		Point(int a = 0, int b = 0);
		Point(const Point&);
		Point& operator=(const Point&);
    ~Point();

		void init();
		int get_x() const;
		void set_x(int);
		int get_y() const;
		void set_y(int);
		void set_location(int, int);
		Point& move_left(int);
		Point& move_up(int);
		void print();
		static int get_count();
		Point& operator+=(int x);

		friend void print_location(const Point&);
};

// global operator overload (overloads the " << " operator)
ostream& operator<<(ostream&, const Point&);

#endif