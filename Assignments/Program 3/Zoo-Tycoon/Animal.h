#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

class Animal {
	protected:			// members cannot be accessed from outside the class; however, they can be accessed in inherited classes
		int age;
		int cost;
		int num_of_babies;
		float food_cost;
		float revenue;

	public:
		Animal();									      // default constructor
		Animal(int);							      // parameterized constructor
		Animal(const Animal&);		      // copy constructor
		Animal& operator=(Animal);      // assignment operator overload constructor

		~Animal();								      // destructor

		void increment_age();		        // setter function (mutator)

		int get_age();					        // getter functions (accessors)
		int get_cost();
		int get_num_of_babies();
		float get_food_cost();
		float get_revenue();
};

#endif