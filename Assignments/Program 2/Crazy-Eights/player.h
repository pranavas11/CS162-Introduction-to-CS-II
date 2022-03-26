#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "hand.h"
using namespace std;

class Player {
	Hand hand;
	string name;
	int player_type;

public:
	Player();						// default constructor
	Player(int);				// parameterized constructor
	Player(const Player&);		// copy constructor
	Player& operator=(const Player&);  // constructor overload

	~Player();					// destructor

	Hand get_hand();					// getters (accessors)
	string get_name();
	int get_player_type();
	void add_to_hand(Card);		// setter (mutator)
	
	void print_hand();				// member functions
	bool is_valid_card(Card);
	Card human_card_choice(Card);
	Card computer_card_choice(Card);
};

#endif