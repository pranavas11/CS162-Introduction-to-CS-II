#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include "spellbook_catalog.h"
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
    if (prompt[i] > 47 && prompt[i] <= 57) {               // checks if numbers are between 0-9
      num = num * 10 + (int(prompt[i] - 48));              // num = 0 * 10 + (integer value of character - 48)) to return num
    } else {
      return -1;
    }
  }
  return num;
}

/****************************************************
* ** Function: print_options()
* ** Description: prints catalog of information
* ** Parameters: none
* ** Pre-conditions: asks user for a choice of input
* ** Post-conditions: displays main menu
****************************************************/
void print_options() {
  cout << "\nWhich option would you like to choose?\n";
  cout << "Sort spellbooks by number of pages (Press 1)\n";
  cout << "Group spells by their effect (Press 2)\n";
  cout << "Sort spellbooks by average success rate (Press 3)\n";
  cout << "Quit (Press 4)\n";
  cout << "Please enter an option: ";
}

/****************************************************
* ** Function: user_input_choice()
* ** Description: asks user for a choice of input
* ** Parameters: none
* ** Pre-conditions: verifies user input
* ** Post-conditions: returns user's choice of input
****************************************************/
int user_input_choice() {
	int option;
	string prompt;
	while (true) {
    cin >> prompt;
    option = get_int(prompt);                          // converts the given integer stored in a string type to integer type
    if (option == -1 || option < 1 || option > 4) {
      cout << "\nInvalid input! Please select a valid option: ";      // check for invalid input and reprompt user
      cin.clear();
      cin.ignore(256, '\n');
    } else {
      cin.clear();
      cin.ignore(256, '\n');
      break;
    }
  }
  return option;
}

/****************************************************
* ** Function: get_output_mode()
* ** Description: asks user for a choice of input
* ** Parameters: none
* ** Pre-conditions: verifies user input
* ** Post-conditions: returns user's choice of input
****************************************************/
int get_output_mode() {
	int option;
	string prompt;
	cout << "\nHow would you like the information displayed?\n";
	cout << "Print to screen (Press 1)\n";
	cout << "Print to file (Press 2)\n";
	cout << "Please select an option: ";
	while (true) {
    cin >> prompt;
    option = get_int(prompt);                        // converts the given integer stored in a string type to integer type
    if (option == -1 || option < 1 || option > 2) {
      cout << "\nInvalid input! Please select a valid option: ";        // check for invalid input and reprompt user
      cin.clear();
      cin.ignore(256, '\n');
    } else {
      cin.clear();
      cin.ignore(256, '\n');
      break;
    }
  }
  return option;
}

/*****************************************************************
* ** Function: get_file_name()
* ** Description: stores user input of file name
* ** Parameters: string* file
* ** Pre-conditions: takes string* file
* ** Post-conditions: returns user's choice of input for file name
******************************************************************/
void get_file_name(string* file) {
	cout << "\nPlease enter a file name: ";
	cin >> *file;
}

/******************************************************
* ** Function: create_spellbooks()
* ** Description: creates an array of spellbooks
* ** Parameters: int n
* ** Pre-conditions: takes int n
* ** Post-conditions: returns a new array of spellbooks
*******************************************************/
spellbook* create_spellbooks(int n) {
  spellbook* arr = new spellbook[n];            // allocates memory for spellbook array
  return arr;                                   // returns spellbook pointer array
}

/***************************************************
* ** Function: create_spells()
* ** Description: creates an array of spellbooks
* ** Parameters: int n
* ** Pre-conditions: takes int n
* ** Post-conditions: returns a new array of spells
***************************************************/
spell* create_spells(int n) {
  spell* arr = new spell[n];                    // allocates memory for spell array
  return arr;                                    // returns pointer to spell array
}

/********************************************************************************************
* ** Function: get_spell_data()
* ** Description: retrieves data of spells from text file
* ** Parameters: spell* s, int n, ifstream &f
* ** Pre-conditions: takes spell* s, int n, ifstream &f
* ** Post-conditions: fills spell struct with information that is read in from spellbooks.txt
*********************************************************************************************/
void get_spell_data(spell* s, int n, ifstream &f) {          // populates spell array with information from file
  for (int i = 0; i < n; i++) {           // read in the name, success_rate, and effect for the total number of spells in the text file
    f >> s[i].name;
    f >> s[i].success_rate;
    f >> s[i].effect;
  }
}

