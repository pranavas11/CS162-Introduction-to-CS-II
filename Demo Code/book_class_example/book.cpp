#include <iostream>
#include "book.h"
using namespace std;

// simple function to print the book info
void print_book_info(book* bk) {
	cout << "\n\n\nBook title is: " << (*bk).title << endl;
	cout << "\nIt has " << bk->pages << " pages and was published in " << bk-> pub_date << "." << endl;
	cout << "\nThe author(s) are:" << endl;
	for (unsigned int i = 0; i < bk->num_authors; i++) {
		cout << bk->authors[i] << endl;
	}
	cout << endl << endl << endl;
}

// function that returns a pointer to a 2D array of books
book** create_2d_array(int rows, int cols) {
	book** book_array = new book*[rows];
	for (int i = 0; i < rows; i++) {
		book_array[i] = new book[cols];
	}
	return book_array;
}

void delete_book_array(book** bk, int n) {
  for (int i = 0; i < n; i++) {
    delete[] bk[i];
  }
  delete[] bk;
}