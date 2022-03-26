#ifndef BOOK_H
#define BOOK_H

#include <iostream>

struct book {
	int pages;
	unsigned int pub_date;
	std::string title;
	unsigned int num_authors;
	std::string* authors;
};

// function prototypes
void print_book_info(book*);
book** create_2d_array(int, int);
void delete_book_array(book**, int);

#endif