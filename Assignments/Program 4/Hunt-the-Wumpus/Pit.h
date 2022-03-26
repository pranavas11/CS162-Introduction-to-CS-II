#ifndef PIT_H
#define PIT_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include "Event.h"
using namespace std;

class Pit : public Event {
	public:
		Pit();					// Pit constructor

		// polymorphic functions
		void percept();
		void encounter();

		~Pit();					// Pit destructor
};

#endif