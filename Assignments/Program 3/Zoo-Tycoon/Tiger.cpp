#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Tiger.h"
using namespace std;

// default constructor for Tiger class which sets default values for member variables inherited from Animal class
Tiger::Tiger() {
	age = 0;
	cost = 15000;
	num_of_babies = 3;
	food_cost = 5;
	revenue = 0.1;
}

// parameterized constructor which sets age for newly born (age = 0) and newly purchased (age = 4 years/48 months) tigers
Tiger::Tiger(int tiger_age) {
	age = tiger_age;              // variable (i.e., value that changes)
	cost = 15000;                 // constant (i.e., value that doesn't change)
	num_of_babies = 3;            // constant
	food_cost = 5;                // constant
	revenue = 0.1;                // constant
}

// Tiger class copy constructor
Tiger::Tiger(const Tiger& new_tiger) {
	age = new_tiger.age;
	cost = new_tiger.cost;
	num_of_babies = new_tiger.num_of_babies;
	food_cost = new_tiger.food_cost;
	revenue = new_tiger.revenue;
}

Tiger::~Tiger() {
	//cout << "\nTiger destructor called!\n";
}