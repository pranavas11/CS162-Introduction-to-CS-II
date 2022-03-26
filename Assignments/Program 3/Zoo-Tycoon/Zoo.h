#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Bear.h"
#include "Lemur.h"
#include "Tiger.h"
using namespace std;

class Zoo {
	private:
		string user_name;
		float bank_money;
		int time_advanced;
		float food_base_cost;
		float total_food_cost;
		float revenue;
		int monthly_event;

		Black_bear* black_bears;
		int num_of_bears;
		int num_of_bears_bought;

		Lemur* lemurs;
		int num_of_lemurs;
		int num_of_lemurs_bought;

		Tiger* tigers;
		int num_of_tigers;
		int num_of_tigers_bought;
	
	public:
		Zoo();					// default constructor

		// ostream operator overload functions
		ostream& bold_text_on(ostream& os);
		ostream& bold_text_off(ostream& os);

		// member functions
		void print_game_conditions();
		string get_player_name();
		int get_int(string prompt);

		int get_baby_bears();
		int get_baby_lemurs();
		int get_baby_tigers();
		int get_adolescent_bears();
		int get_adolescent_lemurs();
		int get_adolescent_tigers();
		int get_adult_bears();
		int get_adult_lemurs();
		int get_adult_tigers();
		void get_animal_ages();
		bool is_adult(int);

		int special_event();
		void birth_event();
		void sick_event();

		int pay_food_cost();
		void update_base_food_cost();

		int user_animal_choice();
		int number_of_purchases();
		int print_purchase_options();
		void purchase_animals();

		void add_black_bear(Black_bear);
		void add_lemur(Lemur);
		void add_tiger(Tiger);

		void remove_black_bear(int);
		void remove_lemur(int);
		void remove_tiger(int);

		void zoo_revenue();
		
		int continue_game();
		void play_zoo_tycoon();

		~Zoo();					// destructor
};

#endif