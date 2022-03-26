#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  vector<vector<string> > v;
    
  v.resize(10);
  cout << "\n\n\nVector size: " << v.size() << endl << endl << endl;
  for(int i = 0; i < 10; i++) {
    v.at(i).resize(10);
    cout << v.at(i).size() << " ";
    for(int j = 0; j < 10; j++) {
      v.at(i).at(j) = "0";
    }
  }
  
  cout << endl << endl << endl;

  v.at(5).at(5) = "\033[1;32mP\033[0m";

  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) cout << v.at(i).at(j) << " ";
    cout << endl;
  }
  
  cout << endl;
    
  for(int j = 0; j < 10; j++) cout << "*---*" ;
  
  cout << endl;
    
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      cout << "* " << v.at(i).at(j) << "  " ;
    }
    
    cout << endl;
    
    for(int j = 0; j < 10; j++) {
      cout << "*---*" ;
    }
    
    cout << endl;
  }
  
  cout << "\n\n\n";
    
  return 0;
}