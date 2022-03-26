#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include "Gold.h"
using namespace std;

Gold::Gold() { this->event_icon = "g"; }      // "g" represents gold event

void Gold::percept() { cout << "\n\033[0;93mYou see a glimmer nearby!\n"; }

void Gold::encounter() { cout << "\n\n\n\033[1;34m\033[4;34mCongrats!!! You pick up the precious gold you came for! Make it safe to the exit!\033[0m\n"; }

Gold::~Gold() {
	//cout << "Gold destructor called!\n";
}