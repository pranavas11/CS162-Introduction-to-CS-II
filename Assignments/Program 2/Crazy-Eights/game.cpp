#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "game.h"
using namespace std;

/**********************************************************************
 * ** Constructor: Game()
 * ** Description: shuffles deck and assigns 7 cards to each player's hand
 * ** Parameters: none
 * ** Pre-conditions: calls Deck class's default constructor and sets players
 * ** Post-conditions: returns cards added to both player's hand
 *********************************************************************/
Game::Game() {
	cards = Deck();                   // calls deck constructor to assign rank and suit for each card
	players[0] = Player(0);           // human player
	players[1] = Player(1);           // computer player
	
	cards.shuffle_deck();
	
	for (int i = 0; i < 7; i++) {		                      // 7 cards for each player
		players[0].add_to_hand(cards.draw_top_card());
		players[1].add_to_hand(cards.draw_top_card());
	}
}

// accessor function which returns cards from the deck to player
Deck Game::get_cards() { return cards; }

// accessor function which returns the player type for both players
Player Game::get_player(int player) { return players[player]; }

// verifies both player's card matches during the game
bool Game::player_has_valid_card(int player_type, Card verify_card) {
	return players[player_type].is_valid_card(verify_card);
}

// draws top card from the deck for each player
Card Game::flip_top_card() { return cards.draw_top_card(); }

// prints the human's hand of cards
void Game::print_human_hand() {
	cout << "\nIt's your turn now! :)\n";
	players[0].print_hand();
}

// comuter's hand is kept hidden during the game
void Game::print_computer_hand() {
	cout << "\nComputer's Turn!\n";
	//players[1].print_hand();
}

// returns human's choice of cards from his/her hand
Card Game::get_human_card(Card human_top_card) {
	return players[0].human_card_choice(human_top_card);
}

// returns computer's choice of cards from its hand
Card Game::get_computer_card(Card computer_top_card) {
	return players[1].computer_card_choice(computer_top_card);
}

// if human player runs out of cards, draw cards from the deck to the player's hand
void Game::human_player_draw_card() {
	players[0].add_to_hand(cards.draw_top_card());
}

// if computer player runs out of cards, draw cards from the deck to the player's hand
void Game::computer_player_draw_card() {
	players[1].add_to_hand(cards.draw_top_card());
}

// game destructor
Game::~Game() {
	//cout << "Player destructor called...\n";
}

/***************************************************************************************************
 * ** Citations: used samples of constructors & member functions from my labs and previous 4 classes
 * ** Additional Resources: used Dr. Goins posted OOP examples
 ***************************************************************************************************/