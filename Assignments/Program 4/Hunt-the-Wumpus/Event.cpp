#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include "Event.h"
using namespace std;

// Event default constructor sets event_icon to empty event by default
Event::Event() { this->event_icon = " "; }

// setter function which will set a room to a new event
void Event::set_event_icon(string event_icon) {
	this->event_icon = event_icon;
}

string Event::get_event_icon() { return this->event_icon; }

Event::~Event() {
	//cout << "Event destructor called!\n";
}
