#include <iostream>
#include <cstdlib>
using namespace std;

struct mult_div_values {
  int mult;
  float div;
};

bool is_valid_dimension(char *n) {
  return !(atoi(n) <= 0);
}

mult_div_values** create_table(int n) {
  mult_div_values** mult = new mult_div_values*[n+1];
  for (int i = 0; i < n + 1; i++) {
    mult[i] = new mult_div_values[n];
  }
  return mult;
}

void set_mult_values(mult_div_values **table, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      table[i][j].mult = (i+1) * (j+1);
    }
  }
}

void set_div_values(mult_div_values **table, int n) {
  cout << "\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0) {
        table[i][j].div = 0;
        continue;
      }
      table[i][j].div = (float) (j+1) / (float) (i+1);
    }
  }
}

void delete_table(mult_div_values **table, int n) {
  for (int i = 0; i < n; i++) {
    delete [] table[i];
  }
  delete [] table;
}

void print_multiplication_table(mult_div_values** table, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << table[i][j].mult << "\t";
    }
    cout << "\n";
  }
}

void print_division_table(mult_div_values** table, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << table[i][j].div << "\t";
    }
    cout << "\n";
  }
}

int main(int argc, char** argv) {
  if (argc != 2) {
    cout << "Invalid number of arguments. Please try again!\n";
    return 0;
  }

  unsigned int matrix_size = 5;
  matrix_size = atoi(argv[1]);
  if (!is_valid_dimension(argv[1])) {
    cout << "Please enter a valid integer for the matrix dimension.\n";
    return 0;
  }

  mult_div_values** table = create_table(matrix_size);
  set_mult_values(table, matrix_size);
  set_div_values(table, matrix_size);
  cout << "Multiplication Table:\n";
  print_multiplication_table(table, matrix_size);
  cout << "\nDivision Table:\n";
  print_division_table(table, matrix_size);

  while (true) {
    char result;
    cout << "\nDo you want to exit the program (y/n)? ";
    cin >> result;
    if (result == 'Y' || result == 'y') {
      cout << "\n";
      exit(0);
    } else {
      char option;
      unsigned int matrix_size = 5; 
      cout << "\nWould you like to see a different size matrix (y/n)? ";
      cin >> option;

      if (option == 'y' || option == 'Y') {
        cout << "\nEnter a matrix size: ";
        cin >> matrix_size;
        while (matrix_size <= 0) {
          cout << "Invalid matrix size. Please enter a valid integer above 0: ";
          cin.ignore(123, '\n');
          cin.clear();
          cin >> matrix_size;
        }

        mult_div_values** table = create_table(matrix_size);
        set_mult_values(table, matrix_size);
        set_div_values(table, matrix_size);
        cout << "Multiplication Table:\n";
        print_multiplication_table(table, matrix_size);
        cout << "\nDivision Table:\n";
        print_division_table(table, matrix_size);
      } else {
        cout << "\n";
        break;
      }
    }
  }

  return 0;
}