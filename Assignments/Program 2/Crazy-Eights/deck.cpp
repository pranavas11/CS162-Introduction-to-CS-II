#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "card.h"
#include "deck.h"
using namespace std;

/**************************************************************************************
 * ** Constructor: Deck()
 * ** Description: assigns ranks and suits to each card in the deck of 52 cards
 * ** Parameters: none
 * ** Pre-conditions: stores number of cards in deck and loops through ranks and suits
 * ** Post-conditions: stores deck of 52 cards with ranks and suits
 *************************************************************************************/
Deck::Deck() {
	num_of_cards = 52;
	int index = 0;
	
	for (int i = 0; i < 13; i++) {			          // ranks
		for (int j = 0; j < 4; j++)			            // suits
			cards[index++] = Card(i + 1, j + 1);
  }
}

/************************************************************************************************************
 * ** Constructor: Deck()
 * ** Description: copy constructor which assigns cards to the old deck of cards
 * ** Parameters: const Deck& old_deck
 * ** Pre-conditions: takes const Deck& old_deck
 * ** Post-conditions: stores each card in the old deck (i.e., deck of 52 cards at the beginning of the game)
 ************************************************************************************************************/
Deck::Deck(const Deck& old_deck) {
	num_of_cards = old_deck.num_of_cards;
	for (int i = 0; i < 52; i++) {			// loop through the entire card deck array
		cards[i] = old_deck.cards[i];
	}
}

/*******************************************************************************************************
 * ** Constructor: Deck::operator()
 * ** Description: assignment operator overload constructor which assign cards to the old deck of cards
 * ** Parameters: const Deck& old_deck
 * ** Pre-conditions: takes const Deck& old_deck
 * ** Post-conditions: returns cards and number of cards from the old deck
 ******************************************************************************************************/
Deck& Deck::operator=(const Deck& old_deck) {
	if (this != &old_deck) {
		for (int i = 0; i < 52; i++) cards[i] = old_deck.cards[i];
	}
	return *this;
}

// accessor function which gets the number of cards from the deck
int Deck::get_num_of_cards() { return num_of_cards; }

// draws the top card from the deck of cards
Card Deck::draw_top_card() {
	// return null card if user tries to draw one when none exist
	if (num_of_cards == 0) return Card();
	return cards[--num_of_cards];		        // return top index
}

// accessor function which gets the top card from the deck
Card Deck::get_top_card() { return cards[num_of_cards-1]; }

/*******************************************************************************
 * ** Function: shuffle_deck()
 * ** Description: shuffle the deck of cards
 * ** Parameters: none
 * ** Pre-conditions: shuffles deck of cards in random order 5000 times
 * ** Post-conditions: swaps all cards in deck and returns them in random order
 ******************************************************************************/
void Deck::shuffle_deck() {
	srand(time(NULL));
	
	Card swap_card;
	int card1 = 0, card2 = 0;

	for (int i = 0; i < 5000; i++) {
		card1 = rand() % num_of_cards;		// 2 random indices
		card2 = rand() % num_of_cards;

		swap_card = cards[card1];		      // swap values (make card copies)
		cards[card1] = cards[card2];
		cards[card2] = swap_card;
	}
}

// deck destructor
Deck::~Deck() {
	//cout << "Deck destructor called...\n";
}

/***********************************************************************
 * ** Citations: used all constructors & member functions from my lab 3
 **********************************************************************/