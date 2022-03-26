#include <iostream>
#include <stdlib.h>
#include "point.h"
#include "line.h"
using namespace std;

void print_info(const Point& p){
	//p.set_location(35,79);
	cout << p.get_x() << " " << p.get_y() << endl;
}

int main(){
  /* Point p1;
	Point p2(53, 9);
	Point p3(17);

	Point p4 = p2;
	p2 = p4;
  */
  
	Line l1;
  cout << "L1" << endl;
	l1.print();
  
	Line l2(3);
	cout << "L2" << endl;
	l2.print();

	l1 = l2;
	cout << "L1 = L2\n\n\n";
   
	Point p5(113, 7);
	l1.print();
	l2.set_point(0, p5);

	cout << "\nL1" << endl;
	l1.print();
  
	cout << "L2" << endl;
	l2.print();

	return 0;
}