#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Zoo.h"
using namespace std;

/*********************************************************************************
 * ** Constructor: Zoo()
 * ** Description: sets initial default values for Zoo class member variables
 * ** Parameters: none
 * ** Pre-conditions: sets bank_money and food_base_cost with known default values
 * ** Post-conditions: returns default values for variables
 *********************************************************************************/
Zoo::Zoo() {                  // give default values for default constructor
	bank_money = 100000;        // owner's initial bank amount = $100,000
	time_advanced = 0; 
	food_base_cost = 80;
	total_food_cost = 0.0;
	revenue = 0.0;

	// as game starts, all animal statistics start at 0
	num_of_bears = 0;
	num_of_bears_bought = 0;

	num_of_lemurs = 0;
	num_of_lemurs_bought = 0;

	num_of_tigers = 0;
	num_of_tigers_bought = 0;
}

// ostream overload function for turning on bold text
ostream& Zoo::bold_text_on(ostream& os) {
  return os << "\e[1m";
}

// ostream overload function for turning off bold text
ostream& Zoo::bold_text_off(ostream& os) {
  return os << "\e[0m";
}

/***************************************************************************************************************
 * ** Function: get_int()
 * ** Description: takes a prompt from the user as a string literal and checks if the inputs is a valid integer
 * ** Parameters: string prompt
 * ** Pre-conditions: takes a string prompt
 * ** Post-conditions: returns the provided integer
 **************************************************************************************************************/
