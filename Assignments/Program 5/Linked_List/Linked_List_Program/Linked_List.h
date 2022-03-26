#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
using namespace std;

class Linked_List {
	private:
  	unsigned int length;          // the number of nodes contained in the list
  	Node* head;              // a pointer to the first node in the list
		int prime_count;
		
	public:
		Linked_List();                      // default constructor
    Linked_List(const Linked_List&);                  // copy constructor
		Linked_List& operator=(const Linked_List&);      // assignment operator overload

  	int get_length();
		// note: there is no set_length(unsigned int) - the reasoning should be intuitive
    
  	void print();      // output a list of all integers contained within the list
  	void clear();      // delete the entire list (remove all nodes and reset length to 0)

  	unsigned int push_front(int);      // insert a new value at the front of the list (returns new length of the list)
  	unsigned int push_back(int);      // insert a new value at the back of the list (returns new length of the list)
  	unsigned int insert(int value, unsigned int index);      // insert a new value in the list at the specified index (returns the new length of the list)
    
    // merge sort functions
		void split_nodes(Node*, Node**, Node**);
		Node* merge_nodes_ascending_order(Node*, Node*);
		Node* merge_nodes_descending_order(Node*, Node*);
		void merge_sort(Node**, bool);

		// selection sort functions
		void swap_nodes(Node**, Node*, Node*, Node*);
		Node* sort(Node*);
		void selection_sort(Node**, bool);
    
    void sort_ascending();      // sort the nodes in ascending order - implements the recursive Merge Sort algorithm
  	void sort_descending();      // sort nodes in descending order - implements the recursive Merge Sort algorithm

		bool check_primes(int);
		int count_primes();
		void print_primes();

		~Linked_List();          // destructor
};

#endif