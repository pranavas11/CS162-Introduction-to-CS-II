#ifndef NODE_H
#define NODE_H

class Node {
	public:
		int value;          // the value that this node stores
  	Node* next;          // a pointer to the next node in the list

		Node();          // default constructor
		// parameterized constructors
		Node(int);
		Node(int, Node*);
    Node(const Node&);                  // copy constructor
		Node& operator=(const Node&);      // assignment operator overload
		
		~Node();          // destructor
};

#endif