#include <iostream>
#include <cstdlib>
#include "House.h"
using namespace std;

int main() {
	House h1(5, 5);
	h1.addResident("Brian", "chef");
	h1.addResident("Samantha", "student");
	h1.addResident("Adam", "student");
	h1.addResident("Zoey", "student");
	h1.addResident("Sharlene", "student");
	h1.sort();
	h1.display();
	h1.shuffle();
	h1.display();

	return 0;
}