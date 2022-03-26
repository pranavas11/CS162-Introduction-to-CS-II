#include <iostream>
#include <vector>

#ifndef HOUSE_H
#define HOUSE_H

#include "Person.h"

class House {
public:
	House(int, int); // specify number of rooms and bathrooms
	void setResident(std::string, std::string);
	void addResident(std::string, std::string);
	void display();
	void sort();
	void shuffle();

private:
	int numBedrooms;
	int numBathrooms;
//	int numResidents;
//	Person* residents; // <-- dynamically allocated array of Person objects
	std::vector<Person> residents;
	double rent;
};

#endif