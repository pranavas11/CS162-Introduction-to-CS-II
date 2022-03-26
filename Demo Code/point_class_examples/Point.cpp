#include <iostream>
#include "Point.h"
using namespace std;

// DEFAULT constructor
Point::Point() {
	cout << "\n\n\nConstructed a point!" << endl;
	desc = new string;
	*desc = "Default location";
	x = 25;
	y = 65;
}

// alternate constructor
// set the position at time of creation
Point::Point(int x, int y) {
	cout << "\nConstructed a point at: " << x << ", " << y << endl;
	// we have a special pointer called "this", which points to the object currently being manipulated
	desc = new string;
	*desc = "Random assigned location";
	this->x = x;
	this->y = y;
}

// COPY CONSTRUCTOR
Point::Point(const Point& old_obj) {
	// copy the contents of old_obj and assign them to the current obj
	// "this" is a pointer to the newly constructed object
	// old_obj is a reference to the source object

	cout << "\nInvoked the copy constructor!" << endl;
	this->x = old_obj.x;
	this->y = old_obj.y;
	this->secret_value = old_obj.secret_value;

	string* tmp = new string;
	*tmp = *(old_obj.desc);
	this->desc = tmp;
}

// Overloaded assignment operator
Point& Point::operator=(const Point& old_obj) {
	cout << "\nOverloaded assignment operator invoked!!!\n" << endl;
	// Copy the contents of the old_obj to the modified object
	this->x = old_obj.x;
	this->y = old_obj.y;
	this->secret_value = old_obj.secret_value;

	// Notice that this is very similar to the copy constructor, but not exactly the same.
	// we did not need to allocate a new string on the heap in this scenario...
	*(this->desc) = *(old_obj.desc);
	return *this;
}

void Point::move_right(int diff) {
	move_to_zero();
	x = x + diff;
  *desc = "New location";
  // cout << "Description: " << *desc << endl;
}

void Point::move_to_zero() {
	x = 0;
	y = 0;
}

int Point::get_x() {
	return x;
}


// print_position is promising not to edit anything within the Point class
void Point::print_position() const {
	cout << "Description: " << *desc << endl;
	cout << "Selected point is at " << x << ", " << y << endl;
}

void Point::set_position(int new_x, int new_y) {
	x = new_x;
	y = new_y;
}

// DESTRUCTOR
Point::~Point() {
	delete desc;
	cout << "A point was just destroyed!\n" << endl;
}