#include <iostream>
#include "Person.h"
using namespace std;

void Person::setInfo(std::string newName, std::string newRole) {
	name = newName;
	role = newRole;
}

string Person::getName() const {
	return name;
}

string Person::getRole() const {
	return role;
}

bool Person::operator<(const Person& p2) const {
	if (this->name < p2.name) {
		return true;
	}
	return false;
}