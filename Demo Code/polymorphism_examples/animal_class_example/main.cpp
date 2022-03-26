/*
	Written by Justin Goins as an in-class demo of polymorphism
*/
#include <iostream>
#include "animal.h"
#include "goat.h"
#include "fish.h"

using namespace std;

/*
  Illustrate how to utilize inheritance
*/
int main() {

//	Animal a1;
	Goat g1("Bob");
	Fish f1;

	Animal* ptr;
//	ptr = &a1;
//	ptr->make_noise();

	// point ptr at a goat and try to make noise...
	ptr = &g1;
	ptr->make_noise();
	// now use the same pointer and point it at a fish
	ptr = &f1;
	ptr->make_noise();

	return 0;
}
