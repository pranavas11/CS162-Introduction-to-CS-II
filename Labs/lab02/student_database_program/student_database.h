#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

struct student {
  unsigned int id_number;
  string firstName;
  string lastName;
  string major;
};

student* create_student_db(int);
void populate_array(student *, int, fstream &);
void sort_by_id(student*, int);
void sort_by_lastname(student*, int);
void get_student_db_info(student *, int, fstream &);
void print_array(student*, int);
void delete_student_db_info(student *);