#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <ctime>
#include "card.h"
#include "deck.h"
using namespace std;

Card::Card() {
	suit = "suit"; rank = 0;
}

Card::Card(string s, int r) {
  setSuit(s);
  setRank(r);
}

void Card::setSuit(string s) { suit = s; }

void Card::setRank(int r) { rank = r; }

string Card::getSuit() { return suit; }

int Card::getRank() { return rank; }

/*std::string Card::getrank() {
  switch (rank) {
    case 0: return "ace";
    case 1: return "one";
    case 2: return "two";
    case 3: return "four";
    case 4: return "five";
    case 5: return "six";
    case 6: return "seven";
    case 7: return "eight";
    case 8: return "nine";
    case 9: return "ten";
    case 10: return "jack";
    case 11: return "queen";
    case 12: return "king";
  }
}

std::string Card::getsuit() {
  switch (suit) {
    case 0: return "hearts";
    case 1: return "clubs";
    case 2: return "diamonds";
    case 3: return "spades";
  }
}*/