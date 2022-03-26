#ifndef WUMPUS_H
#define WUMPUS_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include "Event.h"
using namespace std;

class Wumpus : public Event {
	public:
		Wumpus();					// Wumpus constructor

		// polymorphic functions
		void percept();
		void encounter();

		~Wumpus();					// Wumpus destructor
};

#endif