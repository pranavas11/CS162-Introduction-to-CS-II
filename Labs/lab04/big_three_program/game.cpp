#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <ctime>
#include "game.h"
using namespace std;

Game::Game() {
  //cout << "Game constructor called..." << endl;
  cards = Deck();			//populate deck with 52 cards

  players[0] = Player(0);			//create human player
  players[1] = Player(1);			//create computer player
}

Game::~Game() {
  //cout << "Game destructor called..." << endl;
}