#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Bear.h"
using namespace std;

// default constructor for Bear class which sets default values for member variables inherited from Animal class
Black_bear::Black_bear() {
	age = 0;
	cost = 6000;
	num_of_babies = 2;
	food_cost = 3;
	revenue = 0.1;
}

// parameterized constructor keeps track of a bear's age as it grows from childhood to adulthood
Black_bear::Black_bear(int bear_age) {
	age = bear_age;                          // variable (i.e., value that changes)
	cost = 6000;                             // constant (i.e., value that doesn't change)
	num_of_babies = 2;                       // constant
	food_cost = 3;                           // constant
	revenue = 0.1;                           // constant
}

// Bear class copy constructor
Black_bear::Black_bear(const Black_bear& new_black_bear) {
	age = new_black_bear.age;
	cost = new_black_bear.cost;
	num_of_babies = new_black_bear.num_of_babies;
	food_cost = new_black_bear.food_cost;
	revenue = new_black_bear.revenue;
}

Black_bear::~Black_bear() {
	//cout << "\nBlack bear destructor called!\n";
}