/****************************************************************
* ** Function: spells_avg_success_rate()
* ** Description: calculates the average success rate of spells
* ** Parameters: spell* sb, int n
* ** Pre-conditions: takes spell* sb, int n
* ** Post-conditions: returns average success rate of each spell
****************************************************************/
float spells_avg_success_rate(spell* sb, int n) {
  float sum = 0.0;
  for (int i = 0; i < n; i++) {
    sum += sb[i].success_rate;
  }
  return ((float)sum / (float)n);                  // calculates the average success rate of a spell array
}

/********************************************************************************
* ** Function: get_spellbook_data()
* ** Description: fills spellbook struct with info read from spellbooks.txt file
* ** Parameters: spellbook* sb, int n, ifstream& f
* ** Pre-conditions: takes spellbook* sb, int n, ifstream& f
* ** Post-conditions: returns all spellbook data read from spellbooks.txt
*********************************************************************************/
void get_spellbook_data(spellbook* sb, int n, ifstream& f) {                // populates spellbook array with values from file
  for (int i =  0; i < n; i++) {      // read in the title, author, num_pages, edition, and num_spells
    f >> sb[i].title;
    f >> sb[i].author;
    f >> sb[i].num_pages;
    f >> sb[i].edition;
    f >> sb[i].num_spells;

    sb[i].s = create_spells(sb[i].num_spells);              // creates spells for the number of spells in the text file
    get_spell_data(sb[i].s, sb[i].num_spells, f);           // gets each spells data for total num_spells read in from spellbooks.txt
    sb[i].avg_success_rate = spells_avg_success_rate(sb[i].s, sb[i].num_spells);      // calculates average success rate for all spells in a spellbook
  }
}

/************************************************************************
* ** Function: sort_by_numOfPages()
* ** Description: sorts spellbooks in ascending order by number of pages
* ** Parameters: spellbook* sb, int n
* ** Pre-conditions: takes spellbook* sb, int n
* ** Post-conditions: returns spellbook names sorted by number of pages
************************************************************************/
void sort_by_numOfPages(spellbook* sb, int n) {
	sort(sb, sb+n, [](spellbook a, spellbook b) {              // Method 1 Sort - Uses built-in sort() functionality
		return a.num_pages < b.num_pages;
	});
	
	/*spellbook temp;                                          // Method 2 Sort - Sorting by swapping values (a.k.a bubble sort)
	for (int i = 0; i < n-1; i++) {             // Source: https://www.geeksforgeeks.org/bubble-sort/
		for (int j = 0; j < n-i-1; j++) {
			if (sb[j].num_pages > sb[j+1].num_pages) {
        temp = sb[j];
        sb[j] = sb[j+1];
        sb[j+1] = temp;
      }
		}
	}*/
}

/**************************************************************************************************************
* ** Function: sort_by_effect()
* ** Description: sorts spellbooks by their effect in this order: bubble, memory_loss, fire, poison, and death
* ** Parameters: spellbook* sb, int num, string s
* ** Pre-conditions: takes spellbook* sb, int num, string s
* ** Post-conditions: returns spell names sorted by their effect
**************************************************************************************************************/
void sort_by_effect(spellbook* sb, int num, string s) {
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < sb[i].num_spells; j++) {            // loops through each spell in each spellbook
			if (!sb[i].s[j].effect.compare(s)) {                  // compares all spells in all spellbooks
				cout << sb[i].s[j].effect << " " << sb[i].s[j].name << "\n";     // output spells in correct order by effect followed by spell names
			}
		}
	}
}

/*************************************************************************************
* ** Function: sort_by_avg_success_rate()
* ** Description: sorts spellbooks in descending order by their average success rates
* ** Parameters: spellbook* sb, int n
* ** Pre-conditions: takes spellbook* sb, int n
* ** Post-conditions: returns spellbook names sorted by their average success rates
*************************************************************************************/
void sort_by_avg_success_rate(spellbook* sb, int n) {
	//source: https://www.includehelp.com/cpp-programs/sort-an-array-in-descending-order.aspx
  spellbook temp;
	for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {                    // loops through each success rate of spells in each pair of spellbooks
      if (sb[i].avg_success_rate < sb[j].avg_success_rate) {      // compares spells
        temp = sb[i];
        sb[i] = sb[j];
        sb[j] = temp;                  // sorts spells by swapping in descending order
      }
    }
  }
}

