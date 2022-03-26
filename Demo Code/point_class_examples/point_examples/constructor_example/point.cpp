#include <iostream>
#include "point.h"

using namespace std;

/*Point::Point(){
	cout << "Default point constructor" << endl;
	init();
}*/

Point::Point(int a, int b){
	cout << "Parameterized constructor (default if no arguments provided)" << endl;
	x=a;
	y=b;
}

void Point::init(){
	x=0;
	y=0;
}

//Point::Point(int a, int b):x(a),y(b){}

int Point::get_x(){
	return x;
}

int Point::get_y(){
	return y;
}

void Point::set_x(int new_x){
	x = new_x;
}

void Point::set_y(int new_y){
	y = new_y;
}

void Point::set_location(int new_x, int new_y){
	x = new_x;
	y = new_y;	
}

void Point::move_left(int delta) {
	x = x - delta;
}

void Point::print_point(){
	cout << "X = " << x << ", Y = " << y <<endl;
}
