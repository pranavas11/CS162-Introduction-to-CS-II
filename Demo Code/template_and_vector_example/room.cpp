#include <iostream>
#include "room.h"
using namespace std;

Room::Room() { name = "Empty room"; }

Room::Room(string name) : name(name) {}

string Room::get_name() { return name; }