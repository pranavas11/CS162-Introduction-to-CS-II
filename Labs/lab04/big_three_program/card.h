#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

class Card {
  private: 
    int rank;
    int suit;

  public:
    Card();										//constructors
    Card(int, int);
    Card(const Card &);
    Card & operator=(const Card &);

    ~Card();									//destructor
};

#endif