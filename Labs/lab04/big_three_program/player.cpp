#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "player.h"
using namespace std;

Player::Player() {
  hand = Hand();
  name = "name";
  playerType = -1;    
}

Player::Player(int n) {
  hand = Hand();
  playerType = n;

  if(playerType == 0) {					//human player
    cout << "Enter your name: ";
    cin >> name;
  } else {											//robot player
    cout << "Creating computer player..." << endl;
    name = "HAL";
  }
}

Player::Player(const Player & newPlayer) {
    //cout << "Player copy constructor called..." << endl;
  hand = newPlayer.hand;
  name = newPlayer.name;
}

Player & Player::operator=(const Player & oldPlayer) {
  //cout << "Overloaded constructor: about to overwrite hand..." << endl;
  hand = oldPlayer.hand;		// hand overwritten
  name = oldPlayer.name;		// name overwritten
  return *this;
}

Player::~Player() {
  //cout << "Player destructor called..." << endl;
}