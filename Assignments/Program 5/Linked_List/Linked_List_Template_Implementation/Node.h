#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

template<typename T>
class Node {
	public:
  	T value;          // the value that this node stores
  	Node<T>* next;      // a pointer to the next node in the list

  	Node();          // default constructor
    
    // parameterized constructors
  	Node(int val);
  	Node(int val, Node* nxt_ptr);
    Node(const Node& new_node);
		Node& operator=(const Node& new_node);

  	~Node();          // destructor
};

// Node default constructor sets initial default values for member variables
template<typename T>
Node<T>::Node() {
  this->value = 0;
  this->next = nullptr;
}

// alternate (parameterized) construcor initializes "value" member variable
template<typename T>
Node<T>::Node(int val) {
  this->value = val;
  this->next = nullptr;
}

// alternate (parameterized) construcor initializes "value" and "next" member variables
template<typename T>
Node<T>::Node(int val, Node* nxt_ptr) {
  this->value = val;
  this->next = nxt_ptr;
}

// copy constructor
template<typename T>
Node<T>::Node(const Node& new_node) {
  this->value = new_node.value;
	this->next = new_node.next;
}

template<typename T>
Node<T>& Node<T>::operator=(const Node& new_node) {
  this->value = new_node.value;
	this->next = new_node.next;
	return *this;
}

// Node destructor frees up dynamically allocated memory when called in Linked_List class
template<typename T>
Node<T>::~Node() {
  // cout << "\nNode destructor called!\n";
  delete next;
  // next is a pointer var, so it should be set to NULL after deleting the "next" value so it doesn't point to garbage
  next = nullptr;
}

#endif