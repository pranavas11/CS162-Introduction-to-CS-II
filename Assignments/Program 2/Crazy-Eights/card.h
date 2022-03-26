#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

class Card {
	int suit;				        // private member variables
	int rank;

public:
	Card();									// default constructor
	Card(int, int);					// parameterized constructor
	Card(const Card&);			// copy constructor
	Card& operator=(const Card&);    // assignment operator overload constructor

	~Card();								// destructor

	void setSuit(int);			// setters (i.e., mutators)
	void setRank(int);

	string toString();			// member function

	int getSuit();					// getters (i.e., accessors)
	int getRank();
};

#endif