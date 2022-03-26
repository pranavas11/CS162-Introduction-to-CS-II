#include <iostream>
#include "point.h"

using namespace std;

int main(){
	Point p1;
	p1.print_point();
	Point p2(112,7);
	p2.print_point();
	Point p3(7);
	p3.print_point();
	return 0;
}