#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include "House.h"
using namespace std;

House::House(int num1, int num2) : numBedrooms(num1), numBathrooms(num2) {
	cout << "\n\n\nConstructed a new house with " << numBedrooms << " bedrooms." << endl;
}

// include the capability to set a resident
void House::setResident(string name, string role) {
	// empty the original residents
	residents.clear();
  
	Person newPerson;
	newPerson.setInfo(name, role);
	residents.push_back(newPerson);
}

// insert an additional resident
void House::addResident(string name, string role) {
	Person newPerson;
	newPerson.setInfo(name, role);
	residents.push_back(newPerson);
}

void House::display() {
	cout << "\nHouse info:" << endl;
	cout << "Number of bedrooms: " << numBedrooms << endl;
	cout << "Number of bathroom: " << numBathrooms << endl;
	cout << "Number of residents: " << residents.size() << endl;
   
	for (auto it = residents.cbegin(); it != residents.cend(); it++) {
		cout << "\tRes: " << it->getName() << ", " << it->getRole() << endl;
	}
   
  cout << "\n";
}

void House::sort() {
	std::sort(residents.begin(), residents.end());      // uses built-in sort() function
}

void House::shuffle() {
   unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(residents.begin(), residents.end(), std::default_random_engine(seed));
}