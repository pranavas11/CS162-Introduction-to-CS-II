#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "student_database.h"
using namespace std;

student* create_student_db(int n) {
  student* arr = new student[n];
  return arr;
}

void populate_array(student* person, int n, fstream& fin) {
  for(int i = 0; i < n; i++) {
		fin >> person[i].id_number;
		fin >> person[i].firstName;
		fin >> person[i].lastName;
		fin >> person[i].major;
	}
}

void sort_by_id(student* person, int n) {
  student temp;
  for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i-1; j++) {
      if (person[j].id_number > person[j+1].id_number) {
        temp = person[j];
        person[j] = person[j+1];
        person[j+1] = temp;
      }
    }
  }
}

void sort_by_lastname(student* person, int n) {
  student temp;
  for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i-1; j++) {
      if (person[j].lastName.compare(person[j+1].lastName) > 0) {
				temp = person[j];
        person[j] = person[j+1];
        person[j+1] = temp;
      }
    }
	}
}

void get_student_db_info(student* person, int n, fstream& fout) {
  for (int i = 0; i < n; i++) {
    fout << person[i].id_number << "\n";
    fout << person[i].firstName << "\n";
    fout << person[i].lastName << "\n";
    fout << person[i].major << "\n\n";
  }
  fout << endl;
}

void print_array(student* person, int n) {
  for (int i = 0; i < n; i++) {
    cout << "\nStudent " << i+1 << "\n";
    cout << person[i].id_number << "\n";
    cout << person[i].firstName << "\n";
    cout << person[i].lastName << "\n";
    cout << person[i].major << "\n";
  }
  cout << endl;
}

void delete_student_db_info(student * table) {
	delete[] table;
}