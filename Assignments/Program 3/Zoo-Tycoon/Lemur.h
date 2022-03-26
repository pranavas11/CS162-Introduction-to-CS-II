#ifndef LEMUR_H
#define LEMUR_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Animal.h"
using namespace std;

class Lemur : public Animal {      // Lemur class inherits properties and member variables from Animal class
public:
	Lemur();					        // default constructor
	Lemur(int);				        // parameterized constructor
	Lemur(const Lemur&);      // copy constructor
	~Lemur();					        // destructor
};

#endif