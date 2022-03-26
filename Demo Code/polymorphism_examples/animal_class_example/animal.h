/*
	Animal Class
*/
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
public:
	Animal(); // default constructor
	Animal(std::string, int); // alternate constructor
	~Animal(); // destructor
	 std::string get_name();
	virtual void make_noise();

protected:
	std::string name;
	int age;
	int location;

};
#endif
