#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include "Bats.h"
using namespace std;

Bats::Bats() { this->event_icon = "b"; }      // "b" represents bat event

void Bats::percept() { cout << "\n\033[0;93mYou hear wings flapping!\n"; }

void Bats::encounter() { cout << "\n\n\n\033[0;91mOh no, the bats have taken you to a new room!\n"; }

Bats::~Bats() {
	//cout << "Bats destructor called!\n";
}