#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Shape.h"
using namespace std;

class Rectangle : public Shape {
  private:
    float width;
    float height;

  public:
		Rectangle();
		Rectangle(float, float);

		float get_width();
		float get_height();
		
		virtual float area() const override;

		// comparison operator overload functions
		bool operator > (const Rectangle &);	// overloads > symbol
		bool operator < (const Rectangle &);	// overloads < symbol
};

#endif