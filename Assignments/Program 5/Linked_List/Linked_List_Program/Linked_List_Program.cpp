/***************************************************************************************************
** Program: Linked_List_Program.cpp
** Author: Pranav Prabhu
** Date: 05/25/2021
** Description: this program plays a simple game using linked lists
** Input: list of integers and the order in which the player wants the numbers to be sorted
** Output: numbers sorted in the chosen order along with prime count and primes numbers in the list
***************************************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include "Linked_List.h"
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
	bool flag = false;

	for (unsigned int i = 0; i < prompt.length(); i++) {
    if (prompt[i] == '-') {	// deals with negative numbers
      flag = true;
    } else if (prompt[i] < 48 || prompt[i] > 57) {
      return -1;			// if no valid integer is detected
    } else {
      num = num * 10 + (int(prompt[i] - 48));	// num = (0 * 10) + (integer value of character - 48)) to return num
    }
  }
	
  if (flag == true) {
    return -1 * num;
  }
  
  return num;
}

/***************************************************************************************************************
 * ** Function: play_game()
 * ** Description: sets up the stage to play the game
 * ** Parameters: none
 * ** Pre-conditions: asks user for numbers and the order they would like to sort
 * ** Post-conditions: plays the game
 **************************************************************************************************************/
void play_game() {
	Linked_List linked_list = Linked_List();
	
	string user_num;
	int user_num_choice;
	string input = "yes";
	
	do {
		cout << "\n\n\nPlease enter a number: ";
		cin >> user_num;
		user_num_choice = get_int(user_num);

		while (user_num_choice == -1) {
    	cout << "\nInvalid input! Please select a number between 1 and 25: ";
    	cin.clear();
    	cin.ignore(256,'\n');
    	cin >> user_num;
    	user_num_choice = get_int(user_num);
  	}
		
		linked_list.push_back(user_num_choice);
		//linked_list.print();
		//linked_list.push_front(user_num_choice);
		//linked_list.print();

		cout << "\nDo you want another num (y or n)? ";
		while (true) {
			cin >> input;
			if (input != "Yes" && input != "yes" && input != "Y" && input != "y" && input != "No" && input != "no" && input != "n") {
				cout << "\nInvalid input! Please select a valid option: ";
			} else break;
		}
	} while (input != "No" && input != "no" && input != "N" && input != "n");

	do {
		cout << "\n\n\nSort ascending or descending (a or d)? ";
		cin >> input;
	} while (input != "A" && input != "a" && input != "D" && input != "d");

	if (input == "A" || input == "a") linked_list.sort_ascending();
	else linked_list.sort_descending();

	cout << "\n\n\nYour sorted linked list is: ";
	linked_list.print();

	if (linked_list.count_primes() == 1) {
		cout << "\n\n\nThe linked list has " << linked_list.count_primes() << " prime number.\n";
	} else {
		cout << "\n\n\nThe linked list has " << linked_list.count_primes() << " prime numbers.\n";
	}
	
	cout << "\nList of Prime Number(s) from Linked List: ";
	linked_list.print_primes();
}

int main() {
	play_game();

	while (true) {
		string again;
		cout << "Do you want to play again (y/n)? ";
		cin >> again;
		if (again == "Yes" || again == "yes" || again == "Y" || again == "y") {
			play_game();
		} else {
			cout << "\nThanks for playing! Please play again!\n\n\n";
			break;
		}
	}

	return 0;
}