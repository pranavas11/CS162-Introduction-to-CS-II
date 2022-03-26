#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "student_database.h"
using namespace std;

int main(int argc, char** argv) {
  fstream file;         // combination of ofstream and ifstream: creates, reads, and writes to files
  string file_name = "inputs.txt";
  unsigned int number_of_students;

  file.open(file_name.c_str(), ios::in);
  while(file.fail()) {
    cout << "ERROR: File does not exist. Please enter a valid filename: ";
    cin >> file_name;
    file.open(file_name.c_str(), ios::in);
  }

  string temp;
  file >> temp;
	number_of_students = stoi(temp);
  
  student* student_arr = create_student_db(number_of_students);
  populate_array(student_arr, number_of_students, file);
  file.close();

  file.open("outputs.txt", ios::out);
  file << "STUDENTS SORTED BY ID NUMBER:\n";
  sort_by_id(student_arr, number_of_students);
  get_student_db_info(student_arr, number_of_students, file);

  file << "STUDENTS SORTED BY LAST NAME" << endl;
	sort_by_lastname(student_arr, number_of_students);
	get_student_db_info(student_arr, number_of_students, file);
  print_array(student_arr, number_of_students);
  file.close();
  delete_student_db_info(student_arr);

  return 0;
}