#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "Linked_List.h"
using namespace std;

// default constructor sets length to 0 and head to null
Linked_List::Linked_List() {
	this->length = 0;
	this->head = nullptr;
}

// copy constructor which does shallow copy of objects
Linked_List::Linked_List(const Linked_List& new_list) {
	this->length = new_list.length;
	this->head = new_list.head;
}

Linked_List& Linked_List::operator=(const Linked_List& new_list) {
	this->length = new_list.length;
	this->head = new_list.head;
	return *this;
}

int Linked_List::get_length() { return length; }

// generic print() function - prints sorted data at the end or unsorted data as elements are being added to the list
void Linked_List::print() {
	Node* current_value = head;
	
	int nodes_length = length;
	for (int i = 0; i < nodes_length; i++) {
		cout << current_value->value << " ";
		current_value = current_value->next;
	}
	cout << "\n";
}

// clear() frees up dynamically allocated memory - called in the destructor
void Linked_List::clear() {
	/*do {
		Node* current_value = head;
		for (int i = 0; i < length-1; i++) current_value = current_value->next;
		delete current_value->next;
		length--;
	} while (length == 0);*/

	delete head;
	this->head = nullptr;
	this->length = 0;
}

// inserts new elements at front of the list and returns incremented length
unsigned int Linked_List::push_front(int value) {
	Node* temp = head;
	head = new Node(value, temp);
	return ++length;
}

// inserts new elements at back of the list and returns incremented length
unsigned int Linked_List::push_back(int value) {
	if (this->head == nullptr) this->head = new Node(value);      // if head itself if empty, add new value to head
	else {
		Node* current_value = head;
		while (current_value->next != nullptr) {      // loop until the next value in the list is not empty
			current_value = current_value->next;      // set current value to the next value in the list in the loop
		}
		current_value->next = new Node(value);
	}
	return ++length;
}

/******************************************************************************************************
 * Function: insert()
 * Description: inserts new node at specified index
 * Parameters: int value, unsigned int index
 * Pre-Conditions: checks "index" position and if "index" is in valid range
 * Post-Conditions: returns value inserted at specified index along with the incremented length of list
 *****************************************************************************************************/
unsigned int Linked_List::insert(int value, unsigned int index) {
	if (index == 0) push_front(value);          // if index is at start of list, push value to the front
	else if(index == length) push_back(value);      // if index is at end of list, push value to the back
	else if (index < length || index > length) {
		cout << "\nError: specified index is out of bounds in the list!\n";
		return length;
	} else {
		Node* current_value = head;      // start from head of list
		for (unsigned int i = 0; i < index-1; i++) current_value = current_value->next;
		Node* temp = current_value->next;      // pointer points to the following element
		current_value->next = new Node(value, temp);      // insert new node with saved pointer
	}
	return ++length;
}

// Merge Sort Algorithm starts here
/*****************************************************************************************************************
 * Function: split_nodes()
 * Description: this functions allows us to repeatedly split the nodes in half in the list for sorting later
 * Parameters: Node* start, Node** first_half, Node** second_half
 * Pre-Conditions: iterates through all nodes in list until the end, and pointer repeatedly points to next values
 * Post-Conditions: returns divided list with all nodes separated from each other
 ****************************************************************************************************************/
void Linked_List::split_nodes(Node* start, Node** first_half, Node** second_half) {
	Node* node1 = start->next;
	Node* node2 = start;

	while (node1 != nullptr) {      // iterate until node1 reaches list end
		node1 = node1->next;          // advance node1 by 1
		if (node1 != nullptr) {      // if the current iteration didn't hit the end
			node1 = node1->next;      // increment node1 to point to next item
			node2 = node2->next;      // increment node2 to point to next item
		}
	}

	*first_half = start;      // set address of "first_half" to list start
	*second_half = node2->next;      // set address of "second_half" to node after node2
	node2->next = nullptr;          // split the list at the next node2 item
}

/*********************************************************************************
 * Function: merge_nodes_ascending_order()
 * Description: merges all nodes in ascending order one by one after sorting them
 * Parameters: Node* node1, Node* node2
 * Pre-Conditions: implements base cases before recursive function call
 * Post-Conditions: returns a sorted, merged list
 ********************************************************************************/
Node* Linked_List::merge_nodes_ascending_order(Node* node1, Node* node2) {
	Node* sorted_list = nullptr;      // initial sorted list is empty

	if (node1 == nullptr) return node2;          // base case 1
	else if (node2 == nullptr) return node1;      // base case 2

	if (node1->value <= node2->value) {      // compares two adjacent nodes (<= means ascending)
		sorted_list = node1;                  // add node1 to sorted list
		sorted_list->next = merge_nodes_ascending_order(node1->next, node2);      // recursively verify & add the next nodes in the list
	} else {
		sorted_list = node2;          // add node2 to sorted list
		sorted_list->next = merge_nodes_ascending_order(node1, node2->next);      // recursively verify & add the next nodes in the list
	}

	return sorted_list;
}

/**********************************************************************************
 * Function: merge_nodes_descending_order()
 * Description: merges all nodes in descending order one by one after sorting them
 * Parameters: Node* node1, Node* node2
 * Pre-Conditions: implements base cases before recursive function call
 * Post-Conditions: returns a sorted, merged list
 *********************************************************************************/
Node* Linked_List::merge_nodes_descending_order(Node* node1, Node* node2) {
	Node* sorted_list = nullptr;          // initial sorted list is empty

	if (node1 == nullptr) return node2;          // base case 1
	else if (node2 == nullptr) return node1;      // base case 2

	if (node1->value >= node2->value) {          // compares two adjacent nodes (>= means descending)
		sorted_list = node1;                  // add node1 to sorted list
		sorted_list->next = merge_nodes_descending_order(node1->next, node2);      // recursively verify & add the next nodes in the list
	} else {
		sorted_list = node2;              // add node2 to sorted list
		sorted_list->next = merge_nodes_descending_order(node1, node2->next);      // recursively verify & add the next nodes in the list
	}

	return sorted_list;
}

