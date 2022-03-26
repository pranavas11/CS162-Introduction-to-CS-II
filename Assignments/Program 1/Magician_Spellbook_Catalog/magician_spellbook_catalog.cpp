/***************************************************************************************************************
** Program: magician_spellbook_catalog.cpp
** Author: Pranav Prabhu
** Date: 04/05/2021
** Description: This program searches spellsbooks and outputs sorted spellbook data to console/file.
** Input: executable file name, textfile name, option to sort, and output mode
** Output: Sorts spellbooks in the correct order and either prints data to screen or appends data to a text file
****************************************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include "spellbook_catalog.h"
using namespace std;

int main(int argc, char** argv) {
  ifstream fin;                        // ifstream - used for reading data from file
	int total_spellbooks, option = 0, output_mode = 0;
	spellbook* spellbook_arr;

	cout << "\n\n\nWelcome to the Magician Spellbook Catalog!\n\n";

	if (!is_valid_file(argc, argv[1], fin)) return 0;        // exit program if invalid number of CLI arguments or invalid file name

	fin.open(argv[1], ios::in);        // open text file in reading mode
	fin >> total_spellbooks;           // capture the total number of spellbooks at the top line in spellbooks.txt
	
	spellbook_arr = create_spellbooks(total_spellbooks);          // create spellbooks of the size of total numbe of spellbooks
	get_spellbook_data(spellbook_arr, total_spellbooks, fin);     // get all spellbook data from the text file
  
	fin.close();                // close file after retrieving all data from text file

	while (true) {
		print_options();
		option = user_input_choice();            // get user's choice of input for sorting spells/spellbooks

		if (option == 4) {
			cout << "\n\n\nExiting...\nThank you for using our Magician Spellbook Catalog!\nPlease come again!\n\n\n";
			break;
		} else {
			output_mode = get_output_mode();      // get user's choice of input for program execution
			output_data(spellbook_arr, total_spellbooks, option, output_mode);      // outputs data (either to screen or to file)
		}
	}

	delete_spellbook_data(spellbook_arr, total_spellbooks);            // de-allocates (free-up) memory after usage

  return 0;
}

// read more about file handling here: https://www.tutorialride.com/cpp/file-handling-in-c.htm#:~:text=File%20Handling%20in%20C%2B%2B%201%20Naming%20a%20file,Writing%20data%20into%20file%205%20Closing%20a%20file