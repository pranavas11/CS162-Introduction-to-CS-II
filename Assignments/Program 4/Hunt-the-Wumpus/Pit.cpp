#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include "Pit.h"
using namespace std;

Pit::Pit() { this->event_icon = "p"; }      // "p" represents pit event

void Pit::percept() { cout << "\n\033[0;93mYou feel a breeze!\n"; }

void Pit::encounter() { cout << "\n\n\n\033[0;91mYou have entered a room with bottomless pit where you had freefalled!\n\n\n\033[1;95m"; }

Pit::~Pit() {
	//cout << "Pit destructor called!\n";
}