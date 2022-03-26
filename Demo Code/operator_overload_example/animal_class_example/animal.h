/*
	Animal Class
*/
#ifndef ANIMAL_H
#define ANIMAL_H

using namespace std;

class Animal {
public:
	Animal();
	Animal(string);
	Animal(string, int);
	Animal& operator++(); // pre-increment
	Animal operator++(int); // post-increment
	string get_name() const;
	int get_age() const;

private:
	string name;

protected:
	int age;
};

bool operator<(const Animal& a1, const Animal& a2);
bool operator>(const Animal& a1, const Animal& a2);
bool operator<(const Animal& a, int age);
ostream& operator<<(ostream& out, const Animal& a); 

#endif