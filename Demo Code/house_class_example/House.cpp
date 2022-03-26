#include <iostream>
#include "House.h"
using namespace std;

House::House(int num1, int num2) : numBedrooms(num1), numBathrooms(num2) {
	cout << "\n\n\nConstructed a new house with " << numBedrooms << " bedrooms." << endl;
	residents = nullptr;      // the same as setting the pointer to 0
}

// include the capability to set a resident
void House::setResident(string name, string role) {
  // delete any existing residents to set new residents
	delete[] residents;

	Person* ptr = new Person[1];
	ptr[0].setInfo(name, role);
	numResidents = 1;
	residents = ptr;
}

// insert an additional resident
void House::addResident(string name, string role) {
	// copy any existing residents into a new expanded array
	Person* tmp = new Person[numResidents + 1];
	for (int i = 0; i < numResidents; i++) {
		tmp[i] = residents[i];
	}
  
	// insert the new resident into the final element of the array
	tmp[numResidents].setInfo(name, role);
	numResidents++;

	delete[] residents;
	residents = tmp;
}

void House::display() {
	cout << "\nHouse info:" << endl;
	cout << "Number of bedrooms: " << numBedrooms << endl;
	cout << "Number of bathroom: " << numBathrooms << endl;
	cout << "Number of residents: " << numResidents << endl;
	for (int i = 0; i < numResidents; i++) {
		cout << "\tRes: " << residents[i].getName() << ", " << residents[i].getRole() << endl;
	}
  cout << "\n\n\n";
}

// destructor
House::~House() {
	if (residents != nullptr) {
		delete[] residents;
	}
}