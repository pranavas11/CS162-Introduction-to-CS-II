#include <iostream>
#include "point.h"
using namespace std;

/*Point::Point(){
	cout << "Default point constructor!" << endl;
	init();
}*/

Point::Point(int a, int b) {
	x = a;
	y = b;
	count++;
}

Point::Point(const Point& old_obj) {
	cout << "Point copy constructor called!" << endl;
	x = old_obj.x;
	y = old_obj.y;
}

Point& Point::operator=(const Point& p) {
	cout << "Point assignment operator called!" << endl;
	x = p.x;
	y = p.y;
	return *this;
}

void Point::init() {
	x = 0;
	y = 0;
}

//Point::Point(int a, int b): x(a), y(b) {}

int Point::get_x() const {
	return x;
}

int Point::get_y() const {
	return y;
}

void Point::set_x(int new_x) {
	this->x = new_x;
}

void Point::set_y(int new_y) {
	y = new_y;
}

void Point::set_location(int new_x, int new_y){
	this->x = new_x;
	this->y = new_y;	
}

Point& Point::move_left(int delta) {
	x = x - delta;
	return *this;
}

Point& Point::move_up(int delta) {
	y = y + delta;
	return *this;
}

void Point::print(){
	cout << "X = " << x << ", Y = " << y << endl;
}

// static member variable "count" does not belong to any class (i.e., initialization takes place outside constructors/methods)
int Point::count = 0;

int Point::get_count(){
	cout << "Count: " << count << endl;
	return count;
}

Point::~Point(){
	cout << "\nPoint destroyed!!!" << endl;
}