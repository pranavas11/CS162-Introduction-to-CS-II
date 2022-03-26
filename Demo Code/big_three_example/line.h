#ifndef LINE_H
#define LINE_H

#include "point.h"

class Line {
	private:
		int n_points;
		Point* points;
  
	public:
		void set_point(int, Point&);
		void print();

		Line();          // default constructor
		Line(int);      // alternate constructor 1
		Line(int, int, int, int);      // alternate constructor 2
    
    Line(const Line&);
    Line& operator=(const Line&);
    ~Line();

};

#endif