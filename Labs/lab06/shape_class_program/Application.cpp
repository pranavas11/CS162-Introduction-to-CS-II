#include <iostream>
#include <cstdlib>
#include <string>
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"
using namespace std;

int main() {
  Shape shape1;
  Shape shape2("diamond", "red");

	Rectangle rec1;
  Rectangle rec2(15, 37);

  Circle cir1;
  Circle cir2(79.3);

  Square square1;
  Square square2(51.7);

	cout << "\nShape1: " << shape1.get_name() << " " << shape1.get_color() << endl;
  cout << "Shape2: " << shape2.get_name() << " " << shape2.get_color() << endl << endl;

	cout << "rec1: " << rec1.get_name() << " " << rec1.get_color() << " " << rec1.area() << endl;
  cout << "rec2: " << rec2.get_name() << " " << rec2.get_color() << " " << rec2.area() << endl << endl;

	cout << "circ1: " << cir1.get_name() << " " << cir1.get_color() << " " << cir1.area() << endl;
  cout << "circ2: " << cir2.get_name() << " " << cir2.get_color() << " " << cir2.area() << endl << endl;

  cout << "square1: " << square1.get_name() << " " << square1.get_color() << " " << square1.area() << endl;
  cout << "square2: " << square2.get_name() << " " << square2.get_color() << " " << square2.area() << "\n\n";

  cout << "square1 area > rec2 area: " << boolalpha << (square1 > rec2) << endl;
  cout << "rec1 area < square2 area: " << boolalpha << (rec1 < square2) << "\n\n\n";

	return 0;
}