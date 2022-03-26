#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include "Wumpus.h"
using namespace std;

Wumpus::Wumpus () { this->event_icon = "w"; }      // "w" represents wumpus event

void Wumpus::percept() { cout << "\n\033[0;93mYou smell a terrible stench.\n"; }

void Wumpus::encounter() { cout << "\n\n\n\033[0;91mThe wumpus has woken up and engulfs you!\n\n\n\033[1;95m"; }

Wumpus::~Wumpus() {
	//cout << "Wumpus destructor called!\n";
}