/******************************************************************
* ** Function: print_pages()
* ** Description: prints sorted pages to the screen
* ** Parameters: spellbook* sb, int num
* ** Pre-conditions: takes spellbook* sb, int num
* ** Post-conditions: outputs book title and page number to screen
******************************************************************/
void print_pages(spellbook* sb, int num) {
	sort_by_numOfPages(sb, num);
	cout << "\n";
	for (int i = 0; i < num; i++) {                    // loops through total number of spellbooks
		cout << i+1 << ") " << sb[i].title << " " << sb[i].num_pages << "\n";        // prints title and num_pages
	}
	cout << "\n";
}

/*************************************************************************
* ** Function: print_effects()
* ** Description: prints sorted spell effects to the screen
* ** Parameters: spellbook* sb, int num
* ** Pre-conditions: takes spellbook* sb, int num
* ** Post-conditions: outputs each record of spell effects to the console
*************************************************************************/
void print_effects(spellbook* sb, int num) {            // prints spell effects followed by spell title
	cout << "\n";
	sort_by_effect(sb, num, "bubble");
	sort_by_effect(sb, num, "memory_loss");
	sort_by_effect(sb, num, "fire");
	sort_by_effect(sb, num, "poison");
	sort_by_effect(sb, num, "death");
	cout << "\n";
}

/*******************************************************************
* ** Function: print_rates()
* ** Description: prints sorted average success rates to the screen
* ** Parameters: spellbook* sb, int num
* ** Pre-conditions: takes spellbook* sb, int num
* ** Post-conditions: outputs success rates to the console
*******************************************************************/
void print_rates(spellbook* sb, int num) {
	sort_by_avg_success_rate(sb, num);
	cout << "\n";
	for (int i = 0; i < num; i++) {                    // loops through total number of spellbooks
		cout << i+1 << ") " << sb[i].title << " " << sb[i].avg_success_rate << "\n";        // prints title followed by avg_success_rate
	}
	cout << "\n";
}

/**************************************************************************
* ** Function: write_spell_effects_to_file()
* ** Description: writes sorted spell effects to file
* ** Parameters: spellbook* sb, int num, string s, fstream& file
* ** Pre-conditions: takes spellbook* sb, int num, string s, fstream& file
* ** Post-conditions: outputs sorted spell effects to file
**************************************************************************/
void write_spell_effects_to_file(spellbook* sb, int num, string s, fstream& file) {
	for (int i = 0; i < num; i++) {                           // loops through all spellbooks
		for (int j = 0; j < sb[i].num_spells; j++) {            // loops through all spells in array
			if (!sb[i].s[j].effect.compare(s)) {                  // if type matches, print to file
				file << sb[i].s[j].effect << " " << sb[i].s[j].name << "\n";
			}
		}
	}
}

/*****************************************************************
* ** Function: pages_to_file()
* ** Description: writes sorted pages to file
* ** Parameters: spellbook* sb, int num, fstream& file
* ** Pre-conditions: takes spellbook* sb, int num, fstream& file
* ** Post-conditions: outputs sorted total pages and title to file
******************************************************************/
void pages_to_file(spellbook* sb, int num, fstream& file) {
	sort_by_numOfPages(sb, num);
	for (int i = 0; i < num; i++) {                    // loops through total number of spellbooks
		file << sb[i].title << " " << sb[i].num_pages << "\n";          // prints title and num_pages
	}
	file << "\n\n\n";
  cout << "\nAppended requested information to file.\n";
}

/******************************************************************
* ** Function: spell_effects_to_file()
* ** Description: writes sorted spell effects to file
* ** Parameters: spellbook* sb, int num, fstream& file
* ** Pre-conditions: takes spellbook* sb, int num, fstream& file
* ** Post-conditions: outputs spell effects and spell title to file
*******************************************************************/
void spell_effects_to_file(spellbook* sb, int num, fstream& file) {
	write_spell_effects_to_file(sb, num, "bubble", file);
	write_spell_effects_to_file(sb, num, "memory_loss", file);
	write_spell_effects_to_file(sb, num, "fire", file);
	write_spell_effects_to_file(sb, num, "poison", file);
	write_spell_effects_to_file(sb, num, "death", file);
	file << "\n\n\n";
  cout << "\nAppended requested information to file.\n";
}

