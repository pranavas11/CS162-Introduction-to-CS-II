#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "card.h"
using namespace std;

// constructor which sets initial values of rank and suit to 0
Card::Card() {					// default constructor
	rank = 0;
	suit = 0;
}

// constructor which sets rank and suit to the new values of them
Card::Card(int new_rank, int new_suit) {		// overloaded constructor
	rank = new_rank;
	suit = new_suit;
}

// copy constructor which sets rank & suit to the old rank and suit values
Card::Card(const Card& old_card) {		// copy constructor
	rank = old_card.rank;
	suit = old_card.suit;
}

// assignment operator overload which returns old values of ranks and suits
Card& Card::operator=(const Card& old_card) {      // assignment operator overload
	rank = old_card.rank;
	suit = old_card.suit;
	return *this;
}

// mutator function which sets the values of rank
void Card::setRank(int new_rank) { rank = new_rank; }

// mutator function which sets the values of suit
void Card::setSuit(int new_suit) { suit = new_suit; }

// accessor function which gets the values of rank
int Card::getRank() { return rank; }

// accessor function which gets the values of suit
int Card::getSuit() { return suit; }

/***************************************************************************************
 * ** Function: toString()
 * ** Description: stores arrays of rank & suit values and returns rank and suit values
 * ** Parameters: none
 * ** Pre-conditions: stores arrays of rank and suit values
 * ** Post-conditions: returns rank and suit values as strings
 **************************************************************************************/
string Card::toString() {
	string rank_array[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	string suit_array[] = {"diamond", "heart", "club", "spade"};
	return "| " + rank_array[rank-1] + " " + suit_array[suit - 1] + " |";
}

// card destructor
Card::~Card() {
	//cout << "Card destructor called...\n";
}

/***********************************************************************
 * ** Citations: used all constructors & member functions from my lab 3
 **********************************************************************/