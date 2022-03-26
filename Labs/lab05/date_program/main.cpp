#include <iostream>
#include <cstdlib>
#include <string>
#include "date.h"
using namespace std;

int main() {
  Date date1;
	Date date2(3, 15, 2021);

	date1.print_date1();
	date1.print_date2();
	date2.print_date1();
	date2.print_date2();

	return 0;
}