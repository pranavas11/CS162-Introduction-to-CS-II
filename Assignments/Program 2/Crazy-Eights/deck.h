#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "card.h"
using namespace std;

class Deck {
	Card cards[52];		      // array instance of Card class
	int num_of_cards;       // number of cards remaining in the deck

public:
	Deck();									// default constructor
  Deck(const Deck &);			// copy constructor
	Deck& operator=(const Deck&);		// assignment operator overload

	~Deck();								// destructor

	int get_num_of_cards();			// getter (accessor)
  Card draw_top_card();
  Card get_top_card();

	void shuffle_deck();			  // member function
};

#endif