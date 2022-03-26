#include <iostream>
#include "point.h"

using namespace std;

void print_info(const Point& p){
	//p.set_location(34,78);
	cout << p.get_x() << " " << p.get_y() << endl;
}

int main(){
	Point p1;
	Point::get_count();
	Point p2(112,7);
	Point p3(7);

	print_info(p3);
	p3.move_up(5).move_left(22).print_point();
	
	const Point p4(50,50);
	Point::get_count();

	return 0;
}