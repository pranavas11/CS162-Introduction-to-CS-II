#include <iostream>
#include <cstdlib>
#include <fstream>
#include "catalog.h"
using namespace std;

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cout << "\nPlease enter produce.txt as the second CLI argument for the filename.\n\n\n";
		return 0;
	}
  
	string file = argv[1];
	cout << "\n\n\nFilename: " << file << endl;

	ifstream fin;
	fin.open(file);

	int num_of_entries = get_num_entries(fin);
	cout << "\nNumber of objects in file: " << num_of_entries << "\n\n\n";

	Produce* items = parse_produce(fin, num_of_entries);
	sort_items(items, num_of_entries);

	double profit = compute_profit(items, num_of_entries);
	cout << "\n\n\nYour total incoming cash was: $" << profit << "\n\n\n";
  
	deallocate_array(items);

	return 0;
}