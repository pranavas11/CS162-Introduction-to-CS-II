#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Rectangle.h"
using namespace std;

class Square : public Rectangle
{
  public:
		Square();
		Square(float);
};

#endif