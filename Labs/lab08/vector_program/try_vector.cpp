#include <iostream>
#include <vector>
#include "./vector.hpp"

//We do not want to include either statement. We wouldn't be able to compare our vector template to the Standard
//using std::vector;
//using namespace std;
using std::cout;
using std::endl;

int main() {
  vector<int> v;					// our vector class
  std::vector<int> stdv;	// standard vector

  v.push_back(23);	// compare operation of vector to std
  stdv.push_back(23);

	// invokes copy constructor
	vector<int> vcpy = v;
  std::vector<int> stdvcpy = stdv;

	//invokes assignment operator overload
  vector<int> vcpy2;
  std::vector<int> stdvcpy2;
  vcpy2 = vcpy;
  stdvcpy2 = stdvcpy;

  cout << "\n\n\nOur vector size: " << v.size() << endl;
  cout << "STL vector size: " << stdv.size() << endl;

	cout << "Copy of our vector size: " << vcpy.size() << endl;
  cout << "Copy of STL vector size: " << stdvcpy.size() << endl;

	cout << "Copy of our vector size with =: " << vcpy2.size() << endl;
  cout << "Copy of STL vector size with =: " << stdvcpy2.size() << endl;

	vcpy.push_back(15);
  cout << "Pushed back 15 onto vector copy. Element: " << vcpy[1] << endl;
  vcpy2.push_back(55);
  cout << "Pushed back 55 onto second copy of vector -> vcpy(2).at(1) = " << vcpy2.at(1) << "\n\n\n";

  return 0;
}