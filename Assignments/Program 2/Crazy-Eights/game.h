#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "deck.h"
#include "player.h"
using namespace std;

class Game {
	Deck cards;
	Player players[2];

public:
	Game();								      // constructor
	~Game();							      // destructor

	Deck get_cards();			      // getters (accessors)
	Player get_player(int);
  Card get_human_card(Card);
	Card get_computer_card(Card);

	bool player_has_valid_card(int, Card);		// member functions
	Card flip_top_card();
	void print_human_hand();
	void print_computer_hand();
  void human_player_draw_card();
	void computer_player_draw_card();
};

#endif