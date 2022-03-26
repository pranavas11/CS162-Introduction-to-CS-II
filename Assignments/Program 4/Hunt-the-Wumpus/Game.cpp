#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <vector>
#include "Game.h"
using namespace std;

/******************************************************************************
 * ** Constructor: Game()
 * ** Description: sets initial default values for Game class member variables
 * ** Parameters: none
 * ** Pre-conditions: sets player, rope, and arrow positions to (0, 0)
 * ** Post-conditions: sets default values for variables
 *****************************************************************************/
Game::Game() {
	player_position[0] = 0;          // player row
	player_position[1] = 0;          // player column
	rope_position[0] = 0;          // rope row
	rope_position[1] = 0;          // rope column
	arrow_position[0] = 0;          // arrow row
	arrow_position[1] = 0;          // arrow columns
	this->debug_mode = false;
	this->num_of_arrows = 3;
	this->wumpus_killed = false;
}

/***************************************************************************************
 * ** Constructor: Game()
 * ** Description: sets default values, constructs the board, and fills it with events
 * ** Parameters: int arg1, string arg2
 * ** Pre-conditions: sets values for rows, columns, postions, etc.
 * ** Post-conditions: creates a 2D board filled with game events at random coordinates
 **************************************************************************************/
Game::Game(int arg1, string arg2) {
	int dimension = arg1;
	rows = columns = dimension;      // set inital total rows and columns equal to board dimension

	player_position[0] = player_position[1] = 0;      // player row = player column = (0, 0)
	rope_position[0] = rope_position[1] = 0;          // rope row = rope column = (0, 0)
	arrow_position[0] = arrow_position[1] = 0;          // arrow row = arrow column = (0, 0)

	num_of_arrows = 3;
	this->player_is_alive = true;
	this->player_has_gold = false;
	this->wumpus_killed = false;
	this->debug_mode = false;

	string str = "true";
	if (str.compare(arg2) == 0) this->debug_mode = true;      // if argv[2] is true, debug mode is set to true
	
	//game_map.reserve(dimension);
	//for (int i = 0; i < dimension; i++) game_map[i].reserve(dimension);
	create_board(dimension);
	fill_wumpus_event();
	fill_bat_event();
	fill_bat_event();
	fill_pit_event();
	fill_pit_event();
	fill_gold_event();
	set_player_position();
	//game_map.resize(dimension, dimension vector<Room>(dimension, Room()));
}

// prints game conditions - navigation tips, remaining arrows, and boolean value of if player has gold
void Game::print_game_stats() {
  cout << "\n\n\n\033[1;32m*******************************************************************************************\n";
	cout << "*\t\t\t\t\t\t\t\t\t\t\t  *\n* Navigation: W (North), A (West), S (South), or D (East)\t\t\t\t  *\n*";
  cout << "\t\t\t\t\t\t\t\t\t\t\t  *\n*******************************************************************************************\n*";
	cout << "\t\t\t\t\t\t\t\t\t\t\t  *\n* Shoot Arrows: W (North), A (West), S (South), or D (East)\t\t\t\t  *\n*";
	cout << "\t\t\t\t\t\t\t\t\t\t\t  *\n* Tip: enter space followed by a character to shoot arrows in the appropriate direction!  *\n*";
  cout << "\t\t\t\t\t\t\t\t\t\t\t  *\n*******************************************************************************************\n*";
  cout << "\t\t\t\t\t\t\t\t\t\t\t  *\n* Remaining Arrows: " << num_of_arrows << "\t|\tWumpus killed: " << boolalpha << wumpus_killed;
  cout << "\t|\tGold collected: " << boolalpha << player_has_gold << "\t  *\n*";
  cout << "\t\t\t\t\t\t\t\t\t\t\t  *\n*******************************************************************************************\n\n\n\033[1;34m";
}

/***************************************************************************************************************
 * ** Function: get_int()
 * ** Description: takes a prompt from the user as a string literal and checks if the inputs is a valid integer
 * ** Parameters: string prompt
 * ** Pre-conditions: takes a string prompt
 * ** Post-conditions: returns the provided integer
 **************************************************************************************************************/
