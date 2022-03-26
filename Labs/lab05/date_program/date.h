#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Date {
  private:
    int month;
    int day;
		int year;

  public:
    Date();
    Date(int, int, int);

    void print_date1();
    void print_date2();
};

#endif