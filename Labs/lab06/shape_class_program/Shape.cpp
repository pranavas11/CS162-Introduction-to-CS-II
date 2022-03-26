#include <iostream>
#include <cstdlib>
#include <string>
#include "Shape.h"
using namespace std;

Shape::Shape() {
	this->name = "name";
	this->color = "color";
}

Shape::Shape(string name, string color) {
	this->name = name;
	this->color = color;
}

void Shape::set_name(string shape_name) {
	this->name = shape_name;
}

void Shape::set_color(string shape_color) {
	this->color = shape_color;
}

string Shape::get_name() { return name; }

string Shape::get_color() { return color; }

float Shape::area() { return 0; }