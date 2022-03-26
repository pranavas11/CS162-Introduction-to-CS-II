#ifndef BATS_H
#define BATS_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include "Event.h"
using namespace std;

class Bats : public Event {
	public:
		Bats();					// Bats constructor

		// polymorphic functions
		void percept();
		void encounter();

		~Bats();					// Bats destructor
};

#endif