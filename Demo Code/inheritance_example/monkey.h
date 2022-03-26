#ifndef MONKEY_H
#define MONKEY_H

#include <iostream>
#include "animal.h"
using namespace std;

// Monkey class is derived from Animal class
class Monkey : public Animal {
public:
  Monkey();
  Monkey(string, int);
  
  // public method
	int get_age();

private:
	// Note that monkeys can also have extra properties in addition to the ones that are inherited.
	int longest_jump;
  int max_bananas;
};

#endif