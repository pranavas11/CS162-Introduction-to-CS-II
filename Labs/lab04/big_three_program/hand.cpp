#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "hand.h"
using namespace std;

Hand::Hand() {
  //NOTE: There should NEVER be a hand with zero cards. That would be an impossible state. Zero is checked by the current card being a null card.

  numCards = 1;						//default is 1 null card
  cards = new Card[1];
  //cards[0] = Card(1, 1);
}

Hand::Hand(const Hand & oldHand) { //hand copy constructor
  //delete[] cards;
	cout << "Hand copy constructor called!\n";
  numCards = oldHand.numCards;
  cards = new Card[oldHand.numCards];
  for(int i = 0; i < oldHand.numCards; i++)
		cards[i] = oldHand.cards[i];
}

Hand & Hand::operator=(const Hand & oldHand) {
	cout << "Hand assignment operator overload called!\n";
	if (this != &oldHand) {

  numCards = oldHand.numCards;
	
  delete[] cards;

  cards = new Card[numCards];
  for(int i = 0; i < numCards; i++)
    cards[i] = oldHand.cards[i];
	}
	return *this;
}

Hand::~Hand() {
	cout << "Hand destructor called!\n";
  delete[] cards;
}