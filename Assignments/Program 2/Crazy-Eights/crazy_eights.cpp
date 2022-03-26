/********************************************************************************
** Program: crazy_eights.cpp
** Author: Pranav Prabhu
** Date: 04/16/2021
** Description: this program plays the game of Crazy Eights
** Input: user's choice of a valid card to play from deck or draw card from deck
** Output: player's hand, top card, valid card match, and winner of the game
********************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "game.h"
using namespace std;

/***********************************************************************************************
 * ** Function: play_game()
 * ** Description: creates class instances & calls class member functions to play the game
 * ** Parameters: none
 * ** Pre-conditions: creates class instances for Game, Card, & Deck and gets top card from deck
 * ** Post-conditions: plays the game of Crazy Eights
 ***********************************************************************************************/
void play_game() {
	cout << "\n\n\nWelcome to the game of Crazy Eights!\n\n\n";

	Game crazy_eight;            // instance (object) of the Game class
	Card top_card;               // instance (object) of the Card class
	Deck num_cards;              // instance (object) of the Deck class
	top_card = crazy_eight.flip_top_card();      // fetches the top card from the deck

	cout << "\nTop card: " << top_card.toString() << "\n";
	cout << "\nThere are " << num_cards.get_num_of_cards() << " in the deck.\n";

	while (crazy_eight.get_cards().get_num_of_cards() != 0) {        // loop through until the deck runs out of cards
		crazy_eight.print_human_hand();

		while (!crazy_eight.player_has_valid_card(0, top_card) && crazy_eight.get_cards().get_num_of_cards() != 0) {    // if human player doesn't have a valid card
			int input;
			cout << "\nYou don't have a card! Please enter 1 to draw from the deck: ";
			cin >> input;
      crazy_eight.human_player_draw_card();        // draw card(s) from the deck to the player's hand
			crazy_eight.print_human_hand();
		}

		if (crazy_eight.player_has_valid_card(0, top_card) && crazy_eight.get_cards().get_num_of_cards() != 0) {      // if human player has a valid card in hand
			cout << "\nYou have a valid card!\n";
			Card new_human_top_card = crazy_eight.get_human_card(top_card);        // get human's choice of a valid card

			if (new_human_top_card.getRank() == 8) {          // check if human hand has rank = 8
				int new_suit = 0;
				while (new_suit < 1 || new_suit > 4) {
					cout << "\nPlease specify a suit (1 = diamond, 2 = heart, 3 = club, 4 = spade): ";
					cin >> new_suit;
				}
				new_human_top_card.setSuit(new_suit);          // set a suit for player's card
			}
			top_card = new_human_top_card;        // set top card to human's choice of card
		}

		cout << "\nTop Card: " << top_card.toString() << "\n";

		while (!crazy_eight.player_has_valid_card(1, top_card) && crazy_eight.get_cards().get_num_of_cards() != 0) {    // if computer doesn't have a valid card
			cout << "\nSorry, I do not have a card! Drawing a card from the deck now...\n";
      crazy_eight.computer_player_draw_card();          // draw card from the deck to computer's hand
		}
		
		if (crazy_eight.player_has_valid_card(1, top_card) && crazy_eight.get_cards().get_num_of_cards() != 0) {    // check if computer has a valid card in hand
			crazy_eight.print_computer_hand();
			cout << "\nChaobot has a valid card!\n";
			Card new_computer_top_card = crazy_eight.get_computer_card(top_card);          // get computer's choice of a valid card

			if (new_computer_top_card.getRank() == 8) {         // check if computer hand has rank = 8
				srand(time(NULL));
				int new_suit = (rand() % 4) + 1;                 // pick a random suit for the card
				new_computer_top_card.setSuit(new_suit);        // set the suit for computer's card
			}
			top_card = new_computer_top_card;                // set top card to computer's choice of card
		}
	}
	
	Player human_player = crazy_eight.get_player(0);                      // get human player
	Hand get_human_hand = human_player.get_hand();                        // get human player's hand of cards
	int human_hand_cards = get_human_hand.get_num_of_cards();             // get number of cards from human player
	
	Player computer_player = crazy_eight.get_player(1);                   // get computer player
	Hand get_computer_hand = computer_player.get_hand();                  // get computer player's hand of cards
	int computer_hand_cards = get_computer_hand.get_num_of_cards();       // get number of cards from computer player

	if (human_hand_cards < computer_hand_cards) {              // if human player has less cards in hand, he/she is the winner
		cout << "\n\n\nCongratulations!!! You win the game!";
	} else {                                                   // if computer player has less cards in hand, it is the winner
		cout << "\n\n\nChaobot has won the game!\n\n\n";
	}
}

int main() {                  // main() function has the player for a rematch
  play_game();

	char play_again;

	cout << "\n\n\nDo you want to play again (y/n)? ";
	cin >> play_again;

	while (true) {
		if (play_again == 'Y' || play_again == 'y') {
			play_game();
		} else {
			cout << "\n\n\nThanks for playing Crazy Eights!!! Please play again!\n\n\n";
			break;
		}
	}

	return 0;
}