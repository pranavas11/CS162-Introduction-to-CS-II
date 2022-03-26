#include <iostream>
#include "point.h"
using namespace std;

/*Point::Point(){
	cout << "Default point constructor" << endl;
	init();
}*/

Point::Point(int a, int b) {
	x = a;
	y = b;
	count++;
	cout << "\n\n\nPoint created!" << endl;
}

// Point::Point(int a, int b): x(a), y(b) {}

Point::Point(const Point& old_obj){
	cout << "Point copy constructor" << endl;
	x = old_obj.x;
	y = old_obj.y;
}

Point& Point::operator=(const Point& p){
	cout << "Point assignment operator" << endl;
	x = p.x;
	y = p.y;
	return *this;
}

// overloads the " += " operator
Point& Point::operator+=(int x){
	this->x += x;
	this->y += x;
	return *this;
}

ostream& operator<<(ostream& out, const Point& p){
	out << "Point (" << p.get_x() << ", " << p.get_y() << ")" << endl;
	return out;
}

void Point::init() {
	x = 0;
	y = 0;
}

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

void Point::set_location(int new_x, int new_y) {
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

void Point::print() {
	cout << "X = " << x << ", Y = " << y <<endl;
}

int Point::count = 0;

int Point::get_count() {
	cout << "Count: " << count << endl;
	return count;
}

void print_location(const Point& p){
	cout << "Location is (" << p.x << ", " << p.y << ")" << endl;
}

Point::~Point() {
	cout << "\nPoint destroyed!!!\n\n\n" << endl;
}