#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include "Room.h"
using namespace std;

// room starts with no event in default constructor
Room::Room() { this->room_event = nullptr; }

// setter function which sets the events to random empty rooms
void Room::set_event(Event* new_event) {
	if (this->room_event != nullptr) return;      // returns if room is not empty
	else this->room_event = new_event;          // set a empty room to a new event
}

// getter functions returns the event at any particular room inside grid
string Room::get_event() {
	if (this->room_event == nullptr) return " ";      // return empty room if room is empty
	return this->room_event->get_event_icon();      // get event type from any particular room
}

void Room::percept_room() {
	if (room_event == nullptr) return;      // return if room is empty
	else room_event->percept();      // calls appropriate percept methods corresponding to room event types
}

// displays encounter messages as a player enters a room with any event
void Room::encounter_room() {
	if (this->room_event == nullptr) return;      // return if room is empty
	else {
		this->room_event->encounter();      // calls appropriate encounter methods corresponding to room event types
		if (room_event->get_event_icon() == "g") {      // if a room contains gold
			delete room_event;			// delete event (i.e., player picks up the gold)
			room_event = nullptr;      // always reset pointer to nullptr so it doesn't point to garbage after deleting the value
		}
	}
}

bool Room::is_empty() {
	if (room_event != nullptr) return false;      // returns false if room is not empty
	return true;
}

void Room::delete_event() {
	if (this->room_event != nullptr) {      // if room is not empty
		delete room_event;                  // delete event
		room_event = nullptr;              // reset pointer
	}
}

bool Room::check_wumpus() {
	if (room_event != nullptr && room_event->get_event_icon() == "w") return true;      // checks if a room contains the wumpus
	return false;
}

void Room::kill_wumpus(bool& destroy_wumpus) {
	bool wumpus_check = check_wumpus();
	//bool destroy_wumpus = false;
	if (wumpus_check == true) {
		destroy_wumpus = true;
		cout << "\n\n\n\033[0;92mHooray!!! You've killed the wumpus! Great job!\n";
		delete room_event;			// kill the wumpus
		room_event = nullptr;
	}
}

bool Room::check_bats() {
	if (room_event != nullptr && room_event->get_event_icon() == "b") return true;      // checks if a room contains a bat
	return false;
}

bool Room::check_pit() {
	if (room_event != nullptr && room_event->get_event_icon() == "p") return true;      // checks if a room contains a pit
	return false;
}

bool Room::check_gold() {
	if (room_event != nullptr && room_event->get_event_icon() == "g") return true;      // checks if a room contains gold
	return false;
}

// destructor: room no longer exists
Room::~Room() {
	if (this->room_event != nullptr) delete room_event;      // delete event if room is not empty
}
