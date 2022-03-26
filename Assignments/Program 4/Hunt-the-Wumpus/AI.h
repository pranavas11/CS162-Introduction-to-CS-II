#ifndef AI_H
#define AI_H

#include <iostream>
#include <string>
#include <vector>
#include "Room.h"

class AI {
	private:
		Room* room;
		vector<int> rows;
		vector<int> columns;
		vector<string> adjoining_events;
		bool check_room, validate_room_event;
		string room_event;

	public:
		AI();					// default constructor
    
    // public methods
		bool checked_room();
		bool inspect_room();
		string get_event();
		bool verify_wumpus();
		bool verify_bats();
		bool verify_pits();
		bool verify_gold();
		void update_ai(int, int, string);
		void reset_ai();

		~AI();			// destructor
};

#endif