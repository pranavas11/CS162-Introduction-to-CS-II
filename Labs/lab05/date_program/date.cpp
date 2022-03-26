#include <iostream>
#include <cstdlib>
#include <string>
#include "date.h"
using namespace std;

Date::Date() {
	this->month = 1;
	this->day = 1;
	this->year = 2001;
}

Date::Date(int month, int day, int year) {
	this->month = month;
	this->day = day;
	this->year = year;
}

void Date::print_date1() {
	cout << "\nThe date is: " << month << "/" << day << "/" << year << endl;
}

void Date::print_date2() {
	if (month == 1) {
		cout << "\nThe date is: January " << day << ", " << year << endl << endl;
	} else if (month == 2) {
		cout << "\nThe date is: February " << day << ", " << year << endl << endl;
	} else if (month == 3) {
		cout << "\nThe date is: March " << day << ", " << year << endl << endl;
	} else if (month == 4) {
		cout << "\nThe date is: April " << day << ", " << year << endl << endl;
	} else if (month == 5) {
		cout << "\nThe date is: May " << day << ", " << year << endl << endl;
	} else if (month == 6) {
		cout << "\nThe date is: June " << day << ", " << year << endl << endl;
	} else if (month == 7) {
		cout << "\nThe date is: July " << day << ", " << year << endl << endl;
	} else if (month == 8) {
		cout << "\nThe date is: August " << day << ", " << year << endl << endl;
	} else if (month == 9) {
		cout << "\nThe date is: September " << day << ", " << year << endl << endl;
	} else if (month == 10) {
		cout << "\nThe date is: October " << day << ", " << year << endl << endl;
	} else if (month == 11) {
		cout << "\nThe date is: November " << day << ", " << year << endl << endl;
	} else {
		cout << "\nThe date is: December " << day << ", " << year << endl << endl;
	}
   
	//cout << "\nThe date is: " << month << " " << day << ", " << year << endl;
}