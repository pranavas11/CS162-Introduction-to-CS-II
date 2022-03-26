#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <ctime>
#include "card.h"
using namespace std;

Card::Card() {					// default constructor
	cout << "Card default constructor called!\n";
	rank = 0;
	suit = 0;
}

// overloaded constructor
Card::Card(int new_rank, int new_suit) {
	cout << "Card parameterized constructor called!\n";
	rank = new_rank;
	suit = new_suit;
}

Card::Card(const Card& old_card) {		// copy constructor
	cout << "Card copy constructor called!\n";
	rank = old_card.rank;
	suit = old_card.suit;
}

Card& Card::operator=(const Card& old_card) {
	cout << "Card overloaded assignment operator called!\n";
	rank = old_card.rank;
	suit = old_card.suit;
	return *this;
}

Card::~Card() {
	//cout << "Card destructor called...\n";
}