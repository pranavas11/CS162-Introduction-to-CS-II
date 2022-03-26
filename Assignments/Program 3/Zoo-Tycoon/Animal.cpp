#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Animal.h"
using namespace std;

// default constructor which sets default values for member variables
Animal::Animal() {		// default constructor explicitly defined in order to avoid compiler generated default constructor which will have garbage vales
	this->age = -1;
	this->cost = -1;
	this->num_of_babies = -1;
	this->food_cost = -1;
	this->revenue = -1;
}

// paramterized constructor which sets the animal's age
Animal::Animal(int animal_age) {
	this->age = animal_age;
	this->cost = -1;
	this->num_of_babies = -1;
	this->food_cost = -1;
	this->revenue = -1;
}

// copy constructor which sets the class member variables to each animal's corresponding values
Animal::Animal(const Animal& new_animal) {
	this->age = new_animal.age;
	this->cost = new_animal.cost;
	this->num_of_babies = new_animal.num_of_babies;
	this->food_cost = new_animal.food_cost;
	this->revenue = new_animal.revenue;
}

// assignment overload operator
Animal& Animal::operator=(Animal new_animal) {
	this->age = new_animal.age;
	this->cost = new_animal.cost;
	this->num_of_babies = new_animal.num_of_babies;
	this->food_cost = new_animal.food_cost;
	this->revenue = new_animal.revenue;
	return *this;
}

void Animal::increment_age() { this->age += 1; }

int Animal::get_age() { return age; }

int Animal::get_cost() { return cost; }

int Animal::get_num_of_babies() { return num_of_babies; }

float Animal::get_food_cost() { return food_cost; }

float Animal::get_revenue() {
	float zoo_revenue = (float)(cost * revenue);
	if (this->age <= 5) return zoo_revenue * 2;
	return zoo_revenue;
}

Animal::~Animal() {
	// cout << "\nAnimal destructor called!\n";
}