int Game::get_int(string prompt) {
  int num = 0;
  for (unsigned int i = 0; i < prompt.length(); i++) {
    if (prompt[i] > 47 && prompt[i] <= 57) {      // checks if numbers are between 0-9
      num = num * 10 + (int(prompt[i] - 48));      // num = (0 * 10) + (integer value of character - 48)) to return num
    } else {
      return -1;
    }
  }
  return num;
}

// shuffles grid to place player, rope, and events at random locations
void Game::shuffle_coordinates() {
	rows = rand() % game_map.size();
	columns = rand() % game_map.size();
}

// this method returns the player's row index as he navigates the grid
int Game::get_player_row() {
	int player_row = player_position[0];
	return player_row;
}

// this method returns the player's columns index as he navigates the grid
int Game::get_player_column() {
	int player_column = player_position[1];
	return player_column;
}

// this method returns the size of the entire board
int Game::get_map_size() {
	int map_size = game_map.size();
	return map_size;
}

/**********************************************************************************************************
 * ** Function: get_percepts()
 * ** Description: retrieves percept messages in all directions (NEWS) from the player (except diagonally)
 * ** Parameters: none
 * ** Pre-conditions: determines the player's row and column positions on the grid
 * ** Post-conditions: prints percept messages (a.k.a warnings/information) to the player as he navigates
 *********************************************************************************************************/
void Game::get_percepts() {
	int player_row = get_player_row();
	int player_column = get_player_column();
	int map_size = get_map_size();

	if (player_row != 0) game_map[player_row-1][player_column].percept_room();      // displays any percepts from north
	if (player_row != map_size-1) game_map[player_row+1][player_column].percept_room();      // displays any percepts from south
	if (player_column != 0) game_map[player_row][player_column-1].percept_room();          // displays any percepts from west
	if (player_column != map_size-1) game_map[player_row][player_column+1].percept_room();      // displays any percepts from east
}

// creates a 2D grid with rows and columns (size represented board dimension - argv[1])
void Game::create_board(int size) {
	for (int i = 0; i < size; i++) {
		game_map.push_back(vector<Room>());      // pushes a vector of rooms into the grid of rows
		for (int j = 0; j < size; j++) {
			game_map[i].push_back(Room());          // pushes a vector of rooms into the 2d grid of rows & columns
		}
	}
}

/**********************************************************************************************************
 * ** Function: print_board()
 * ** Description: prints the board with rows and columns filled with events and player/rope positions
 * ** Parameters: none
 * ** Pre-conditions: retrieves the size of the 2D grid
 * ** Post-conditions: prints the entire 2D board
 *********************************************************************************************************/
void Game::print_board() {
	int dimension = game_map.size();
  cout << "\n";
	for (int i = 0; i < dimension; i++) {                  // loops through rows
		for (int j = 0; j < dimension; j++) cout << "\033[1;34m+---";
		cout << "+\n";
		for (int n = 1; n < dimension; n++) {
			for (int k = 0; k < dimension; k++) {      // loops through columns
				cout << "| ";
        // if i and k equal shuffled player row and column in board, print player's position
				if ((i == player_position[0]) && (k == player_position[1]) && (n == 3)) cout << "\033[1;92m*\033[1;34m";
        // if i and k equal shuffled player row and column in board and debug = true, print player & rope's position (both are in same positions)
				else if ((i == rope_position[0]) && (k == rope_position[1]) && (debug_mode == true) && (n == 2)) cout << "\033[1;92mR\033[1;34m";
				else if ((debug_mode == true) && (n==1)) cout << game_map[i][k].get_event();      // prints events on board only if debug mode is true
				else cout << " ";
				cout << " ";
			}
			cout << "|\n";
		}
	}
	cout << "+";
	for (int i = 0; i < dimension; i++) cout << "---+";
	cout << "\n";
}

