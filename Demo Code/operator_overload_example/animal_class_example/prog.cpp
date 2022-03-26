#include <iostream>
#include "animal.h"
#include "monkey.h"
using namespace std;

// Illustrate how to utilize inheritance

int main() {
	// demonstrate how functions work with different types of objects
	Animal a1("Generic Animal");
	Monkey m1("Curious George");

	// demonstrate the pre-increment and post-increment overloads
	cout << a1 << endl;
	cout << m1 << endl;

	cout << ++a1 << endl;
	cout << m1++ << endl;

	cout << a1 << endl;
	cout << m1 << endl;

	m1++;

	if (a1<10) cout << a1 << "\tanimal is young" << endl;
	else cout << a1 << "\tanimal is old" << endl;

	return 0;
}