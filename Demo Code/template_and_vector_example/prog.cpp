#include <iostream>
#include <vector>
#include "custom_array.hpp"
#include "room.h"

// for historical reasons the first line below can also be written as: template <class T>
template <typename T>
const T& minimum(const T& x, const T& y) {
	// check to see which value is smaller
	if (x < y) return x;
	else return y;
}

int main() {
	// simple vector example
	// allocate a vector containing 10 ints, with each int initialized to a value of 2
	vector<int> v(10, 2);
	cout << "\n\n\nSize: " << v.size() << endl;
	cout << "Capacity: " << v.capacity() << endl;
  
	// add an additional int to the vector
	v.push_back(7);
	cout << "\nAfter pushing back element 7:\nSize: " << v.size() << endl;
	cout << "Capacity: " << v.capacity() << endl << endl << endl;

	// demonstrate how to access the vector using array notation (square brackets)
	for (unsigned int i = 0; i < v.size(); i++) {
		cout << "Initial value at index " << i << ": " << v[i];
		v[i] = i;
		cout << ", changed to: " << v[i] << endl;
	}

  cout << "\n\n\n";

	// more complicated vector example
	int square_size = 3; // length of one side
	// create a 2D vector of the requested size
	vector<vector<Room>> cave(square_size, vector<Room>(square_size));

	// now the individual rooms within the cave can be accessed as cave[0][0], cave[0][1], ... , cave[3][2], cave[3][3]
	for (int i = 0; i < square_size; i++) {
		for (int j = 0; j < square_size; j++) {
			// this shows how to call a member function of the Room
			cout << cave[i][j].get_name() << endl;
		}
	}

	// illustrate how to use the template function that we declared at the top of this file
	int i = minimum(3, 9); // returns 3
	cout << "\n\n\nminimum(3, 9) is: " << i << '\n';

	double d = minimum(3.14, 2.718);      // returns 2.718
	cout << "minimum(3.14, 2.718) is: " << d << '\n';

	// lastly, let's use the template class that was defined in custom_array.hpp
	// https://www.learncpp.com/cpp-tutorial/133-template-classes/
	// the class is named custom_array
	// instantiate a new instance with 14 elements
	Custom_Array<double> tmp(14);
	for (int i = 0; i < tmp.getLength(); i++) {
		tmp[i] = i*2.0;
	}
  
	cout << "\nValue of tmp at index 4 is: " << tmp[4] << "\n\n\n";

	return 0;
}