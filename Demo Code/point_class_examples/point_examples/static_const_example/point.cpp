#include <iostream>
#include "point.h"

using namespace std;

/*Point::Point(){
	cout << "Default point constructor" << endl;
	init();
}*/

Point::Point(int a, int b){
	x=a;
	y=b;
	count++;
}

void Point::init(){
	x=0;
	y=0;
}

//Point::Point(int a, int b):x(a),y(b){}

int Point::get_x() const {
	return x;
}

int Point::get_y() const {
	return y;
}

void Point::set_x(int banana){
	this->x = banana;
}

void Point::set_y(int new_y){
	y = new_y;
}

void Point::set_location(int new_x, int new_y){
	x = new_x;
	y = new_y;	
}

Point& Point::move_left(int delta) {
	x = x - delta;
	return *this;
}

Point& Point::move_up(int delta) {
	y = y + delta;
	return *this;
}

void Point::print_point(){
	cout << "X = " << x << ", Y = " << y <<endl;
}

int Point::count = 0;

int Point::get_count(){
	cout << count << endl;
	return count;
}