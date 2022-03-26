#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Zoo.h"
using namespace std;

int main() {
	srand(time(NULL));      // seeds the random number generator

	cout << "\n\n\n\033[0;34m\e[1mWelcome to the Game of Zoo Tycoon!\n\n\n";
	
  Zoo zoo_tycoon;                  // instance of Zoo class (calls Zoo default constructor)
	zoo_tycoon.play_zoo_tycoon();    // the Zoo instance calls the play_zoo_tycoon() method/function from Zoo class

	return 0;
}