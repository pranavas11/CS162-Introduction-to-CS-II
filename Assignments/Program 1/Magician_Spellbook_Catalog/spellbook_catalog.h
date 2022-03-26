#ifndef SPELLBOOK_CATALOG_H
#define SPELLBOOK_CATALOG_H

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
using namespace std;

struct spellbook {                // this struct is used to hold information from the spellbooks.txt file
  string title;
  string author;
  int num_pages;
  int edition;
  int num_spells;
  float avg_success_rate;
  struct spell* s;
};

struct spell {            // this struct is also used to read in information from the spellbooks.txt file and also holds information about a spell
  string name;
  float success_rate;
  string effect; 
};

int get_int(string prompt);
void print_options();
int user_input_choice();
int get_output_mode();
void get_file_name(string* file);

spellbook* create_spellbooks(int n);
spell* create_spells(int n);
void get_spell_data(spell* s, int n, ifstream &f);
float spells_avg_success_rate(spell* sb, int n);
void get_spellbook_data(spellbook* sb, int n, ifstream& f);

void sort_by_numOfPages(spellbook* sb, int n);
void sort_by_effect(spellbook* sb, int num, string s);
void sort_by_avg_success_rate(spellbook* sb, int n);

void print_pages(spellbook* sb, int num);
void print_effects(spellbook* sb, int num);
void print_rates(spellbook* sb, int num);

void write_spell_effects_to_file(spellbook* sb, int num, string s, fstream& file);
void pages_to_file(spellbook* sb, int num, fstream& file);
void spell_effects_to_file(spellbook* sb, int num, fstream& file);
void avg_success_rates_to_file(spellbook* sb, int num, fstream& file);
void write_to_file(string s, fstream& file);

void output_data(spellbook* sb, int num, int option, int outmode);

bool is_valid_file(int n, char* arg1, ifstream& file);

void delete_spellbook_data(spellbook* sb, int n);

#endif