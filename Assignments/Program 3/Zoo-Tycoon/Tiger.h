#ifndef TIGER_H
#define TIGER_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Animal.h"
using namespace std;

class Tiger : public Animal {      // Tiger class inherits properties and member variables from Animal class
public:
	Tiger();					        // default constructor
	Tiger(int);				        // parameterized constructor
	Tiger(const Tiger&);      // copy constructor
	~Tiger();					        // destructor
};

#endif