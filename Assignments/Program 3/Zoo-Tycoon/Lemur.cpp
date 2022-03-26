#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Lemur.h"
using namespace std;

// default constructor for Lemur class which sets default values for member variables inherited from Animal class
Lemur::Lemur() {
	age = 0;
	cost = 700;
	num_of_babies = 1;
	food_cost = 1;
	revenue = 0.2;
}

// parameterized constructor which sets age for newly born (age = 0) and newly purchased (age = 4 years/48 months) lemurs
Lemur::Lemur(int lemur_age) {
	age = lemur_age;              // variable (i.e., value that changes)
	cost = 700;                   // constant (i.e., value that doesn't change)
	num_of_babies = 1;            // constant
	food_cost = 1;                // constant
	revenue = 0.2;                // constant
}

// Lemur class copy constructor
Lemur::Lemur(const Lemur& new_lemur) {
	age = new_lemur.age;
	cost = new_lemur.cost;
	num_of_babies = new_lemur.num_of_babies;
	food_cost = new_lemur.food_cost;
	revenue = new_lemur.revenue;
}

Lemur::~Lemur() {
	//cout << "\nLemur destructor called!\n";
}