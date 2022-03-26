#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <ctime>
#include "deck.h"
#include "player.h"
using namespace std;

class Game {
  private:
    Deck cards;
    Player players[2];

  public:
    Game();								//constructor
    ~Game();							//destructor
};

#endif