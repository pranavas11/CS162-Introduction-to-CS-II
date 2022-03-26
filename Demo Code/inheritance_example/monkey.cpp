#include <iostream>
#include "monkey.h"
using namespace std;

Monkey::Monkey() {
  cout << "\nDefault monkey constructor called!" << endl;
  age = 11;
	longest_jump = 5;
  max_bananas = 17;
}

Monkey::Monkey(string name, int age) : Animal(name, age) {
  cout << "\nAlternate monkey constructor called!" << endl;
	longest_jump = 5;
  max_bananas = 17;
}

int Monkey::get_age() {
	cout << "\nMonkey get age called!" << endl;
	return age;
}