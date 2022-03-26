#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "player.h"
using namespace std;

// player constructor
Player::Player() {
	hand = Hand();        // invokes assignment operator overload condtructor from Hand class
	name = "player";      // set default value for player names
	player_type = -1;     // set default value for player types
}

/**********************************************************************
 * ** Constructor: Player()
 * ** Description: gets player names according to player types
 * ** Parameters: int player_type_num
 * ** Pre-conditions: takes int player_type_num
 * ** Post-conditions: returns names of the human and computer players
 *********************************************************************/
Player::Player(int player_type_num) {
	hand = Hand();
	player_type = player_type_num;
	if (player_type == 0) {					    // human player
		cout << "Enter your name: ";
		cin >> name;
	} else {								            // robot player
		cout << "\nCreating a Computer Player...\n";
		name = "Chaobot";
	}
}

// copy constructor which sets hand and name to the current player
Player::Player(const Player& new_player) {
	this->hand = new_player.hand;        // sets hand to the current two players
	this->name = new_player.name;        // sets name to the current two players
}

// assignment operator overload which returns both new player's hand and name
Player& Player::operator=(const Player& new_player) {
	this->hand = new_player.hand;        // sets hand to the current two players
	this->name = new_player.name;        // sets name to the current two players
	return *this;
}

// accessor function which returns the player's hand of cards
Hand Player::get_hand() { return hand; }

// accessor function which returns the player's name
string Player::get_name() { return name; }

// accessor function which returns the player's type (human/computer)
int Player::get_player_type() { return player_type; }

// member function which adds cards from deck to player's hand
void Player::add_to_hand(Card new_card) {
	hand.add_to_cards(new_card);      // calls the add_to_cards() function from Hand class
}

// prints the player's hand of cards
void Player::print_hand() { hand.print_hand(); }

// checks if the player has a valid card match in their hand
bool Player::is_valid_card(Card new_card) {
	return hand.has_valid_match(new_card);      // calls the has_valid_match() function from Hand class
}

/****************************************************************
 * ** Function: human_card_choice()
 * ** Description: gets human's choice of card from his/her hand
 * ** Parameters: Card human_card
 * ** Pre-conditions: takes Card human_card
 * ** Post-conditions: returns player's choice of valid card
 ***************************************************************/
Card Player::human_card_choice(Card human_card) {
	int input;

	do {		              // must return card with same rank or same suit or an 8
		while (true) {
			cout << "\nPlease enter the number of the card: ";
			cin >> input;
			if (input >= 0 && input <= hand.get_num_of_cards() - 1)      // input should be less than total cards in hand (index starts at 0)
				break;
		}

		cout << "\nChoice is in valid range!\n";
		if (hand.get_card(input).getRank() == 8 || hand.get_card(input).getRank() == human_card.getRank() || hand.get_card(input).getSuit() == human_card.getSuit())
			break;
	} while(true);

	return hand.draw_card(input);          // calls the draw_card() function from the Hand class
}

/***************************************************************
 * ** Function: computer_card_choice()
 * ** Description: gets computer's choice of card from its hand
 * ** Parameters: Card computer_card
 * ** Pre-conditions: takes Card computer_card
 * ** Post-conditions: returns computer's choice of valid card
 **************************************************************/
Card Player::computer_card_choice(Card computer_card) {
	int card_num = 0;
	while (true) {
		if (hand.has_valid_match(computer_card) == true) {      // if computer's card matches with player's card (if either rank or suit matches or an 8)
			return hand.draw_card(card_num);            // calls the draw_card() function from the Hand class
			card_num++;
		}
	}
}

// player destructor
Player::~Player() {
	//cout << "Player destructor called...\n";
}

/***************************************************************************************************
 * ** Citations: used samples of constructors & member functions from my labs and previous 3 classes
 * ** Additional Resources: used Dr. Goins posted OOP examples (ex: advanced point class)
 ***************************************************************************************************/