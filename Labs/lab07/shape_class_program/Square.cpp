#include <iostream>
#include <cstdlib>
#include <string>
#include "Square.h"
using namespace std;

Square::Square() : Rectangle(0,0) {
  set_name("square");
  set_color("magenta");
}

Square::Square(float dim) : Rectangle(dim, dim) {
	set_name("square");
  set_color("cyan");
}