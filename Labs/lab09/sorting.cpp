#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <ctime>
using namespace std;

int get_int(string prompt) {
  int num = 0;
  for (unsigned int i = 0; i < prompt.length(); i++) {
    if (prompt[i] > 47 && prompt[i] <= 57) {	// checks if numbers are between 0-9
      num = num * 10 + (int(prompt[i] - 48));	// num = (0 * 10) + (integer value of character - 48)) to return num
    } else {
      return -1;
    }
  }
  return num;
}

void swap(int &a, int &b) {	//swap contents of a and b
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void selection_sort(int* arr, int arr_length) {
	int small_element, temp;
	for (int i = 0; i < arr_length-1; i++) {
		small_element = i;
		for (int j = i+1; j < arr_length; j++) {
			if (arr[j] < arr[small_element]) small_element = j;
		}
		temp = arr[small_element];			// Method 1
		arr[small_element] = arr[i];
		arr[i] = temp;

		//swap(arr[i], arr[small_element]);			// Method 2
	}
}

bool check_primes(int num) {
	if (num == 1) return false;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void print_primes(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		if (check_primes(arr[i]) == true) cout << arr[i] << " ";
	}
}

int main() {
	srand(time(NULL));
	
	int array_length;
	string arr_len;

  cout << "\n\n\nEnter the length of the array (1-25) to be sorted: ";
	while (true) {
		cin >> arr_len;
		array_length = get_int(arr_len);
		if (array_length == -1 || array_length < 1 || array_length > 25) {
			cout << "\nInvalid input! Please select a number between 1 and 25: ";
      cin.clear();
      cin.ignore(256, '\n');
    } else {
      cin.clear();
      cin.ignore(256, '\n');
      break;
    }
	}

	int* arr = new int[array_length];
	int* copy_arr = new int[array_length];
	cout << "\n\n\nUnsorted array:\n";
	for (int i = 0; i < array_length; i++) {
		arr[i] = (rand() % 100) + 1;
		cout << arr[i] << " ";
		copy_arr[i] = arr[i];
	}

	selection_sort(copy_arr, array_length);
	cout << "\n\n\nSorted array (in ascending order):\n";
	for (int i = 0; i < array_length; i++) cout << copy_arr[i] << " ";

	cout << "\n\n\nList of Prime Numbers:\n";
	print_primes(copy_arr, array_length);
	cout << "\n\n\n";

	delete [] arr;
	delete [] copy_arr;

	return 0;
}