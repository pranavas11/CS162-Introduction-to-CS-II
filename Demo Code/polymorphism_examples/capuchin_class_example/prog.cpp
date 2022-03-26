#include <iostream>
#include "animal.h"
#include "monkey.h"
#include "capuchin.h"

using namespace std;

/*
  Illustrate how to utilize inheritance
*/
int main() {
	// demonstrate how functions work with different types of objects
	Animal a1("Ditto");
	Monkey m1("Curious George");
	Capuchin c1("King Louie");
	
	cout << "a1 name:" << a1.get_name() << endl; // runs the Animal version
	cout << "m1 name:" << m1.get_name() << endl; // runs the Monkey version
	cout << "c1 name:" << c1.get_name() << endl; // runs the Capuchin version

	Animal *aptr = &a1;
	Animal *aptr2 = &m1;
	Animal *aptr3 = &c1;

	// illustrate polymorphism in action:
	cout << "aptr says: " << endl;
	aptr->make_noise(3); // runs the Animal version
	cout << "aptr2 says: " << endl;
	aptr2->make_noise(3); // runs the Monkey version
	cout << "aptr3 says: " << endl;
	aptr3->make_noise(3); // runs the Capuchin version

	cout << "aptr1 name:" << aptr->get_name() << endl;
	cout << "aptr2 name:" << aptr2->get_name() << endl;
	cout << "aptr3 name:" << aptr3->get_name() << endl;

	return 0;
}