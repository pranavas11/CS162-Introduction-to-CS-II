#include <iostream>

#ifndef HOUSE_H
#define HOUSE_H

#include "Person.h"

class House {
public:
	House(int, int);      // specify number of rooms and bathrooms
  ~House();
  
	void setResident(std::string, std::string);
	void addResident(std::string, std::string);
	void display();

private:
	int numBedrooms;
	int numBathrooms;
	int numResidents;
	Person* residents;
	double rent;
};

#endif