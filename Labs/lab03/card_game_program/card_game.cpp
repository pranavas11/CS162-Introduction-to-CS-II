#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <ctime>
#include "deck.h"
using namespace std;

int main() {
  Deck myDeck;

	myDeck.print_deck();
	myDeck.shuffle_deck();
	myDeck.print_deck();

	return 0;
}