/*******************************************************************
* ** Function: avg_success_rates_to_file()
* ** Description: writes sorted average success rates to file
* ** Parameters: spellbook* sb, int num, fstream& file
* ** Pre-conditions: takes spellbook* sb, int num, fstream& file
* ** Post-conditions: outputs success rates and spell titles to file
********************************************************************/
void avg_success_rates_to_file(spellbook* sb, int num, fstream& file) {
	sort_by_avg_success_rate(sb, num);
	for (int i = 0; i < num; i++) {
		file << sb[i].title << " " << sb[i].avg_success_rate << "\n";
	}
	file << "\n\n\n";
  cout << "\nAppended requested information to file.\n";
}

/*************************************************************************************************
* ** Function: write_to_file()
* ** Description: determines if fstream will be writing to a new file or appending to an existing
* ** Parameters: string s, fstream& file
* ** Pre-conditions: takes string s, fstream& file
* ** Post-conditions: decides whether to output data or append data
**************************************************************************************************/
void write_to_file(string s, fstream& file) {
	file.open(s.c_str(), ios::in);                  // try to open file (note: s.c_str() converts each each charater in a string to C-Style strings)
	if (file.fail()) {                              // if file doesn't exist
		file.close();                                 // close failed filestream
		file.open(s.c_str(), ios::out);               // reopen and set to output mode with given filename
	} else {                                        // if file exists
		file.close();                                 // close filestream
		file.open(s.c_str(), ios::out|ios::app);      // set to append mode
	}
}

/*********************************************************************************************
* ** Function: output_data()
* ** Description: captures user input to determine the program's mode of output
* ** Parameters: spellbook* sb, int num, int option, int output_mode
* ** Pre-conditions: takes spellbook* sb, int num, int option, int output_mode
* ** Post-conditions: decides whether to output data to the console or append data into a file
**********************************************************************************************/
void output_data(spellbook* sb, int num, int option, int output_mode) {
	if (output_mode == 1) {                              // if user chooses to print to screen
		if (option == 1) print_pages(sb, num);
		if (option == 2) print_effects(sb, num);
		if (option == 3) print_rates(sb, num);
   
	} else {                                             // if user chooses to print to file
		fstream file;
		string output_file;

		get_file_name(&output_file);                        // get user's choice of file name
		write_to_file(output_file, file);                   // open file and set it to append mode

		if (option == 1) pages_to_file(sb, num, file);
		if (option == 2) spell_effects_to_file(sb, num, file);
		if (option == 3) avg_success_rates_to_file(sb, num, file);

		file.close();
	}
}

/************************************************************************************************
* ** Function: is_valid_file()
* ** Description: verfies correct number of CLI arguments and file name
* ** Parameters: int n, char* arg1, ifstream& file
* ** Pre-conditions: takes int n, char* arg1, ifstream& file
* ** Post-conditions: returns true/false as to validate the number of CLI arguments and file name
*************************************************************************************************/
bool is_valid_file(int n, char* arg1, ifstream& file) {
  if (n != 2) {
    cout << "\n\n\nERROR: exactly two arguments were not specified.\n\n\nPlease enter the executable file and text file as arguments.\n\n\nExiting now...\n\n\n";
    file.close();
    return false;
  }

  file.open(arg1, ios::in);          // open the file (note - ios::in opens file for reading)
  if (file.fail()) {
    cout << "\n\n\nERROR: specified spellbook text file does not exist.\n\n\nPlease enter a valid text file name.\n\n\nExiting now...\n\n\n";
    file.close();
    return false;
  }
  file.close();

  return true;
}

/**************************************************************************************
* ** Function: delete_spellbook_data()
* ** Description: de-allocates memory for the spellbook array
* ** Parameters: spellbook* sb, int n
* ** Pre-conditions: takes spellbook* sb, int n
* ** Post-conditions: frees up memory usage (heap memory) of spellbook and spell arrays
***************************************************************************************/
void delete_spellbook_data(spellbook* sb, int n) {
  for (int i = 0; i < n; i++) {
    delete[] sb[i].s;                    // loops through spellbooks array and deletes spell array
  }
  delete[] sb;                           // finally, delete the entire spellbook array itself
}