/******************************************************************************************************
 * Function: merge_sort()
 * Description: final implemention of merge sort - brings together all nodes sorted in the given order
 * Parameters: Node** node_begin, bool sorting_order
 * Pre-Conditions: implements base cases before recursive function call
 * Post-Conditions: returns the final sorted, merged list
 *****************************************************************************************************/
void Linked_List::merge_sort(Node** node_begin, bool sorting_order) {
	Node* begin = *node_begin;
	Node* node1;
	Node* node2;

	if(begin == nullptr || begin->next == nullptr) return;      // return if first or next value is empty

	split_nodes(begin, &node1, &node2);      // split nodes in list into halves
  
  // recursive calls for merge_sort() function
	merge_sort(&node1, sorting_order);
	merge_sort(&node2, sorting_order);
	
	if (sorting_order == true) *node_begin = merge_nodes_ascending_order(node1, node2);
	else *node_begin = merge_nodes_descending_order(node1, node2);
}

// Selection Sort Algorithm below
// this function swaps nodes in the list in descending order
void Linked_List::swap_nodes(Node** list_head, Node* current_x, Node* current_y, Node* previous_y) {
	*list_head = current_y;
	previous_y->next = current_x;

	Node* temp = current_y->next;
	current_y->next = current_x->next;
	current_x->next = temp;
}

/****************************************************************************************
 * Function: sort()
 * Description: sorts all nodes in the list in descending order
 * Parameters: Node* val
 * Pre-Conditions: iterates through the list to set minimums and sort in desceding order
 * Post-Conditions: returns a sorted list
 ***************************************************************************************/
Node* Linked_List::sort(Node* val) {
	if (val->next == nullptr) return val;      // return previous value if there's no next value
	Node* minimum_value = val;
	Node* previous_min = nullptr;
	Node* list_value;

	for (list_value = val; list_value->next != nullptr; list_value = list_value->next) {
		if (list_value->next->value > minimum_value->value) {      // if next list value is greater than current min value ...
			minimum_value = list_value->next;          // ... upadte current min value to next value in list
			previous_min = list_value;
		}
	}

	if (minimum_value != val) swap_nodes(&val, val, minimum_value, previous_min);      // swap nodes
	val->next = sort(val->next);      // recursive call to sort subsequent items in list

	return val;
}

// this functions returns the sorted list in descending order
void Linked_List::selection_sort(Node** list_head, bool sorting_order) {
	if (sorting_order == false) {
		if ((*list_head) == nullptr) return;
		*list_head = sort(*list_head);
	}
}

void Linked_List::sort_ascending() { merge_sort(&(head), true); }

void Linked_List::sort_descending() {
	merge_sort(&(head), false);
	//selection_sort(&(head), false);
}

// this function checks prime numbers in the list
bool Linked_List::check_primes(int num) {
	if (num <= 1) return false;
	for (int i = 2; i < num; i++) {      // primes start from 2
		if (num % i == 0) return false;      // if a factor is found, return false
	}
	return true;
}

// this functions counts the number of prime numbers in the list
int Linked_List::count_primes() {
  
  //      Method 1
	Node* node = head;          // start from the head of the list
  prime_count = 0;

  while (node) {      // loop through all nodes in the list
    if (check_primes(node->value)) prime_count++;      // increase prime count if a prime is found
    node = node->next;          // go the next item/node in the list
  }
  
  /*      Method 2
	if (length == 0) return 0;
	else if (length == 1 && check_primes(head->value)) return 1;
	
	prime_count = 0;
	Node* current_node = this->head;
	while (current_node != nullptr) {
		if (current_node->value >= 2 ) {
			prime_count += check_primes(current_node->value);
		}
		current_node = current_node->next;
	}*/
  
  /*      Method 3
	for (int i = 0; i < length ; i++) {
		if (current_node->value >= 2 ) {
			prime_count += check_primes(current_node->value);
		}
		current_node = current_node->next;
	}*/

	return prime_count;
}

// this function prints all prime numbers in the list (if there are any)
void Linked_List::print_primes() {
	int list_prime_count = count_primes();      // get the total prime count
  
	if (list_prime_count > 0) {
		Node* current_value = head;      // start at the head (first value) in the list
		int list_length = length;          // get list length
		for (int i = 0; i < list_length; i++) {
			if (check_primes(current_value->value) == true) {      // if current value is prime, print it
				cout << current_value->value << " ";
			}
			current_value = current_value->next;      // go the next node in the list
		}
		cout << "\n\n\n";
	} else {
		cout << "\nSorry, there are no primes in the linked list!\n\n\n";
	}
}

// Linked_List destructor frees up dynamically allocated memory
Linked_List::~Linked_List() {
	//cout << "\nLinked List destructor called!\n";
	clear();
}

/*                                                              Citations
 * “Merge Sort for Linked Lists.” GeeksforGeeks, 26 May 2021, www.geeksforgeeks.org/merge-sort-for-linked-list/.
 * “Recursive Selection Sort for Singly Linked List: Swapping Node Links.” GeeksforGeeks, 28 May 2021, www.geeksforgeeks.org/recursive-selection-sort-singly-linked-list-swapping-node-links/.
 * “List of Prime Numbers.” Wikipedia, Wikimedia Foundation, 7 May 2021, en.wikipedia.org/wiki/List_of_prime_numbers. 
*/