#include <iostream>
#include "animal.h"
#include "monkey.h"
using namespace std;

int main() {
	// create a generic animal
	Animal a1("Bambi", 15);
	cout << "Generic animal age: " << a1.get_age() << endl;
  
	// name is private, so we can't access it from main
	a1.set_name("Henry");
	cout << "\nCreated animal. Retrieved name: " << a1.get_name() << endl;
  
  // age is protected, so we can't access it from main [i.e., we can't do a1.age = 18;]

	Monkey m1;
	// now we can use the inherited variables and functions
	cout << "\nCreated monkey. Retrieved name: " << m1.get_name() << endl;
   m1.set_name("King Louie");
   cout << "\nMonkey name: " << m1.get_name() << endl;
	cout << "Monkey age: " << m1.get_age() << "\n\n\n";

	return 0;
}