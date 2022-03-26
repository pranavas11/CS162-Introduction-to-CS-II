#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <exception>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle() : Shape("rectangle", "red") {
	this->width = 0.0;
	this->height = 0.0;
}

Rectangle::Rectangle(float width, float height) : Shape("rectangle", "orange") {
	this->width = width;
	this->height = height;

	if (width * height == 0) {
		throw invalid_argument("\nInvalid constructor argument: area cannot be 0");
	}

	/*try {
		if (width * height == 0)
			throw invalid_argument("Invalid constructor argument: area cannot be 0");
	} catch (exception e) {
		cerr << "\n" << e.what() << "\n";
		cout << "Setting to default width and height of 1...\n";
		this->width = 1;
		this->height = 1;
	}*/
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