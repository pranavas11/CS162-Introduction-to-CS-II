#include <iostream>
#include <cstdlib>
#include "Person.h"
using namespace std;

void Person::setInfo(std::string newName, std::string newRole) {
	name = newName;
	role = newRole;
}

string Person::getName() {
	return name;
}

string Person::getRole() {
	return role;
}