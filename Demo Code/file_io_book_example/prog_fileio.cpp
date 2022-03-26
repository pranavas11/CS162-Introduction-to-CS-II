#include <iostream>
#include <fstream>
#include "book.h"
using namespace std;

/*********************************************
  Demonstrates the basics of file input/output
*********************************************/
int main() {
	// read book information from file
	ifstream fin;
	fin.open("book.txt");
	if (!fin.is_open()) {
		cerr << "Error, unable to open file!" << endl;
		return 1;
	}

	// create a statically allocated book struct
	book bk1;
  
	// read information from a file into a struct
	string tmp_string;
  
	getline(fin, tmp_string, ',');
	bk1.title =	tmp_string;
  
	getline(fin, tmp_string, ',');
	bk1.pub_date = stoi(tmp_string);
  
	getline(fin, tmp_string, ',');
	bk1.num_authors = stoi(tmp_string);
  
	bk1.authors = new string[bk1.num_authors];
	for (unsigned int i = 0; i < bk1.num_authors; i++) {
		getline(fin, tmp_string, ',');
		bk1.authors[i] = tmp_string;
	}
  
	getline(fin, tmp_string, ',');
	bk1.pages = stoi(tmp_string);
  
	fin.ignore();
	fin.close();

	// example of file output
	string output_file = "book_stats.txt";
	ofstream fout;
	fout.open(output_file.c_str(), ios::out | ios::trunc);
  
	if (!fout.is_open()) {
		cerr << "Error, unable to open file for output!" << endl;
		return 1;
	}

	fout << "Hello world!"<< " " << 125 << endl;

	fout.close();

	print_book_info(&bk1);

	// remember to clean up the dynamic memory usage
  delete [] bk1.authors;
  
	return 0;
}