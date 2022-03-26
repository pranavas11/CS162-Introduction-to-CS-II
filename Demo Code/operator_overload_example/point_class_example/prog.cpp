#include <iostream>
#include "point.h"
using namespace std;

void print_point(const Point& p) {
	cout << "\n" << p.get_x() << " " << p.get_y() << endl;
}

int main() {
	Point p1(7, 11);
	print_point(p1);
  
	p1.print();
	print_location(p1);
  
  cout << "\n";
  
	p1 += 4;
	p1.print();
	cout << p1;

	return 0;
}