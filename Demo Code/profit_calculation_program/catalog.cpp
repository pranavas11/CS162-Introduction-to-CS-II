#include <iostream>
#include <fstream>
#include "catalog.h"
using namespace std;

// read the file and parse the top line (we read the text as a string and then convert the string into an integer)
int get_num_entries(ifstream& fin) {
	string topline;
	fin >> topline;
	return stoi(topline);
}

// parse the file and return a pointer to an array of produce
Produce* parse_produce(ifstream& fin, int num) {
	// create an array of Produce
	Produce* items = new Produce[num];
	for (int i = 0; i < num; i++) {
		fin >> items[i].name >> items[i].price >> items[i].plu >> items[i].size;
		//cout << items[i].name << ',' << items[i].price << ',' << items[i].plu << ',' << items[i].size << endl;
	}
	return items;
}


// determine the incoming cash flow
double compute_profit(Produce * ptr, int num) {
  int num_sold;
	double total_income = 0.0, cur_income;

	for (int i = 0; i < num; i++) {
		cout << "\nHow many " << ptr[i].name << "s did you sell today? ";
		cin >> num_sold;
		cur_income = num_sold * ptr[i].price;
		total_income += cur_income;
	}

	return total_income;
}

// sort by name
void sort_items(Produce * arr, int num) {
	int i, j;
	for (i = 0; i < num-1; i++) {
		for (j = 0; j < num-i-1; j++) {
			if (arr[j].name > arr[j+1].name) {
				// swap the elements
				Produce tmp;
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

// function to free the dynamic memory
void deallocate_array(Produce * ptr) {
	delete [] ptr;
}