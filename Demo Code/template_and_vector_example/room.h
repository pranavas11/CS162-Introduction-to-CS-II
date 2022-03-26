#ifndef ROOM_H
#define ROOM_H

#include <iostream>
using namespace std;

class Room {
public:
	Room();
	Room(string name);
	string get_name();

private:
	string name, volume;
};

#endif