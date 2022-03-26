#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
using namespace std;

template<typename T>
class LinkedList {
	private:
    unsigned int length;      // the number of nodes contained in the list
    Node<T>* head;              // a pointer to the first node in the list
    int prime_count;

  public:
    LinkedList();          // default constructor
    LinkedList(const LinkedList& new_list);
		LinkedList& operator=(const LinkedList& new_list);

    int get_length();
    // note: there is no set_length(unsigned int) - you cannot set the length when you don't know number of nodes that will be added
    
    void print();          // output a list of all integers contained within the list
  	void clear();          // delete the entire list (remove all nodes and reset length to 0)

    unsigned int push_front(T value);      // insert a new value at the front of the list (returns new length of the list)
  	unsigned int push_back(T value);      // insert a new value at the back of the list (returns new length of the list)
    
    // insert a new value in the list at the specified index (returns the new length of the list)
    unsigned int insert(T value, T index);
    
    // merge sort functions
    void split_nodes(Node<T>* start, Node<T>** first_half, Node<T>** second_half);
    Node<T>* merge_nodes_ascending_order(Node<T>* node1, Node<T>* node2);
    Node<T>* merge_nodes_descending_order(Node<T>* node1, Node<T>* node2);
    void merge_sort(Node<T>** node_begin, bool sorting_order);

    // selection sort functions
    void swap_nodes(Node<T>** list_head, Node<T>* current_x, Node<T>* current_y, Node<T>* previous_y);
    Node<T>* sort(Node<T>* val);
    void selection_sort(Node<T>** list_head, bool sorting_order);
    
    void sort_ascending();      // sort the nodes in ascending order - implements the recursive Merge Sort algorithm
  	void sort_descending();      // sort nodes in descending order - implements the recursive Merge Sort algorithm

    bool check_primes(T num);
    int count_primes();
    void print_primes();

		~LinkedList();              // destructor
};

// default constructor sets length to 0 and head to null
template<typename T>
LinkedList<T>::LinkedList() {
  this->length = 0;
  this->head = nullptr;
}

// copy constructor
template<typename T>
LinkedList<T>::LinkedList(const LinkedList& new_list) {
  this->length = new_list.length;
  this->head = new_list.head;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& new_list) {
  this->length = new_list.length;
  this->head = new_list.head;
	return *this;
}

template<typename T>
int LinkedList<T>::get_length() { return length; }

// generic print() function - prints sorted data at the end or unsorted data as elements are being added to the list
template<typename T>
void LinkedList<T>::print() {
  Node<T>* current_value = head;
  int nodes_length = length;
  for (int i = 0; i < nodes_length; i++) {
    cout << current_value->value << " ";
    current_value = current_value->next;
  }
  cout << "\n";
}

// clear() frees up dynamically allocated memory - called in the destructor
template<typename T>
void LinkedList<T>::clear() {
  delete head;
  this->head = nullptr;
  this->length = 0;
}

// inserts new elements at front of the list and returns incremented length
template<typename T>
unsigned int LinkedList<T>::push_front(T value) {
  Node<T>* temp = head;
  head = new Node<T>(value, temp);
  return ++length;
}

// inserts new elements at back of the list and returns incremented length
template<typename T>
unsigned int LinkedList<T>::push_back(T value) {
  if (this->head == nullptr) this->head = new Node<T>(value);
  else {
    Node<T>* current_value = head;
    while (current_value->next != nullptr) {
      current_value = current_value->next;
    }
    current_value->next = new Node<T>(value);
  }
  return ++length;
}

/******************************************************************************************************
 * Function: insert()
 * Description: inserts new node at specified index
 * Parameters: T value, T index
 * Pre-Conditions: checks "index" position and if "index" is in valid range
 * Post-Conditions: returns value inserted at specified index along with the incremented length of list
 *****************************************************************************************************/
template<typename T>
unsigned int LinkedList<T>::insert(T value, T index) {
  if (index == 0) push_front(value);
  else if(index == length) push_back(value);
  else if (index < length || index > length) {
    cout << "\nError: specified index is out of bounds in the list!\n";
    return length;
  } else {
    Node<T>* current_value = head;
    for (unsigned int i = 0; i < index-1; i++) current_value = current_value->next;
    Node<T>* temp = current_value->next;
    current_value->next = new Node<T>(value, temp);
  }
  return ++length;
}

// Merge Sort Algorithm starts here
/*****************************************************************************************************************
 * Function: split_nodes()
 * Description: this functions allows us to repeatedly split the nodes in half in the list for sorting later
 * Parameters: Node<T>* start, Node<T>** first_half, Node<T>** second_half
 * Pre-Conditions: iterates through all nodes in list until the end, and pointer repeatedly points to next values
 * Post-Conditions: returns divided list with all nodes separated from each other
 ****************************************************************************************************************/
template<typename T>
void LinkedList<T>::split_nodes(Node<T>* start, Node<T>** first_half, Node<T>** second_half) {
  Node<T>* node1 = start->next;
  Node<T>* node2 = start;

  while (node1 != nullptr) {
    node1 = node1->next;
    if (node1 != nullptr) {
      node1 = node1->next;
      node2 = node2->next;
    }
  }

  *first_half = start;
  *second_half = node2->next;
  node2->next = nullptr;
}

/*********************************************************************************
 * Function: merge_nodes_ascending_order()
 * Description: merges all nodes in ascending order one by one after sorting them
 * Parameters: Node<T>* node1, Node<T>* node2
 * Pre-Conditions: implements base cases before recursive function call
 * Post-Conditions: returns a sorted, merged list
 ********************************************************************************/
