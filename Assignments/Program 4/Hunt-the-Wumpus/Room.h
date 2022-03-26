#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Event.h"
#include "Wumpus.h"
#include "Bats.h"
#include "Pit.h"
#include "Gold.h"

class Room {
	private:
		Event* room_event;

	public:
		Room();      // default constructor

		// setter (mutator) function
		void set_event(Event*);

		// getter (accessor) function
		string get_event();

		// member functions
		void percept_room();
		void encounter_room();
		bool is_empty();
		void delete_event();
		bool check_wumpus();
		void kill_wumpus(bool&);
		bool check_bats();
		bool check_pit();
		bool check_gold();
    
		~Room();      // destructor
};

#endif