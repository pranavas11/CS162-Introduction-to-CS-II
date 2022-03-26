#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <ctime>
#include "card.h"
using namespace std;

class Hand {
  private:
  	Card* cards;			// heap array of cards
    int numCards;			// number of cards in the hand

  public:
    //constructor
    Hand();
    Hand(const Hand &);
    Hand & operator=(const Hand &);

    //destructor
    ~Hand();
};

#endif