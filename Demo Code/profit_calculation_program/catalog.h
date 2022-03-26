#ifndef CATALOG_H
#define CATALOG_H

#include <iostream>
#include <fstream>

struct Produce {
	std::string name;
	double price;
	int plu;
	std::string size;
};

// function prototypes
int get_num_entries(std::ifstream &);
Produce* parse_produce(std::ifstream &, int);
double compute_profit(Produce *, int);
void sort_items(Produce *, int);
void deallocate_array(Produce *);

#endif