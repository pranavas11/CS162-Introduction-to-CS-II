#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "card.h"
using namespace std;

class Hand {
	Card* cards;								// heap array of cards
	int num_of_cards;						// number of cards in hand

public:
	Hand();											// default constructor
	Hand(const Hand&);					// copy constructor
	Hand& operator=(const Hand&);      // assignment operator overload

	~Hand();										// destructor

	int get_num_of_cards();			// getters (accessors)
	Card get_card(int);

	void print_hand();					// member functions
	bool has_valid_match(Card);

	void add_to_cards(Card);		// setter (mutator)

	Card draw_card(int);				// member function
};

#endif