int Zoo::get_int(string prompt) {
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

// retrieves the name of the player
string Zoo::get_player_name() {
	cout << "\033[1;92mPlease enter your name: ";
	getline(cin, user_name);
	return user_name;
}

// retrieves number of baby bears in zoo
int Zoo::get_baby_bears() {
	int num_of_babies = 0;
	for (int i = 0; i < num_of_bears; i++) {
		if (black_bears[i].get_age() < 5) num_of_babies++;      // increment count of babies if age <= 5 months old
	}
	return num_of_babies;
}

// retrieves number of baby lemurs in zoo
int Zoo::get_baby_lemurs() {
	int num_of_babies = 0;
	for (int i = 0; i < num_of_lemurs; i++) {
		if (lemurs[i].get_age() < 5) num_of_babies++;           // increment count of babies if age <= 5 months old
	}
	return num_of_babies;
}

// retrieves number of baby tigers in zoo
int Zoo::get_baby_tigers() {
	int num_of_babies = 0;
	for (int i = 0; i < num_of_tigers; i++) {
		if (tigers[i].get_age() < 5) num_of_babies++;           // increment count of babies if age <= 5 months old
	}
	return num_of_babies;
}

// retrieves number of adolescent bears in zoo
int Zoo::get_adolescent_bears() {
	int num_of_adolescents = 0;
	for (int i = 0; i < num_of_bears; i++) {          // increment count of adolescents if age > 5 months & age < 48 months
		if (black_bears[i].get_age() >= 5 && black_bears[i].get_age() < 48) num_of_adolescents++;
	}
	return num_of_adolescents;
}

// retrieves number of adolescent lemurs in zoo
int Zoo::get_adolescent_lemurs() {
	int num_of_adolescents = 0;
	for (int i = 0; i < num_of_lemurs; i++) {          // increment count of adolescents if age > 5 months & age < 48 months
		if (lemurs[i].get_age() >= 5 && lemurs[i].get_age() < 48) num_of_adolescents++;
	}
	return num_of_adolescents;
}

// retrieves number of adolescent tigers in zoo
int Zoo::get_adolescent_tigers() {
	int num_of_adolescents = 0;
	for (int i = 0; i < num_of_tigers; i++) {          // increment count of adolescents if age > 5 months & age < 48 months
		if (tigers[i].get_age() >= 5 && tigers[i].get_age() < 48) num_of_adolescents++;
	}
	return num_of_adolescents;
}

// retrieves number of adult bears in zoo
int Zoo::get_adult_bears() {
	int num_of_adults = 0;
	for (int i = 0; i < num_of_bears; i++) {
		if (black_bears[i].get_age() >= 48) num_of_adults++;      // increment count of adults if age >= 48 months old
	}
	return num_of_adults;
}

// retrieves number of adult lemurs in zoo
int Zoo::get_adult_lemurs() {
	int num_of_adults = 0;
	for (int i = 0; i < num_of_lemurs; i++) {
		if (lemurs[i].get_age() >= 48) num_of_adults++;          // increment count of adults if age >= 48 months old
	}
	return num_of_adults;
}

// retrieves number of adult tigers in zoo
int Zoo::get_adult_tigers() {
	int num_of_adults = 0;
	for (int i = 0; i < num_of_tigers; i++) {
		if (tigers[i].get_age() >= 48) num_of_adults++;          // increment count of adults if age >= 48 months old
	}
	return num_of_adults;
}

/****************************************************************************
 * ** Function: print_game_conditions()
 * ** Description: prints a table of zoo data
 * ** Parameters: none
 * ** Pre-conditions: retrieves number of baby, adolescent, and adult animals
 * ** Post-conditions: provides user with a zoo database table each month
 ****************************************************************************/
void Zoo::print_game_conditions() {
	time_advanced++;
	int baby_bears = get_baby_bears();
	int baby_lemurs = get_baby_lemurs();
	int baby_tigers = get_baby_tigers();
	int adolescent_bears = get_adolescent_bears();
	int adolescent_lemurs = get_adolescent_lemurs();
	int adolescent_tigers = get_adolescent_tigers();
	int adult_bears = get_adult_bears();
	int adult_lemurs = get_adult_lemurs();
	int adult_tigers = get_adult_tigers();

	string month_event;
	if (monthly_event == 1) month_event = "Sickness";
	else if (monthly_event == 2) month_event = "Birth";
	else month_event = "None";

	string monthly_status;
	if (bank_money > 75000) monthly_status = "Excellent!";
	else if (bank_money > 50000 && bank_money <= 75000) monthly_status = "Good";
	else if (bank_money > 25000 && bank_money <= 50000) monthly_status = "Poor";
  else monthly_status = "Bad!";
  
  float bank_status = (bank_money > 0.0) ? bank_money : bank_money = 0.0;

	cout << "\n\n\n\033[0;93m\033[4;33mZoo Status at the end of month " << time_advanced << ":";
	cout << "\n\n\n\033[0m\033[1;94m*******************************************************************************************\n";
	cout << "*\t\t\t\t\t\t\t\t\t\t\t  *\n*\033[1;92m\t\t\t\t" << user_name << "\'s Zoo Tycoon\033[1;94m\t\t\t\t\t  *\n";
	cout << "*\t\t\t\t\t\t\t\t\t\t\t  *\n*******************************************************************************************\n";
  cout << "*\t\t\t\t\t\t\t\t\t\t\t  *\n";
	cout << "* Bank Amount: $" << bank_status << "\t\t\t|\t";
	cout << "Food cost: $" << total_food_cost << "\t\t\t\t  *\n";
	cout << "* Month: " << time_advanced << "\t\t\t\t|\t";
	cout << "Special Event: " << month_event << "\t\t\t  *\n";
	cout << "* Revenue: $" << revenue << "\t\t\t\t|\t";
	cout << "Monthly Status: " << monthly_status << "\t\t  *\n";
	cout << "*\t\t\t\t\t\t\t\t\t\t\t  *\n*******************************************************************************************\n";
  cout << "*\t\t\t\t\t\t\t\t\t\t\t  *\n";
	cout << "* Baby bears: " << baby_bears << "\t\t|\t";
	cout << "Teen bears: " << adolescent_bears << "\t\t|\t";
	cout << "Adult bears: " << adult_bears << "\t\t  *\n";
	cout << "* Baby lemurs: " << baby_lemurs << "\t|\t";
	cout << "Teen lemurs: " << adolescent_lemurs << "\t\t|\t";
	cout << "Adult lemurs: " << adult_lemurs << "\t\t  *\n";
	cout << "* Baby tigers: " << baby_tigers << "\t|\t";
	cout << "Teen tigers: " << adolescent_tigers << "\t\t|\t";
	cout << "Adult tigers: " << adult_tigers << "\t\t  *\n";
	cout << "* ----------------------|-------------------------------|-------------------------------- *\n";
	cout << "* Total babies: " << baby_bears + baby_lemurs + baby_tigers << "\t|";
	cout << "\tTotal teens: " << adolescent_bears + adolescent_lemurs + adolescent_tigers << "\t\t|";
	cout << "\tTotal adults: " << adult_bears + adult_lemurs + adult_tigers << "\t\t  *\n";
	cout << "*\t\t\t\t\t\t\t\t\t\t\t  *\n*******************************************************************************************\n";
  cout << "*\t\t\t\t\t\t\t\t\t\t\t  *\n";
	cout << "* Total bears: " << num_of_bears << "\t|";
	cout << "\tTotal lemurs: " << num_of_lemurs << "\t\t|";
	cout << "\tTotal tigers: " << num_of_tigers << "\t\t  *\n";
	cout << "*\t\t\t\t\t\t\t\t\t\t\t  *\n*******************************************************************************************\n";
  cout << "*\t\t\t\t\t\t\t\t\t\t\t  *\n";
	cout << "*\t\t\t\tTotal Number of Animals in Zoo: " << num_of_bears + num_of_lemurs + num_of_tigers << "\t\t\t  *\n";
	cout << "*\t\t\t\t\t\t\t\t\t\t\t  *\n*******************************************************************************************\n\n\n";
}

// retrieves the incremented animal ages each month
void Zoo::get_animal_ages() {
	for (int i = 0; i < num_of_bears; i++) black_bears[i].increment_age();
	for (int i = 0; i < num_of_lemurs; i++) lemurs[i].increment_age();
	for (int i = 0; i < num_of_tigers; i++) tigers[i].increment_age();
}

// generates a random base food cost between 80% and 120% of the base cost from the month before
void Zoo::update_base_food_cost() {
	food_base_cost *= (float) ((rand() % 41) + 80) / 100.0;
	//cout << "Base base food cost: " << food_base_cost << ".\n";
}

/************************************************************************************************
 * ** Function: pay_food_cost()
 * ** Description: pays the total food cost of each animal for each month
 * ** Parameters: none
 * ** Pre-conditions: obtains food cost of bears, lemurs, and tigers
 * ** Post-conditions: total_food_cost of each animal is deducted automatically from bank account
 ************************************************************************************************/
int Zoo::pay_food_cost() {
	total_food_cost = 0.0;

	for (int i = 0; i < num_of_bears; i++) total_food_cost += food_base_cost * black_bears[i].get_food_cost();      // tfc = fbc * 3
	for (int i = 0; i < num_of_lemurs; i++) total_food_cost += food_base_cost * lemurs[i].get_food_cost();          // tfc = fbc * 1
	for (int i = 0; i < num_of_tigers; i++) total_food_cost += food_base_cost * tigers[i].get_food_cost();          // tfc = fbc * 5

	cout << "\n\n\n\033[1;96m\033[4;34mYou need to pay a total of $" << total_food_cost << " of food cost this month for your animals.\n\n\033[0mMoney will be automatically deducted from your bank account.\n";
	bank_money -= total_food_cost;      // subtract total food cost from bank money
	return total_food_cost;
}

/*************************************************************************************************
 * ** Function: is_adult()
 * ** Description: checks if each animal in zoo is an adult
 * ** Parameters: int species_type
 * ** Pre-conditions: loops through number of bears, lemurs, and tigers to check for adult animals
 * ** Post-conditions: returns true if for adult animals in zoo and false otherwise
 *************************************************************************************************/
bool Zoo::is_adult(int species_type) {
	if (species_type == 1) {
		for (int i = 0; i < num_of_bears; i++) {
			if (black_bears[i].get_age() >= 48) return true;      // if bear >= 48 months old
		}
	} else if (species_type == 2) {
		for (int i = 0; i < num_of_lemurs; i++) {
			if (lemurs[i].get_age() >= 48) return true;          // if lemur >= 48 months old
		}
	} else {
		for (int i = 0; i < num_of_tigers; i++) {
			if (tigers[i].get_age() >= 48) return true;          // if tiger >= 48 months old
		}
	}
	return false;
}

/*******************************************************************************
 * ** Function: add_black_bear()
 * ** Description: adds new black bears to existing number of bears in the zoo
 * ** Parameters: Black_bear new_black_bear
 * ** Pre-conditions: takes Black_bear new_black_bear
 * ** Post-conditions: appends new black bears to existing array of black bears
 ******************************************************************************/
void Zoo::add_black_bear(Black_bear new_black_bear) {
	Black_bear* temp = new Black_bear[num_of_bears+1];

	for (int i = 0; i < num_of_bears; i++) temp[i] = black_bears[i];

	if (num_of_bears != 0) delete [] black_bears;
	black_bears = temp;
	black_bears[num_of_bears++] = new_black_bear;
}

/**************************************************************************
 * ** Function: add_lemur()
 * ** Description: adds new lemurs to existing number of lemurs in the zoo
 * ** Parameters: Lemur new_lemur
 * ** Pre-conditions: takes Lemur new_lemur
 * ** Post-conditions: appends new lemurs to existing array of lemurs
 *************************************************************************/
void Zoo::add_lemur(Lemur new_lemur) {
	Lemur* temp = new Lemur[num_of_lemurs+1];

	for (int i = 0; i < num_of_lemurs; i++) temp[i] = lemurs[i];

	if (num_of_lemurs != 0) delete [] lemurs;
	lemurs = temp;
	lemurs[num_of_lemurs++] = new_lemur;
}

/**************************************************************************
 * ** Function: add_tiger()
 * ** Description: adds new tigers to existing number of tigers in the zoo
 * ** Parameters: Tiger new_tiger
 * ** Pre-conditions: takes Tiger new_tiger
 * ** Post-conditions: appends new tigers to existing array of tigers
 *************************************************************************/
void Zoo::add_tiger(Tiger new_tiger) {
	Tiger* temp = new Tiger[num_of_tigers+1];

	for (int i = 0; i < num_of_tigers; i++) temp[i] = tigers[i];

	if (num_of_tigers != 0) delete [] tigers;
	tigers = temp;
	tigers[num_of_tigers++] = new_tiger;
}

/*****************************************************************************************************************
 * ** Function: birth_event()
 * ** Description: randomly chosen animal gives birth to appropriate number of babies
 * ** Parameters: none
 * ** Pre-conditions: selects a random species type for birth event
 * ** Post-conditions: adds newly born baby animals to existing animals of the appropriate species type in the zoo
 *****************************************************************************************************************/
void Zoo::birth_event() {
	if (num_of_bears + num_of_lemurs + num_of_tigers < 2) {
		cout << "\n\033[1;31mSorry, you do not have enough animals in your zoo that can produce offsprings.\n";
	} else {
		int species_type;
		do {
			species_type = (rand() % 3) + 1;      // select a random animal species
		} while (!is_adult(species_type));      // only adult animals should give birth to babies

		if (species_type == 1) {
			cout << "\n\033[0;33mCongratulations!!! One of your black bears has given birth to " << black_bears[0].get_num_of_babies() << " babies!\n";
			for (int i = 0; i < black_bears[0].get_num_of_babies(); i++) {
				add_black_bear(Black_bear(0));      // adds a baby bear and sets its age to 0 (calls parameterized Black_bear constructor for setting age)
			}
		} else if (species_type == 2) {
			cout << "\n\033[0;33mCongratulations!!! One of your lemurs has given birth to " << lemurs[0].get_num_of_babies() << " baby!\n";
			for (int i = 0; i < lemurs[0].get_num_of_babies(); i++) {
				add_lemur(Lemur(0));      // adds a baby lemur and sets its age to 0 (calls parameterized Lemur constructor for setting age)
			}
		} else {
			cout << "\n\033[0;33mCongratulations!!! One of your tigers has given birth to " << tigers[0].get_num_of_babies() << " babies!\n";
			for (int i = 0; i < tigers[0].get_num_of_babies(); i++) {
				add_tiger(Tiger(0));      // adds a baby tiger and sets its age to 0 (calls parameterized Tiger constructor for setting age)
			}
		}
	}
}

/**************************************************
 * ** Function: remove_black_bear()
 * ** Description: removes dead bears from the zoo
 * ** Parameters: int extinct_bear
 * ** Pre-conditions: takes int extinct_bear
 * ** Post-conditions: eliminates extinct bears
 *************************************************/
void Zoo::remove_black_bear(int extinct_bear) {
	Black_bear* temp = new Black_bear[num_of_bears-1];
	int removed_bears = 0;

	for (int i = 0; i < num_of_bears; i++) {
		if (i != extinct_bear) temp[i-removed_bears] = black_bears[i];
		else removed_bears++;
	}

	delete [] black_bears;
	black_bears = temp;
	num_of_bears--;
}

/***************************************************
 * ** Function: remove_lemur()
 * ** Description: removes dead lemurs from the zoo
 * ** Parameters: int extinct_lemur
 * ** Pre-conditions: takes int extinct_lemur
 * ** Post-conditions: eliminates extinct lemurs
 **************************************************/
void Zoo::remove_lemur(int extinct_lemur) {
	Lemur* temp = new Lemur[num_of_lemurs-1];
	int removed_lemurs = 0;

	for (int i = 0; i < num_of_lemurs; i++) {
		if (i != extinct_lemur) temp[i-removed_lemurs] = lemurs[i];
		else removed_lemurs++;
	}

	delete [] lemurs;
	lemurs = temp;
	num_of_lemurs--;
}

/***************************************************
 * ** Function: remove_tiger()
 * ** Description: removes dead tigers from the zoo
 * ** Parameters: int extinct_tiger
 * ** Pre-conditions: takes int extinct_tiger
 * ** Post-conditions: eliminates extinct tigers
 **************************************************/
void Zoo::remove_tiger(int extinct_tiger) {
	Tiger* temp = new Tiger[num_of_tigers-1];
	int removed_tigers = 0;

	for (int i = 0; i < num_of_tigers; i++) {
		if (i != extinct_tiger) temp[i-removed_tigers] = tigers[i];
		else removed_tigers++;
	}

	delete [] tigers;
	tigers = temp;
	num_of_tigers--;
}

/***********************************************************************************************************************
 * ** Function: sick_event()
 * ** Description: randomly chosen animal gets sick and if money is available, the animal is saved, else it dies
 * ** Parameters: none
 * ** Pre-conditions: selects a random species type for sick event
 * ** Post-conditions: depending upon the availability of money, the animal is either saved or died and removed from zoo
 ***********************************************************************************************************************/
void Zoo::sick_event() {
	if (num_of_bears + num_of_lemurs + num_of_tigers == 0) {
		cout << "\nThere are no animals in the zoo to get sick!\n";
		return;
	} else {
		int random_animal = rand() % (num_of_bears + num_of_lemurs + num_of_tigers);
		int disease_cost = 0;

		cout << "\nSorry, your zoo's unhealthy conditions lead to sickness of your animals!\n";

		if (random_animal < num_of_bears) {                              // if range is within bears
			disease_cost = black_bears[random_animal].get_cost() / 2;      // disease cost equals half the initial cost of a bear
			if (disease_cost > bank_money || bank_money <= 0.0) {
				cout << "\nSorry, you don't have enough money to save the animal! Sadly, the bear died!\n";
				remove_black_bear(random_animal);      // bear dies if no money (1 bear is popped out of the bear array)
			} else {
				if (black_bears[random_animal].get_age() < 5) {          // baby bears cost twice for sick treatment
					disease_cost *= 2;
					cout << "\nA baby bear has gotten sick. It will cost you $" << disease_cost << ".\nMoney will be automatically withdrawn from your bank account to help save the animal.\n";
					bank_money -= disease_cost;
				} else {
					cout << "\nAn adult bear has gotten sick. It will cost you $" << disease_cost << ".\nMoney will be automatically withdrawn from your bank account to help save the animal.\n";
					bank_money -= disease_cost;
				}
			}
		} else if (random_animal < num_of_bears + num_of_lemurs) {      // if range is within lemurs
			disease_cost = lemurs[random_animal - num_of_bears].get_cost() / 2;      // disease cost equals half the initial cost of a lemur

			if (disease_cost > bank_money || bank_money <= 0.0) {
				cout << "\nSorry, you don't have enough money to save the animal! Sadly, the lemur died!\n";
				remove_lemur(random_animal - num_of_bears);          // lemur dies if no money (1 lemur is popped out of the lemur array)
			} else {
				if (lemurs[random_animal - num_of_bears].get_age() <= 5) {      // baby lemurs cost twice for sick treatment
					disease_cost *= 2;
					cout << "\nA baby lemur has gotten sick. It will cost you $" << disease_cost << ".\nMoney will be automatically withdrawn from your bank account to help save the animal.\n";
					bank_money -= disease_cost;
				} else {
					cout << "\nAn adult lemur has gotten sick. It will cost you $" << disease_cost << ".\nMoney will be automatically withdrawn from your bank account to help save the animal.\n";
					bank_money -= disease_cost;
				}
			}
		} else {                  // if range is within tigers
			disease_cost = tigers[random_animal - (num_of_bears + num_of_lemurs)].get_cost() / 2;      // disease cost equals half the initial cost of a tiger

			if (disease_cost > bank_money || bank_money <= 0.0) {
				cout << "\nSorry, you don't have enough money to save the animal! Sadly, the tiger died!\n";
				remove_tiger(random_animal - (num_of_bears + num_of_lemurs));      // tiger dies if no money (1 tiger is popped out of the tiger array)
			} else {
				if (tigers[random_animal - (num_of_bears + num_of_lemurs)].get_age() <= 5) {      // baby tigers cost twice for sick treatment
					disease_cost *= 2;
					cout << "\nA baby tiger has gotten sick. It will cost you $" << disease_cost << ".\nMoney will be automatically withdrawn from your bank account to help save the animal.\n";
					bank_money -= disease_cost;
				} else {
					cout << "\nAn adult tiger has gotten sick. It will cost you $" << disease_cost << ".\nMoney will be automatically withdrawn from your bank account to help save the animal.\n";
					bank_money -= disease_cost;
				}
			}
		}
	}
}

/************************************************************
 * ** Function: special_event()
 * ** Description: random special event selection each month
 * ** Parameters: int extinct_tiger
 * ** Pre-conditions: takes int extinct_tiger
 * ** Post-conditions: eliminates extinct tigers
 ************************************************************/
int Zoo::special_event() {
	cout << "\n\n\n\033[4;33mHere's the special event for this month:\n";
	int random_event = (rand() % 3) + 1;      // random number between 1 and 3 (inclusive)

	if (random_event == 1) {
		cout << "\nMonthly special event: Sickness\033[0m\n";
		sick_event();
	} else if (random_event == 2) {
		cout << "\nMonthly special event: Birth\033[0m\n";
		birth_event();
	} else {
		cout << "\nNo special event has occurred this month!\033[0m\n";
	}
	return random_event;
}

/*****************************************************************
 * ** Function: user_animal_choice()
 * ** Description: asks user what animal he/she would like to buy
 * ** Parameters: none
 * ** Pre-conditions: asks user for a valid option
 * ** Post-conditions: returns user's animal choice
 ****************************************************************/
int Zoo::user_animal_choice() {
	int animal_choice;
	string option;
	cout << "\nWhat animal would you like to purchase this month?\n";
	cout << "\n\033[1;96m[1] Black bear\n\033[1;95m[2] Lemur\n\033[1;91m[3] Tiger\n";
	cout << "\n\033[1;35mPlease pick an option: ";

	while (true) {          // error handling
		cin >> option;
		animal_choice = get_int(option);
		if (animal_choice == -1 || animal_choice < 1 || animal_choice > 3) {
			cout << "\nInvalid input! Please select a valid option: ";
      cin.clear();
      cin.ignore(256, '\n');
    } else {
      cin.clear();
      cin.ignore(256, '\n');
      break;
    }
	}
	return animal_choice;
}

/*****************************************************************************
 * ** Function: print_purchase_options()
 * ** Description: asks user if he/she would like to buy an animal each month
 * ** Parameters: none
 * ** Pre-conditions: asks user for a valid option
 * ** Post-conditions: returns user's animal choice
 ****************************************************************************/
int Zoo::print_purchase_options() {
	string input;
	int animal_choice = -1;
	cout << "\n\n\n\033[0m\033[1;91mWould you like to buy an animal this month (y/n)? ";
	cin >> input;

	if (input == "Yes" || input == "yes" || input == "Y" || input == "y") {
		animal_choice = user_animal_choice();
	}
	return animal_choice;
}

/***********************************************************************************************
 * ** Function: purchase_animals()
 * ** Description: purchases a new adult animal of a particular species
 * ** Parameters: none
 * ** Pre-conditions: determines species type for purchase(s)
 * ** Post-conditions: purchases the user's desired number of adult animals of a certain species
 ***********************************************************************************************/
void Zoo::purchase_animals() {
	int user_input = print_purchase_options();
	string input;

	if (user_input == 1) {                          // if user chooses to buy a bear
		add_black_bear(Black_bear(48));               // add a new adult bear and set its age to 48 (calls parameterized Bear constructor)
		num_of_bears_bought++;                        // increase count of bears bought
		bank_money -= black_bears[0].get_cost();      // subtract purchase cost from bank money

		cout << "\n\033[1;96mWould you like to purchase another animal of the black bear species (y/n)? ";
		cin >> input;
		if (input == "Yes" || input == "yes" || input == "Y" || input == "y") {
			add_black_bear(Black_bear(48));
			num_of_bears_bought++;
			bank_money -= black_bears[0].get_cost();
		}
	} else if (user_input == 2) {              // if user chooses to buy a lemur
		add_lemur(Lemur(48));                    // add a new adult lemur and set its age to 48 (calls parameterized Lemur constructor)
		num_of_lemurs_bought++;                  // increase count of lemurs bought
		bank_money -= lemurs[0].get_cost();      // subtract purchase cost from bank money

		cout << "\n\033[1;95mWould you like to purchase another animal of the lemur species (y/n)? ";
		cin >> input;
		if (input == "Yes" || input == "yes" || input == "Y" || input == "y") {
			add_lemur(Lemur(48));
			num_of_lemurs_bought++;
			bank_money -= lemurs[0].get_cost();
		}
	} else if (user_input == 3) {              // if user chooses to buy a tiger
		add_tiger(Tiger(48));                    // add a new adult tiger and set its age to 48 (calls parameterized Tiger constructor)
		num_of_tigers_bought++;                  // increase count of tigers bought
		bank_money -= tigers[0].get_cost();      // subtract purchase cost from bank money

		cout << "\n\033[1;91mWould you like to purchase another animal of the tiger species (y/n)? ";
		cin >> input;
		if (input == "Yes" || input == "yes" || input == "Y" || input == "y") {
			add_tiger(Tiger(48));
			num_of_tigers_bought++;
			bank_money -= tigers[0].get_cost();
		}
	}
}

/*******************************************************************************************
 * ** Function: zoo_revenue()
 * ** Description: calculates the revenue generated by the zoo animals each month
 * ** Parameters: none
 * ** Pre-conditions: loops through number of bears, lemurs, and tigers to calculate revenue
 * ** Post-conditions: adds the profit to the bank money each month
 *******************************************************************************************/
void Zoo::zoo_revenue() {
	revenue = 0.0;

	for (int i = 0; i < num_of_bears; i++) {
		revenue += black_bears[i].get_revenue();
	}
	for (int i = 0; i < num_of_lemurs; i++) {
		revenue += lemurs[i].get_revenue();
	}
	for (int i = 0; i < num_of_tigers; i++) {
		revenue += tigers[i].get_revenue();
	}

	cout << "\n\n\n\033[4;32m\033[1;32mYour monthly revenue is $" << revenue << ".\033[1;36m\n";
	bank_money += revenue;
}

/***********************************************************************************
 * ** Function: continue_game()
 * ** Description: asks user if he/she wants to continue playing for the next month
 * ** Parameters: none
 * ** Pre-conditions: asks user for a valid input
 * ** Post-conditions: returns user's choice to continue playing
 ***********************************************************************************/
int Zoo::continue_game() {
	int play_again;
	string option;
	cout << "\n\n\n\033[0;31mWould you like to continue playing for the next month (1 = yes/ 0 = no)? ";
  
	while (true) {          // error handling
    cin >> option;
    play_again = get_int(option);
    if (play_again == -1 || play_again < 0 || play_again > 1) {
      cout << "\n\033[0;35mInvalid input! Please select a valid option: ";
      cin.clear();
      cin.ignore(256, '\n');
    } else {
      cin.clear();
      cin.ignore(256, '\n');
      break;
    }
  }
  
	return play_again;
}

/****************************************************************************************************************
 * ** Function: play_zoo_tycoon()
 * ** Description: plays the game of Zoo Tycoon
 * ** Parameters: none
 * ** Pre-conditions: retrives player's name and player's choice to continue playing each month
 * ** Post-conditions: player plays the game until he/she goes bankrupt or he/she voluntarily quits after a month
 ****************************************************************************************************************/
void Zoo::play_zoo_tycoon() {
	user_name = get_player_name();
  cout << "\n\n\n\033[0;33mYour Initial Bank Money: $" << bank_money << "\n";
	int user_choice = continue_game();
  
	while (bank_money > 0.0 && user_choice == 1) {
		get_animal_ages();
		monthly_event = special_event();
		zoo_revenue();
		purchase_animals();
		pay_food_cost();
		update_base_food_cost();
		print_game_conditions();
    if (bank_money <= 0.0) break;
		user_choice = continue_game();
	}

	if (bank_money <= 0.0) {
		cout << "\n\n\n\033[1;93mI'm sorry to say that your zoo has gone bankrupt due to low bank balance. Please play again! Goodbye!\n\n\n";
	} else {
		cout << "\n\n\n\033[0;37mSorry to see you go! Please play again later! Goodbye!\n\n\n";
	}
}

// Zoo destructor (frees dynamic memory - memory allocated for storing the array of animals)
Zoo::~Zoo() {
	if (num_of_bears != 0) delete[] black_bears;
	if (num_of_lemurs != 0) delete[] lemurs;
	if (num_of_tigers != 0) delete[] tigers;
}