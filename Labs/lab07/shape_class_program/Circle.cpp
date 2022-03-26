#include <iostream>
#include <cstdlib>
#include <string>
#include <exception>
#include <stdexcept>
#include "Circle.h"
using namespace std;

Circle::Circle() : Shape("circle", "white") { this->radius = 0.0; }

Circle::Circle(float radius) : Shape("circle", "black") {
	this->radius = radius;

	try {
		if (radius == 0) throw invalid_argument("Invalid radius: radius cannot be 0");
	} catch (exception e) {
		cerr << "\n" << e.what() << "\n";
		cout << "Setting to default radius of 1...\n";
		this->radius = 1;
	}
}

float Circle::get_radius() { return radius; }

float Circle::area() const {
	return 3.14 * this->radius * this->radius;	// pi * r^2
}