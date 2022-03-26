#ifndef BEAR_H
#define BEAR_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Animal.h"
using namespace std;

class Black_bear : public Animal {    // Black_bear class inherits properties and member variables from Animal class
public:
	Black_bear();					              // default constructor
	Black_bear(int);			              // parameterized constructor
	Black_bear(const Black_bear&);      // copy constructor
	~Black_bear();				              // destructor
};

#endif