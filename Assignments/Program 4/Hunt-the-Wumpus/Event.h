#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <vector>
using std::string;

class Event {
	protected:
		string event_icon;

	public:
		Event();					// Event constructor

		void set_event_icon(string);

		// getter (accessor) function
		string get_event_icon();

		// pure virtual functions for polymorphism
		virtual void percept() = 0;
		virtual void encounter() = 0;
		
		virtual ~Event();					// Event destructor
};

#endif