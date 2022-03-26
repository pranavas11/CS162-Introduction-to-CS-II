#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <vector>
#include "AI.h"
using namespace std;

// AI default constructor sets default values to class member variables
AI::AI() {
	this->check_room = false;
	this->validate_room_event = false;
	this->room_event = " ";
}

bool AI::checked_room() { return check_room; }

bool AI::inspect_room() { return validate_room_event; }

string AI::get_event() { return room_event; }

// this method checks to verify a wumpus at particular room
bool AI::verify_wumpus() {
	bool wumpus_check = room->check_wumpus();
	if (wumpus_check == true) return true;
	return false;
}

// this method checks to verify a bat at particular room
bool AI::verify_bats() {
	bool bat_check = room->check_bats();
	if (bat_check == true) return true;
	return false;
}

// this method checks to verify a pit at particular room
bool AI::verify_pits() {
	bool pit_check = room->check_pit();
	if (pit_check == true) return true;
	return false;
}

// this method checks to verify a gold at particular room
bool AI::verify_gold() {
	bool gold_check = room->check_gold();
	if (gold_check == true) return true;
	return false;
}

/***************************************************************************************************************
 * ** Function: update_ai()
 * ** Description: updates the AI and adds an adjacent if necessary
 * ** Parameters: int row, int column, string adjacent
 * ** Pre-conditions: checks to verify if rooms are empty or not and sets the flags appropriately
 * ** Post-conditions: returns the updated vision of the AI's understandings of rows/columns/adjacent rooms
 **************************************************************************************************************/
void AI::update_ai(int row, int column, string adjacent) {
	if (validate_room_event) return;
	check_room = true;

	if (adjacent == "") {
		validate_room_event = true;
		return;
	}

	for (unsigned int i = 0; i < rows.size(); i++) {
		if (rows[i] == row && columns[i] == column) return;
		for (unsigned int j = 0; j < columns.size(); j++) {
			if (adjoining_events[i].find(adjacent.at(j)) != string::npos) {
				validate_room_event = true;
				room_event = adjacent.at(j);
				return;
			}
		}
	}
	
	rows.push_back(row);
	columns.push_back(column);
	adjoining_events.push_back(adjacent);
}

// this method resets the AI's understanding of game state back to normal
void AI::reset_ai() {
	this->rows.clear();
	this->columns.clear();
	this->adjoining_events.clear();
	this->check_room = false;
	this->validate_room_event = false;
	this->room_event = " ";
}

AI::~AI() {
	//cout << "AI destructor called!\n";
}
