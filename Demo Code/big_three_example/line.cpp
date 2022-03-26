#include <iostream>
#include "line.h"
using namespace std;

Line::Line() {
	cout << "\nLine default constructor called!" << endl;
	n_points = 2;
	points = new Point[n_points];
	points[n_points-1].set_location(1,1);
}

//setting the number of points
Line::Line(int n) {
	cout << "\nLine alternate constructor called!" << endl;
	n_points = n;
	points =  new Point[n_points];
	for (int i = 0; i < n; i++){
		points[i].set_location(i, i);
	}
}

Line::Line(int x1, int y1, int x2, int y2) {
	cout << "\nAnother Line alternate constructor called!" << endl;
	n_points = 2;
	points = new Point[n_points];
	points[0].set_location(x1, y1);
	points[1].set_location(x2, y2);
}

Line::Line(const Line& old_line) {
	cout << "\nLine copy constructor called!" << endl;
	n_points = old_line.n_points;
	points = new Point[n_points];
	for (int i = 0; i < n_points; i++) {
		points[i] = old_line.points[i];
	}
}

Line& Line::operator=(const Line& old_line) {
	if (this != &old_line) {
		cout << "\nLine assignment operator overload called!" << endl;
		delete [] points;
		
		n_points = old_line.n_points;
		points = new Point[n_points];
		for (int i = 0; i < n_points; i++) {
			points[i] = old_line.points[i];
		}
	}
  
	return *this;
}

void Line::print() {
	for (int i = 0; i < n_points; i++) {
		points[i].print();      // calls print() method from "point" class
	}
}

void Line::set_point(int n, Point& p) {
	points[n] = p;
}

Line::~Line(){
    delete[] points;
    cout << "\nLine destroyed!\n\n\n";
}