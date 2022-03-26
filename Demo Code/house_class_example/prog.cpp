#include <iostream>
#include "House.h"
using namespace std;

int main() {
	House h1(5, 5);
	h1.setResident("Adam", "student");
	h1.addResident("Brian", "chef");
	h1.addResident("Samantha", "student");
	h1.display();

	return 0;
}