#ifndef TEAL_SEA_OTTER_H
#define TEAL_SEA_OTTER_H

#include <iostream>
#include "sea_otter.h"
using namespace std;

class Teal_Sea_Otter : public Sea_Otter {
public:
	Teal_Sea_Otter(string);
	Teal_Sea_Otter(string, double);
  
	void make_noise(int) override;
	void swim(int) override;
};

#endif