#include <iostream>
#include "animal.h"
#include "monkey.h"

using namespace std;

int main() {

	Animal a1("Ditto");
	Monkey m1("Curious George");

	//compile time overloading
	cout << a1.get_name() << endl;
	cout << m1.get_name() << endl;

	Animal* aptr = &a1;
	Animal* aptr2 = &m1;

	cout << aptr->get_name() << endl;
	cout << aptr2->get_name() << endl;
	aptr2->make_noise(3);

	Animal* array[2];
	array[0] = &a1;
	array[1] = &m1;

	for (int i=0; i<2; i++)
		array[i]->make_noise(3);

	return 0;
}