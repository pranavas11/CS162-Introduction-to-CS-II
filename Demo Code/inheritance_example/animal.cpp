#include <iostream>
#include "animal.h"
using namespace std;

Animal::Animal() {
	cout << "\nDefault animal constructor called!" << endl;
	this->name = "Specimen Unknown";
	this->age = 0;
}

// alternate constructor which sets animal properties
Animal::Animal(string input_name, int age) {
	cout << "\n\n\nAlternate animal constructor called!" << endl;
	this->name = input_name;
	this->age = age;
}

string Animal::get_name() {
	return name;
}

int Animal::get_age() {
	cout << "\nAnimal get age called!" << endl;
	return age;
}

void Animal::set_name(string name) {
    this->name = name;
}