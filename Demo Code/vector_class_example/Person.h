#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person {
public:
	void setInfo(std::string, std::string);
	std::string getName() const;
	std::string getRole() const;
  // operator overload function
	bool operator<(const Person& p2) const;

private:
	std::string name;
	std::string role;
};

#endif