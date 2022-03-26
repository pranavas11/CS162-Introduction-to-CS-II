#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "Node.h"
using namespace std;

// Node default constructor sets initial default values for member variables
Node::Node() {
	this->value = 0;
	this->next = nullptr;
}

// parameterized constructor initializes "value" member variable
Node::Node(int val) {
	this->value = val;
	this->next = nullptr;
}

// alternate (parameterized) construcor initializes "value" and "next" member variables
Node::Node(int val, Node* nxt_ptr) {
	this->value = val;
	this->next = nxt_ptr;
}

// copy constructor which does shallow copy of objects
Node::Node(const Node& new_node) {
	this->value = new_node.value;
	this->next = new_node.next;
}

Node& Node::operator=(const Node& new_node) {
	this->value = new_node.value;
	this->next = new_node.next;
	return *this;
}

// Node destructor frees up dynamically allocated memory when called in Linked_List class
Node::~Node() {
	// cout << "\nNode destructor called!\n";
	delete next;
  next = nullptr;      // next is a pointer var, so it should be set to NULL after deleting the "next" value so it doesn't point to garbage
}