// this method fills a wumpus event at a random empty room on the grid
void Game::fill_wumpus_event() {
	Event* wumpus = new Wumpus;          // new wumpus event (created on the heap)
	shuffle_coordinates();
	while (!game_map[rows][columns].is_empty()) {      // shuffle grid until a wumpus can be placed in a random empty room
		shuffle_coordinates();
	}
	game_map[rows][columns].set_event(wumpus);      // call setter method from Room class to set the wumpus event
}

// this method fills a bat event at a random empty room on the grid
void Game::fill_bat_event() {
	Event* bats = new Bats;              // new bat event (created on the heap)
	shuffle_coordinates();
	while (!game_map[rows][columns].is_empty()) {      // shuffle grid until a bat can be placed in a random empty room
		shuffle_coordinates();
	}
	game_map[rows][columns].set_event(bats);          // call setter method from Room class to set the bat event
}

// this method fills a pit event at a random empty room on the grid
void Game::fill_pit_event() {
	Event* pits = new Pit;              // new pit event (created on the heap)
	shuffle_coordinates();
	while (!game_map[rows][columns].is_empty()) {      // shuffle grid until a pit can be placed in a random empty room
		shuffle_coordinates();
	}
	game_map[rows][columns].set_event(pits);          // call setter method from Room class to set the pit event
}

// this method fills a gold event at a random empty room on the grid
void Game::fill_gold_event() {
	Event* gold = new Gold;              // new gold event (created on the heap)
	shuffle_coordinates();
	while (!game_map[rows][columns].is_empty()) {      // shuffle grid until gold event can be placed in a random empty room
		shuffle_coordinates();
	}
	game_map[rows][columns].set_event(gold);      // call setter method from Room class to set the gold event
}

// this method sets the initial player position on the board
void Game::set_player_position() {
	shuffle_coordinates();
	while (!game_map[rows][columns].is_empty()) {      // shuffle grid until the player can be placed in a random empty room
		shuffle_coordinates();
	}
	
	player_position[0] = rope_position[0] = rows;          // set player & rope row to shuffled row
	player_position[1] = rope_position[1] = columns;      // set player & rope column to shuffled column
}

// this method allows the bat to place to player in a random empty room (if player enters a bat room)
void Game::move_to_random_room() {
	shuffle_coordinates();
	while (!game_map[rows][columns].is_empty()) {      // shuffle grid until the player can be placed in a random empty room
		shuffle_coordinates();
	}
	player_position[0] = rows;          // set player row to shuffled row
	player_position[1] = columns;      // set player column to shuffled columns
}

// this method asks the user a valid navigation direction
char Game::get_directions() {
	char input;
	do {
		cin.clear();
		cout << "\nEnter the direction you would like to travel: ";
		cin >> input;
	} while (input != 'W' && input != 'w' && input != 'A' && input != 'a' && input != 'S' && input != 's' && input != 'D' && input != 'd');
	return input;
}

// this method checks to make sure the fired arrow doesn't go out of bounds (i.e., outside of grid)
bool Game::arrow_is_in_bounds(int row, int column) {
	int game_map_size = game_map.size();
	if (row < 0 || row >= game_map_size) return false;
	if (column < 0 || column >= game_map_size) return false;
	return true;
}

/*************************************************************************************************************
 * ** Function: fire_arrows()
 * ** Description: shoots an arrow to kill the wumpus in the appropriate direction
 * ** Parameters: none
 * ** Pre-conditions: sets player's position on grid to arrow initial position and asks user firing direction
 * ** Post-conditions: prints the entire 2D board
 ************************************************************************************************************/
