#include <iostream>

#ifndef PERSON_H
#define PERSON_H

class Person {
public:
	void setInfo(std::string, std::string);
	std::string getName();
	std::string getRole();

private:
	std::string name;
	std::string role;
};

#endif