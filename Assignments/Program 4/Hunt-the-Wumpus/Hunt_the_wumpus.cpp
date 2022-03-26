/*****************************************************************************************
** Program: Hunt_the_wumpus.cpp
** Author: Pranav Prabhu
** Date: 05/11/2021
** Description: this program plays the game of Hunt the Wumpus
** Input: player's direction to navigate the cave or player's direction to shoot an arrow
** Output: winning or losing condition of the player at the end of the game
*****************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <vector>
#include "Game.h"
using namespace std;

/***************************************************************************************************************
 * ** Function: get_int()
 * ** Description: takes a prompt from the user as a string literal and checks if the inputs is a valid integer
 * ** Parameters: string prompt
 * ** Pre-conditions: takes a string prompt
 * ** Post-conditions: returns the provided integer
 **************************************************************************************************************/
int get_int(string prompt) {
  int num = 0;
  for (unsigned int i = 0; i < prompt.length(); i++) {
    if (prompt[i] > 47 && prompt[i] <= 57) {          // checks if numbers are between 0-9
      num = num * 10 + (int(prompt[i] - 48));          // num = (0 * 10) + (integer value of character - 48)) to return num
    } else {
      return -1;
    }
  }
  return num;
}

// this method validates the number of CLI arguments
bool validate_args(int argc) {
  if (argc == 3) {
    return true;
  } else if (argc > 3) {
    cout << "\nYou entered too many arguments.\n";
  } else {
    cout << "\nYou entered too few arguments.\n";
  }
  return false;
}

int main(int argc, char** argv) {
	srand(time(NULL));

	int board_dimension;
	string debug;

	if (validate_args(argc)) {
		string dimension(argv[1]);
		board_dimension = atoi(argv[1]);
		while (board_dimension > 50 || board_dimension < 4/* || to_string(atoi(dimension.c_str())) != dimension*/) {
      cout << "\nInvalid dimension! Please enter a valid dimension between 4 and 50: ";
      cin >> dimension;
      board_dimension = atoi(dimension.c_str());
    }
		string debug_mode(argv[2]);
		while (debug_mode != "true" && debug_mode != "false") {
			cout << "\nERROR - please enter either true or false for setting the debug mode: ";
			cin >> debug_mode;
		}
		debug = debug_mode;
	} else {
		int user_choice;
		string dim;
		cout << "\nEnter the board dimension: ";
    
		while (true) {
			cin >> dim;
			user_choice = get_int(dim);
			if (user_choice == -1 || user_choice < 4 || user_choice >= 51) {
				cout << "\nInvalid input! Please select a valid dimension between 4 and 50: ";
    	} else {
      	break;
    	}
		}
		board_dimension = user_choice;

		if (validate_args(argc)) string debug_mode(argv[2]);
		else {
			debug = "f";
			while (debug != "true" && debug != "false") {
				cout << "\nERROR - please enter either true or false for setting the debug mode: ";
				cin >> debug;
			}
		}
	}
	
	Game hunt_the_wumpus = Game(board_dimension, debug);
	hunt_the_wumpus.play_game();

	string play_again;
	while (true) {
		cout << "\n\033[1;31mWould you like to play again (y/n)? ";
		cin >> play_again;
		if (play_again == "Yes" || play_again == "yes" || play_again == "Y" || play_again == "y") {
			Game new_game = Game(board_dimension, debug);
			new_game.play_game();
		} else {
			cout << "\n\n\n\033[1;33mThanks for playing Hunt The Wumpus! Sorry to see you leave! Please play again!\n\n\n";
			break;
		}
	}

	return 0;
}
