/*
	Sea Otter Class
*/
#include <iostream>
#include "sea_otter.h"

using namespace std;

// predict the time to swim a certain distance
double Sea_Otter::predict_swim_time(int distance) {
	return distance/swim_speed;
}
