#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    fstream f;
    f.open("input.txt");

    int num = 0;
    string tmp_string;
    
    cout << "\n\n\n";
    
    if (f.is_open()) {
        while (f.good()) {
            getline(f, tmp_string, ',');      // separates characters/words by the ',' separator
            cout << tmp_string << " ";
            num++;
        }
    } else {
        cout << "FILE PROBLEMS" << endl;
    }
    
    cout << num << "\n\n\n";

    //f << "This is a file." << endl;      // uncomment to test

    f.close();

    //f.open("inputs2.txt");      // uncomment to test

    return 0;
}