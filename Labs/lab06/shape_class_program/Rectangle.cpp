#include <iostream>
#include <cstdlib>
#include <string>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle() : Shape("rectangle", "red") {
	this->width = 0.0;
	this->height = 0.0;
}

Rectangle::Rectangle(float width, float height) : Shape("rectangle", "orange") {
	this->width = width;
	this->height = height;
}

float Rectangle::get_width() { return width; }

float Rectangle::get_height() { return height; }

float Rectangle::area() const { return width * height; }

bool Rectangle::operator > (const Rectangle &rec) {
	return this->area() > rec.area();
}

bool Rectangle::operator < (const Rectangle &rec) {
	return this->area() < rec.area();
}