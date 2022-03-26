#include <iostream>
#include "animal.h"
#include "monkey.h"
#include "sea_otter.h"
#include "teal_sea_otter.h"
#include "red_sea_otter.h"
using namespace std;

int main() {
	Monkey m1("Curious George");
	Teal_Sea_Otter tso1("Blue Otter Pop");
	Red_Sea_Otter rso1("Pascal");

	// show how to catch a custom exception
	try {
		int distance = 30;
		cout << tso1.get_name() << " will take " << tso1.predict_swim_time(distance) << " seconds to swim " << distance << "meters" << endl;
		cout << "Everything was executed!" << endl;
	} catch (double e_val) {
		cerr << "Caught exception of type double with value: " << e_val << endl;
	} catch (Swim_Exception e_val) {
		// in this example we don't do anything to fix the problem; instead, we wil just print the exception information
		cerr << "\nCaught exception: " << e_val.what() << endl;
	}
  
	cout << endl << endl;

	// demonstrate another try-catch block
	try {
		Animal &a_ref = m1;
		// the following dynamic cast is invalid and will result in the generation of an exception
		Sea_Otter &otter_ref = dynamic_cast<Sea_Otter &>(a_ref);
		otter_ref.make_noise(2);
	} catch (exception& e) {
		cerr << "\nCaught system exception while trying to cast a reference." << endl;
	}
  
	cout << "\n\n\nProgram finished\n\n\n" << endl;

	return 0;
}