template<typename T>
Node<T>* LinkedList<T>::merge_nodes_ascending_order(Node<T>* node1, Node<T>* node2) {
  Node<T>* sorted_list = nullptr;

  if (node1 == nullptr) return node2;
  else if (node2 == nullptr) return node1;

  if (node1->value <= node2->value) {
    sorted_list = node1;
    sorted_list->next = merge_nodes_ascending_order(node1->next, node2);
  } else {
    sorted_list = node2;
    sorted_list->next = merge_nodes_ascending_order(node1, node2->next);
  }

  return sorted_list;
}

/**********************************************************************************
 * Function: merge_nodes_descending_order()
 * Description: merges all nodes in descending order one by one after sorting them
 * Parameters: Node<T>* node1, Node<T>* node2
 * Pre-Conditions: implements base cases before recursive function call
 * Post-Conditions: returns a sorted, merged list
 *********************************************************************************/
template<typename T>
Node<T>* LinkedList<T>::merge_nodes_descending_order(Node<T>* node1, Node<T>* node2) {
  Node<T>* sorted_list = nullptr;

  if (node1 == nullptr) return node2;
  else if (node2 == nullptr) return node1;

  if (node1->value >= node2->value) {
    sorted_list = node1;
    sorted_list->next = merge_nodes_descending_order(node1->next, node2);
  } else {
    sorted_list = node2;
    sorted_list->next = merge_nodes_descending_order(node1, node2->next);
  }

  return sorted_list;
}

/******************************************************************************************************
 * Function: merge_sort()
 * Description: final implemention of merge sort - brings together all nodes sorted in the given order
 * Parameters: Node<T>** node_begin, bool sorting_order
 * Pre-Conditions: implements base cases before recursive function call
 * Post-Conditions: returns the final sorted, merged list
 *****************************************************************************************************/
template<typename T>
void LinkedList<T>::merge_sort(Node<T>** node_begin, bool sorting_order) {
  Node<T>* begin = *node_begin;
  Node<T>* node1;
  Node<T>* node2;

  if(begin == nullptr || begin->next == nullptr) return;

  split_nodes(begin, &node1, &node2);
  merge_sort(&node1, sorting_order);
  merge_sort(&node2, sorting_order);

  if (sorting_order == true) *node_begin = merge_nodes_ascending_order(node1, node2);
  else *node_begin = merge_nodes_descending_order(node1, node2);
}

// Selection Sort Algorithm below
// this function swaps nodes in the list in descending order
template<typename T>
void LinkedList<T>::swap_nodes(Node<T>** list_head, Node<T>* current_x, Node<T>* current_y, Node<T>* previous_y) {
  *list_head = current_y;
  previous_y->next = current_x;

  Node<T>* temp = current_y->next;
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
template<typename T>
Node<T>* LinkedList<T>::sort(Node<T>* val) {
  if (val->next == nullptr) return val;
  Node<T>* minimum_value = val;
  Node<T>* previous_min = nullptr;
  Node<T>* list_value;

  for (list_value = val; list_value->next != nullptr; list_value = list_value->next) {
    if (list_value->next->value > minimum_value->value) {
      minimum_value = list_value->next;
      previous_min = list_value;
    }
  }

  if (minimum_value != val) swap_nodes(&val, val, minimum_value, previous_min);
  val->next = sort(val->next);

  return val;
}

// this functions returns the sorted list in descending order
template<typename T>
void LinkedList<T>::selection_sort(Node<T>** list_head, bool sorting_order) {
  if (sorting_order == false) {
    if ((*list_head) == nullptr) return;
    *list_head = sort(*list_head);
  }
}

template<typename T>
void LinkedList<T>::sort_ascending() {
  merge_sort(&(head), true);
}

template<typename T>
void LinkedList<T>::sort_descending() {
  //merge_sort(&(head), false);
  selection_sort(&(head), false);
}

// this function checks prime numbers in the list
template<typename T>
bool LinkedList<T>::check_primes(T num) {
  if (num <= 1) return false;
  for (T i = 2; i < num; i++) {
    if (num % i == 0) return false;
  }
  return true;
}

// this functions counts the number of prime numbers in the list
template<typename T>
int LinkedList<T>::count_primes() {
  Node<T>* node = head;
  prime_count = 0;

  while (node) {
    if (check_primes(node->value)) prime_count++;
    node = node->next;
  }

  return prime_count;
}

// this function prints all prime numbers in the list (if there are any)
template<typename T>
void LinkedList<T>::print_primes() {
  int list_prime_count = count_primes();
  if (list_prime_count > 0) {
    Node<T>* current_value = head;
    int nodes_length = length;
    for (int i = 0; i < nodes_length; i++) {
      if (check_primes(current_value->value) == true) {
        cout << current_value->value << " ";
      }
      current_value = current_value->next;
    }
    cout << "\n\n\n";
  } else {
    cout << "\nSorry, there are no primes in the linked list!\n\n\n";
  }
}

// Linked_List destructor frees up dynamically allocated memory
template<typename T>
LinkedList<T>::~LinkedList() {			// destructor
  //cout << "\nLinked List destructor called!\n";
  clear();
}

/*                                                              Citations
 * “Merge Sort for Linked Lists.” GeeksforGeeks, 26 May 2021, www.geeksforgeeks.org/merge-sort-for-linked-list/.
 * “Recursive Selection Sort for Singly Linked List: Swapping Node Links.” GeeksforGeeks, 28 May 2021, www.geeksforgeeks.org/recursive-selection-sort-singly-linked-list-swapping-node-links/.
 * “List of Prime Numbers.” Wikipedia, Wikimedia Foundation, 7 May 2021, en.wikipedia.org/wiki/List_of_prime_numbers. 
*/

#endif