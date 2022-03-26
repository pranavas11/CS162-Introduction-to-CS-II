#ifndef GOLD_H
#define GOLD_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include "Event.h"
using namespace std;

class Gold : public Event {
	public:
		Gold();					// Gold constructor

		// polymorphic functions
		void percept();
		void encounter();

		~Gold();					// Gold destructor
};

#endif