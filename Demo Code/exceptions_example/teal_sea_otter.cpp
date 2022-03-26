#include <iostream>
#include "teal_sea_otter.h"
using namespace std;

Teal_Sea_Otter::Teal_Sea_Otter(string tmp) {
	name = tmp;
	maximum_length = 2;
}

Teal_Sea_Otter::Teal_Sea_Otter(string tmp, double speed) {
	name = tmp;
	maximum_length = 2;
	swim_speed = speed;
}

void Teal_Sea_Otter::make_noise(int num) {
	for (int i = 0; i < num; i++) cout << "Groank" << " ";
	cout << endl;	
}

void Teal_Sea_Otter::swim(int num) {
	cout << name << " is swimming like a dolphin for " << num << " meters." << endl;
}