void Game::fire_arrows() {
	int row_direction, column_direction;
	arrow_position[0] = player_position[0];      // arrow initial row (for aiming) is set to player's current row
	arrow_position[1] = player_position[1];      // arrow initial column (for aiming) is set to player's current column

	string arrow_direction;
	cout << "\nWhich direction would you like to fire the arrow? ";

	while (true) {
		getline(cin, arrow_direction);
	  if (!(arrow_direction == " W" || arrow_direction == " w" || arrow_direction == " A" || arrow_direction == " a" || arrow_direction == " S" || arrow_direction == " s" || arrow_direction == " D" || arrow_direction == " d")) {
	    cout << "\nInvalid input! Please select a valid direction: ";
	  } else break;
	}

	if (arrow_direction == " W" || arrow_direction == " w") {          // if direction is north, decrement row and column remains the same
		row_direction = -1;
		column_direction = 0;
	} else if (arrow_direction == " A" || arrow_direction == " a") {      // if direction is west, row remains the same and decrement column
		row_direction = 0;
		column_direction = -1;
	} else if (arrow_direction == " S" || arrow_direction == " s") {      // if direction is south, increment row and column remains the same
		row_direction = 1;
		column_direction = 0;
	} else if (arrow_direction == " D" || arrow_direction == " d") {      // if direction is east, row remains the same and increment column
		row_direction = 0;
		column_direction = 1;
	}

	for (int i = 0; i < 3; i++) {      // the fired arrow flies through 3 rooms
		if (arrow_is_in_bounds(arrow_position[0]+row_direction, arrow_position[1]+column_direction)) {
			arrow_position[0] += row_direction;
			arrow_position[1] += column_direction;
			game_map[arrow_position[0]][arrow_position[1]].kill_wumpus(wumpus_killed);
			//cout << "\narrow_position[0]: " << arrow_position[0] << " arrow_position[1]: " << arrow_position[1] << endl;
			//cout << "wumpus killed: " << wumpus_killed << '\n';
		}
	}

	int probability = rand() % 4;
	if (!wumpus_killed && probability != 0) {      // if shot is missed, the probability of the wumpus moving to a new empty room is 75%
		cout << "\n\033[1;36mSorry, you missed your shot! The arrow has awoken the wumpus, which now moved to a different room!\n";
		shift_wumpus();
	}
	num_of_arrows -= 1;      // decrement arrow count after one is fired
}

/************************************************************************************************
 * ** Function: shift_wumpus()
 * ** Description: shifts the wumpus to a new random empty room if needed
 * ** Parameters: none
 * ** Pre-conditions: loops through rows and columns on the grid to locate wumpus' original spot
 * ** Post-conditions: prints the entire 2D board
 ***********************************************************************************************/
void Game::shift_wumpus() {
	int game_map_size = game_map.size();
	for (int i = 0; i < game_map_size; i++) {
		for (int j = 0; j < game_map_size; j++) {
			if (game_map[i][j].get_event() == "w") {
				game_map[i][j].delete_event();          // remove the old wumpus event from the old room after wumpus shifts
			}
		}
	}

	shuffle_coordinates();
	while (!game_map[rows][columns].is_empty() && rope_position[0] == rows && rope_position[1] == columns) {
		shuffle_coordinates();          // shuffle wumpus location while a new random empty room (not the rope room either) is found
	}
	//cout << "wumpus shuffled row: " << rows << " shuffled col: " << columns << '\n';
  
	Event* wumpus = new Wumpus();
	game_map[rows][columns].set_event(wumpus);      // call setter method from Room class to set the wumpus event
}

/********************************************************************************************
 * ** Function: player_action()
 * ** Description: retrieves user's choice to either navigate the grid or fire an arrow
 * ** Parameters: none
 * ** Pre-conditions: gets user's choice to travel or fire arrow
 * ** Post-conditions: the player either moves or fires an arrow in the appropriate direction
 ********************************************************************************************/
