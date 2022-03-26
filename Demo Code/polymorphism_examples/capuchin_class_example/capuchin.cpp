/*
	Capuchin Class
*/
#include <iostream>
#include "capuchin.h"

using namespace std;


Capuchin::Capuchin(string name) : Monkey(name) {
	size = 10;
	cout << "alternate capuchin constructor called" << endl;
}

string Capuchin::get_name() {
	string monkey_name = "Tiny " + Animal::get_name();
	return monkey_name;
}

void Capuchin::make_noise(int num) {
   for (int i = 0; i < num; i++)
      cout << "ooOOOOOOOooooOOOOOOOOO" << " ";
   cout << endl;
}

// void Capuchin::move_forward(int steps){
	// cout << "Capuchin moved " << steps << endl;	
// }