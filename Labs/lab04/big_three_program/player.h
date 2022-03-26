#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <ctime>
#include "hand.h"
using namespace std;

class Player {
  private:
  	Hand hand;
    string name;
    int playerType;

  public:
    //constructors
    Player();
    Player(int);
    Player(const Player &);
    Player & operator=(const Player &);

    //destructor
    ~Player();
};

#endif