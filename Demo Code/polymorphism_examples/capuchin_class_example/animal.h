/*
	Animal Class
*/
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using namespace std;

class Animal {
public:
	Animal();
	Animal(string);
	Animal(string, int);
	Animal& operator++(); // pre-increment
	virtual string get_name() const;
	int get_age() const;
	virtual void make_noise(int);

private:
	string name;

protected:
	int age;

};

ostream& operator<<(ostream& out, const Animal& a);

#endif