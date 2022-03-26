/*
	Animal Class
*/

#include <iostream>
#include "animal.h"

Animal::Animal(string name) {
	cout << "Alternate animal constructor called" << endl;
	this->name = name;
	this->age = 0;
}

Animal::Animal(string name, int age) {
	cout << "Alternate 2 animal constructor called" << endl;
	this->name = name;
	this->age = age;
}

Animal::Animal() {
	cout << "Default animal constructor called" << endl;
	this->name = "Specimen Unknown";
	this->age = 0;
}

// overload the pre-increment operator
Animal& Animal::operator++() {
	++age;
	return *this;
}

// overload the post-increment operator
// notice the dummy variable that is provided to distinguish
// this from the pre-increment operator
Animal Animal::operator++(int) {
	Animal old(*this); //copy constructor
	++(*this);
	return old;	
}

string Animal::get_name() const {
	return name;
}

int Animal::get_age() const{
	return age;
}

// overload the stream operator
ostream& operator<<(ostream& out, const Animal& a) {
	out << "Name: " << a.get_name() << ", Age: " << a.get_age();
	return out;
}

bool operator<(const Animal& a1, const Animal& a2){
	return (a1.get_age() < a2.get_age());
}

bool operator>(const Animal& a1, const Animal& a2){
	return (a1.get_age() > a2.get_age());
}

bool operator<(const Animal& a, int age){
	return (a.get_age() < age);
}