#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using namespace std;

class Animal {
public:
	Animal();
	Animal(string, int);
  
	string get_name();
	int get_age();
  void set_name(string);

private:
	string name;  // visible only to the Animal class

protected:
	int age;      //derived class access, not main
};

#endif