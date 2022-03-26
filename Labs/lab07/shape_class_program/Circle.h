#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Shape.h"
using namespace std;

class Circle : public Shape {
  private:
    float radius;

  public:
		Circle();
		Circle(float);
		float get_radius();
		float area() const override;
};

#endif