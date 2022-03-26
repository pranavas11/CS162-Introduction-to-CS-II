#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "hand.h"
using namespace std;

// hand default constructor which allocates dynamic memory for each card in the deck
Hand::Hand() {
	num_of_cards = 1;			// lowest possible card a player can have in hand
	this->cards = new Card[num_of_cards];
}

/**********************************************************************************************************************************
 * ** Constructor: Hand()
 * ** Description: copy constructor which assigns total_cards and cards to the old hand of cards
 * ** Parameters: const Deck& old_deck
 * ** Pre-conditions: takes const Deck& old_deck
 * ** Post-conditions: stores each card in the player's old hand (i.e., copy constructor keeps track of player's old hand of cards)
 **********************************************************************************************************************************/
Hand::Hand(const Hand& old_hand) {
	this->num_of_cards = old_hand.num_of_cards;        // assign num_of_cards to old hand's cards
	this->cards = new Card[old_hand.num_of_cards];     // create new array of cards on the heap
	for (int i = 0; i < num_of_cards; i++)
		cards[i] = old_hand.cards[i];                    // assign all cards player's old hand cards
}

/*******************************************************************************************************
 * ** Constructor: Hand::operator()
 * ** Description: assignment operator overload constructor which assign cards to the old hand of cards
 * ** Parameters: const Deck& old_deck
 * ** Pre-conditions: takes const Deck& old_deck
 * ** Post-conditions: returns cards and number of cards from player's old hand
 ******************************************************************************************************/
Hand& Hand::operator=(const Hand& old_hand) {
	this->num_of_cards = old_hand.num_of_cards;        // assign num_of_cards to old hand's cards
	delete [] cards;                                   // delete old array of cards to prevent memory leaks

	cards = new Card[num_of_cards];                    // create new array of cards on the heap
	for (int i = 0; i < num_of_cards; i++)
		cards[i] = old_hand.cards[i];                    // assign all cards player's old hand cards
	
	return *this;
}

// accessor function which gets the total number of cards from player's hand
int Hand::get_num_of_cards() { return num_of_cards; }

// accessor function which gets each card at all indexes from the player's hand
Card Hand::get_card(int num) { return cards[num]; }

// print the player's hand of cards
void Hand::print_hand() {
	for (int i = 0; i < num_of_cards; i++) {
		cout << "Card " << i << " " << cards[i].toString() << "\n";
  }
}

/************************************************************************************************
 * ** Function: has_valid_match()
 * ** Description: checks for a valid match of cards
 * ** Parameters: Card verify_card
 * ** Pre-conditions: takes Card verify_card
 * ** Post-conditions: returns true/false if a valid match for a card is found in the player hand
 ************************************************************************************************/
bool Hand::has_valid_match(Card verify_card) {
	for (int i = 0; i < num_of_cards; i++) {	        // loop through all cards in hand
		if (cards[i].getRank() == verify_card.getRank() || cards[i].getSuit() == verify_card.getSuit()) {
			cout << "\nCard " << verify_card.toString() << " has been found in deck at index " << i << ".\n";
			return true;
		}
		if (cards[i].getRank() == 8) {                  // 8 is a special case
			cout << "\nHand has an 8!\n";
			return true;
		}
	}
	
	return false;
}

/******************************************************************************
 * ** Function: add_to_cards()
 * ** Description: adds cards from the deck to player's hand of cards
 * ** Parameters: Card new_card
 * ** Pre-conditions: takes Card new_card
 * ** Post-conditions: returns added cards from deck to player's hand of cards
 *****************************************************************************/
void Hand::add_to_cards(Card new_card) {
	if(cards[0].getRank() == 0 || cards[0].getSuit() == 0)	// catch for null deck
		cards[0] = new_card;		// overwrite the existing one
	else {
		Card* temp = new Card[num_of_cards+1];		// temp array

		for (int i = 0; i < num_of_cards; i++)	// loop through cards in current array
			temp[i] = cards[i];			// copy to temp array
		
		delete[] cards;				// destroy old array

		cards = temp;					// copy new one
		cards[num_of_cards++] = new_card;		// assign new card to end of array, increment numCards
	}
}

/*****************************************************************************
 * ** Function: draw_card()
 * ** Description: draws a card at a particular index from the player's hand
 * ** Parameters: int index
 * ** Pre-conditions: takes int index
 * ** Post-conditions: discards matching card from the player's hand of cards
 ****************************************************************************/
Card Hand::draw_card(int index) {
	Card* temp = new Card[num_of_cards-1];		// new card array with 1 less index
	Card card_to_play = cards[index];		// card to return at current hand index

	int write_to_index = 0;
	for (int i = 0; i < num_of_cards; i++) {	// loop through card array
		if (i != index) temp[i-write_to_index] = cards[i];
		else write_to_index++;
	}
 
	delete[] cards;				// delete old array

	cards = temp;					// reassigning cards
	num_of_cards--;		    // decrement cards to reflect new array

	cout << "\nReturning card at index " << index << "...\n";
	return card_to_play;
}

// hand destructor deallocates memory for cards
Hand::~Hand() {
	delete[] cards;          // delete cards array from the heap to prevent memory leaks
}

/****************************************************************************************
 * ** Citations: used all constructors & member functions from my labs 3 & 4
 * ** Additional Resources: used Dr. Goins posted OOP examples (ex: advanced point class)
 ***************************************************************************************/