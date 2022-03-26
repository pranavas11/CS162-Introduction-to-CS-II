#ifndef CAPUCHIN_H
#define CAPUCHIN_H

#include <iostream>
#include "monkey.h"
#include "animal.h"

using namespace std;

class Capuchin : public Monkey {
	public:
		Capuchin(string name);
		string get_name();
		void make_noise(int);
		//void move_forward(int);

	private:
		int size;
}; 
#endif