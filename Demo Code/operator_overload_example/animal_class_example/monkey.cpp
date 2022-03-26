/*
	Monkey Class
*/
#include <iostream>
#include "monkey.h"

// This Monkey constructor shows how we can invoke an
// alternate Animal constructor when the Monkey is created.
// It also uses a member initialization list for longest_jump.
Monkey::Monkey(string name) : Animal(name, 0), longest_jump(5) {
	cout << "Default monkey constructor called" << endl;
}

string Monkey::get_name() {
	// we have overridden the get_name function
	// instead of the plain name, we will add an honorary title
	string monkey_name = "Honorable " + Animal::get_name();
	return monkey_name;
}

/*int Monkey::get_age() {
	
	int monkey_age = 10 + Animal::get_age();
	return monkey_age;
}*/
