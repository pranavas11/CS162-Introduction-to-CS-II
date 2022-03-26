#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <ctime>
#include "card.h"
#include "deck.h"
using namespace std;

Deck::Deck() {
	cout << "\n\n\nMaking a new deck...\n\n\n";
	cards = new Card[52];
	for (int i = 0; i < 13; i++) {
		cards[i] = Card("diamond", i+1);
	}
	for (int i = 0; i < 13; i++) {
		cards[13+i] = Card("club", i+1);
	}
	for (int i = 0; i < 13; i++) {
		cards[26+i] = Card("heart", i+1);
	}
	for (int i = 0; i < 13; i++) {
		cards[39+i] = Card("spade", i+1);
	}
}

Deck::~Deck() {
	cout << "\nDeleting deck...\n\n\n";
	delete [] cards;
}

void Deck::shuffle_deck() {
	string str;
	int num, card1, card2;

	srand(time(NULL));

	for (int i = 0; i < 3000; i++) {
		card1 = rand() % 52;
		card2 = rand() % 52;

		str = cards[card1].getSuit();
		num = cards[card1].getRank();

		cards[card1].setSuit(cards[card2].getSuit());
    cards[card1].setRank(cards[card2].getRank());

		cards[card2].setSuit(str);
    cards[card2].setRank(num);
	}
}

void Deck::print_deck() {
	for (int i = 0; i < 52; i++) {
		cout << cards[i].getRank() << " of " << cards[i].getSuit() << "\n";
	}
}