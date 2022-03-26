#include <iostream>
#include <cstdlib>
#include <string>
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"
using namespace std;

void print_shape_info(Shape& shape) {
	cout << "\nShape name: " << shape.get_name() << "\n";
	cout << "Shape color: " << shape.get_color() << "\n";
	cout << "Shape area: " << shape.area() << "\n";
}

int main() {
  Shape shape1 = Shape();			// same as Shape shape1;
	Rectangle rec1 = Rectangle(15, 37);
  Circle cir1 = Circle(79.3);
  Square square1 = Square(51.7);

	Shape* shape_arr[4] = {&shape1, &rec1, &cir1, &square1};
	for (int i = 0; i < 4; i++)
		print_shape_info(*shape_arr[i]);
	
	try {
		Rectangle rec2 = Rectangle(0,0);
		Circle circ = Circle(0);
  	Square test = Square(0);
	} catch (invalid_argument& invalid_arg) {
		cout << invalid_arg.what() << "\n";
	}

	/*Rectangle rec2 = Rectangle(0,0);
	Circle circ = Circle(0);
  Square test = Square(0);*/

	cout << "\n";

	return 0;
}