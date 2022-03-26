/*
	Animal Class
*/
#include <iostream>
#include "animal.h"

using namespace std;

Animal::Animal(string name, int age) {
	cout << "Alternate animal constructor called" << endl;
	this->name = name;
	this->age = age;
}

Animal::Animal() {
	cout << "Default animal constructor called" << endl;
	this->name = "Specimen Unknown";
	this->age = 0;
}

Animal::~Animal() {
	cout << "Animal destructor invoked" << endl;
}

string Animal::get_name() {
	return name;
}

void Animal::make_noise() {
	cout << "??? UNKNOWN NOISE" << endl;
}
