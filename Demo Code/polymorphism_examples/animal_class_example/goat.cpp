/*
	Goat Class
*/
#include <iostream>
#include "goat.h"

using namespace std;

Goat::Goat() : Animal("Billy", 0) {
	cout << "Default goat constructor called" << endl;
}

Goat::Goat(string name) : Animal(name, 0) {
	cout << "Special goat constructor called" << endl;
}

Goat::~Goat() {
	cout << "Goat destructor called." << endl;
}


void Goat::make_noise() {
   cout << "Bleat & Scream!!!" << endl;
}