void Game::player_action() {
	int game_map_size = game_map.size();
	if (num_of_arrows > 0) {
		int user_choice;
		string option;

		cout << "\n\n\n\033[1;96m[1] Would you like to travel?\n[2] Would you like to fire an arrow?\n";
		cout << "\nPlease select an option: ";

		while (true) {
			cin >> option;
			user_choice = get_int(option);
			if (user_choice == -1 || user_choice < 1 || user_choice >= 3) {
				cout << "\nInvalid input! Please select a valid option: ";
      	cin.clear();
      	cin.ignore(256, '\n');
    	} else {
      	cin.clear();
      	cin.ignore(256, '\n');
      	break;
    	}
		}

		if (user_choice == 1) {          // if player wants to travel
			char user_direction = get_directions();
			if ((user_direction == 'W' || user_direction == 'w') && player_position[0] != 0) player_position[0] -= 1;      // north -> shift one row down
			else if ((user_direction == 'A' || user_direction == 'a') && player_position[1] != 0) player_position[1] -= 1;  // west -> shift one column down
			else if ((user_direction == 'S' || user_direction == 's') && player_position[0] != game_map_size-1) player_position[0] += 1;  // south -> one row up
			else if ((user_direction == 'D' || user_direction == 'd') && player_position[1] != game_map_size-1) player_position[1] += 1;  // east -> one column up
		} else fire_arrows();

	} else {          // if player wants to fire an arrow
		char user_direction = get_directions();
		if ((user_direction == 'W' || user_direction == 'w') && player_position[0] != 0) player_position[0] -= 1;      // north -> fire arrows down
		else if ((user_direction == 'A' || user_direction == 'a') && player_position[1] != 0) player_position[1] -= 1;  // west -> fire arrows left
		else if ((user_direction == 'S' || user_direction == 's') && player_position[0] != game_map_size-1) player_position[0] += 1;  // south -> fire arrows up
		else if ((user_direction == 'D' || user_direction == 'd') && player_position[1] != game_map_size-1) player_position[1] += 1;  // east -> fire arrows right
	}
}

/*********************************************************************************************
 * ** Function: interact_room()
 * ** Description: player interacts with a room filled with a random event
 * ** Parameters: none
 * ** Pre-conditions: gets room event at player's position and print encounter message
 * ** Post-conditions: the player enters a room with an event which can be postive or negative
 *********************************************************************************************/
void Game::interact_room() {
	string room_event = game_map[player_position[0]][player_position[1]].get_event();
	game_map[player_position[0]][player_position[1]].encounter_room();

	if (room_event == "w") player_is_alive = false;          // if wumpus room, player dies
	else if (room_event == "b") move_to_random_room();      // if bat room, player gets shifted to a random room
	else if (room_event == "p") player_is_alive = false;      // if pit room, player dies
	else if (room_event == "g") player_has_gold = true;      // if gold room, player collects all the gold
}

// this method verifies whether the game has come an end with player either winning or losing
bool Game::end_game() {
	if ((player_position[0] == rope_position[0] && player_position[1] == rope_position[1]) && (player_is_alive == true) && (player_has_gold == true)) {
		return true;                              // returns true if player successfully navigates back to rope with gold (winning condition)
	} else if (player_is_alive == false) {
		return true;          // returns true if player dies (losing condition)
	}
	return false;      // returns false as long as the player doesn't win or lose
}

/***********************************************************************************************************
 * ** Function: play_game()
 * ** Description: player plays the game until a winning or losing condition is reached
 * ** Parameters: none
 * ** Pre-conditions: prints the board filled with events, gets percepts, and player navigates/shoots arrow
 * ** Post-conditions: after game is over, determines if the player has won or lost the game
 ***********************************************************************************************************/
void Game::play_game() {
	print_game_stats();

	while (!end_game()) {
		print_board();
		get_percepts();
		player_action();
		interact_room();
		if (end_game()) {
			print_board();
			continue;
		}
		print_game_stats();
	}

	cout << "\n\n\n\033[1;94mGame Over!!!\n\n\n";
	if (player_is_alive == true && player_has_gold == true) {
		print_board();
		cout << "\n\033[1;92mGreat job! You got the gold! You won the game!\n\n\n";
	} else cout << "\n\033[1;95mSorry, you have lost the game! Please play again!\n\n\n";
}

// Game destructor which frees up all dynamically allocated memory from using vector
Game::~Game() {
	for (int i = 0; i < rows; i++) {
		game_map[i].clear();
	}
	game_map.clear();
	game_map.shrink_to_fit();
}