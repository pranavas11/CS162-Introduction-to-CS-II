#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <ctime>
#include "card.h"
using namespace std;

class Deck {		// defaults to private member variables
	Card* cards;

public:
	Deck();									// constructor
	~Deck();								// destructor

	void shuffle_deck();
	void print_deck();
};

#endif