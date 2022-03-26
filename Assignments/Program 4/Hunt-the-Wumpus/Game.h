#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <vector>
#include "Event.h"
#include "Wumpus.h"
#include "Bats.h"
#include "Pit.h"
#include "Gold.h"
#include "Room.h"
#include "AI.h"
using namespace std;

class Game {
	vector< vector<Room> > game_map;
	vector< vector<AI> > ai;
	int player_position[2];
	int rope_position[2];
	int arrow_position[2];
	int rows, columns;
  int num_of_arrows;
	bool debug_mode;
	bool player_has_gold;
	bool player_is_alive;
	bool wumpus_killed;

	public:
		Game();									// default constructor
		Game(int, string);			// parameterized constructor

		// setter (mutator) function
		void set_player_position();

		// getter (accessor) function
		int get_int(string);
		int get_player_row();
		int get_player_column();
		int get_map_size();
		void get_percepts();
		char get_directions();
		
		void print_game_stats();
		void shuffle_coordinates();
		void create_board(int);
		void print_board();
		void fill_wumpus_event();
		void fill_bat_event();
		void fill_pit_event();
		void fill_gold_event();
		void move_to_random_room();
		bool arrow_is_in_bounds(int, int);
		void fire_arrows();
		void shift_wumpus();
		void player_action();
		void interact_room();
		bool end_game();
		void play_game();

		~Game();
};

#endif
