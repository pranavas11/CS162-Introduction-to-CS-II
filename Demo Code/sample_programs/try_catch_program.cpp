#include <iostream>
#include <cstdlib>
#include <array>
#include <cassert>
using namespace std;

int getValue(const array<int, 10> &a, int i) {
      if(i >= 0 && i <= 9 && "Invalid range") {
            throw i;
      }
      return a[i];
}

int main() {
      try{
            array<int, 10> test;
            cout << getValue(test, 1);      // call function with invalid index
            cerr << "\n\n\nError Message" << endl;
            int z = getValue(test, -3);
      } catch (int x) {
            cerr << "\n\n\nInt exception occurred " << x << "\n\n\n";
      } catch (double y) {
            cerr << "\n\n\nDouble exception occurred " << y << "\n\n\n";
      }
      
      return 0;
}