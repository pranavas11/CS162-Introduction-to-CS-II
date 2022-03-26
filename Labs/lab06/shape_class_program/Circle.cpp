#include <iostream>
#include <cstdlib>
#include <string>
#include "Circle.h"
using namespace std;

Circle::Circle() : Shape("circle", "white") { this->radius = 0.0; }

Circle::Circle(float radius) : Shape("circle", "black") { this->radius = radius; }

float Circle::get_radius() { return radius; }

float Circle::area() {
	return 3.14 * this->radius * this->radius;	// pi * r^2
}