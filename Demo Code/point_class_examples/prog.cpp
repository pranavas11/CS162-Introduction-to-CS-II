#include <iostream>
#include <stdlib.h>
#include "Point.h"
using namespace std;

// writing a special function to illustrate the usage of const
void doSomething(const Point& ref) {
	ref.print_position();
}

int main() {
	Point p1;
  // p1.set_position(523, -36);
	p1.print_position();
	p1.move_right(123);
	p1.print_position();

	Point p2;
	p2.set_position(42, 11);
	p2.print_position();

	Point p3(34, 67);
	p3.print_position();
	doSomething(p3);

	Point py = p2;      // invoking the copy constructor
	Point pz = p1;      // again invokes the copy constructor
	Point px(p2);      // also invokes the copy constructor
  
	pz = p3;          // invokes the overloaded assignment operator function (NOT the copy constructor)!
  
	return 0;
	// p1, p2, p3, etc. went poof!
	// (the destructors were automatically called because the instances went out of scope)
}
