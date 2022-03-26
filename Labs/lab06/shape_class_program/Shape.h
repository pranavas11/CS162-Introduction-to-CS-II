#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Shape {
  private:
    string name;
    string color;

  public:
		Shape();
		Shape(string, string);

		void set_name(string);
		void set_color(string);
		string get_name();
		string get_color();
    float area();
};

#endif