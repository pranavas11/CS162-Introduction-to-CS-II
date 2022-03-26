#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
using namespace std;

class Card {			// defaults to private member variables
	string suit;			// private member variables
	int rank;

public:
	Card();									// default constructor
	Card(string, int);			// parameterized constructor

	void setSuit(string);		// setters (i.e., mutators)
	void setRank(int);

	string getSuit();					// getters (i.e., accessors)
	int getRank();
};

#endif