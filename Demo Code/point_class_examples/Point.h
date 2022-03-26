#include <iostream>

#ifndef POINT_H
#define POINT_H

class Point {
public:
	Point();      // default constructor
	~Point();      // destructor
	Point(int, int);      // alternate constructor
	Point(const Point &);      // copy constructor
	Point& operator=(const Point&);      // assignment operator overload
  
  // class methods
	void move_right(int);
	void set_position(int, int);
	void print_position() const;
	int get_x();
  
  // member variable
	int mynum;

private:
	std::string* desc;
	int x;
  int y;
	int secret_value;
	void move_to_zero();
};

#endif