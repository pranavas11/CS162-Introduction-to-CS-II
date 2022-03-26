#ifndef BOOK_H
#define BOOK_H

#include <iostream>

struct book {
	int pages;
	unsigned int pub_date, num_authors;
	std::string title;
	std::string* authors;
};

// function prototypes
void print_book_info(book*);
book** create_2d_array(int, int);

#endif