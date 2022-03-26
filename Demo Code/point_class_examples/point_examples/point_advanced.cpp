#include <iostream>
using namespace std;

class Point {
public:
	Point();
	Point(int, int);
	void move_right(int);
	void set_position(int, int);
	void print_position();
	int get_x();

private:
	int x_position;
	int y_position;
	int secret_value;
	void move_to_zero();
};

// DEFAULT constructor
Point::Point() {
	cout << "Constructed a point!" << endl;
	x_position = 25;
	y_position = 65;
}

// alternate constructor
// set the position at time of creation
Point::Point(int x, int y) {
	cout << "Constructed a point at: " << x << ", " << y << endl;
	x_position = x;
	y_position = y;
}

void Point::move_right(int diff) {
	move_to_zero();
	x_position = x_position + diff;
}

void Point::move_to_zero() {
	x_position = 0;
	y_position = 0;
}

int Point::get_x() {
	return x_position;
}

void Point::print_position() {
	cout << "Selected point is at " << x_position << ", " << y_position << endl;
}

void Point::set_position(int new_x, int new_y) {
	x_position = new_x;
	y_position = new_y;
}

int main() {

	Point p1;
//	p1.set_position(523, -36);

	p1.print_position();
	p1.move_right(123);
	p1.print_position();

	Point p2;
	p2.set_position(42, 11);
	p2.print_position();

	Point p3(34, 67);
	p3.print_position();
	return 0;
}
