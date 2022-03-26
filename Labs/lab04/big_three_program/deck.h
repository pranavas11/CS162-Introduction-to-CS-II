#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <ctime>
#include "card.h"
using namespace std;

class Deck {
  private:
    Card cards[52];
    int numCards;  // number of cards remaining in the deck
    
	public:
    //constructors
    Deck();
    Deck(const Deck &);
    Deck & operator=(const Deck &);

    //destructor
    ~Deck();
};

#endif