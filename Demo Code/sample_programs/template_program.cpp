#include <iostream>
// using namespace std;      // don't include this while working with templates

template <typename T>
const T& min(const T& x, const T& y) {
      if (x < y) return x;
      else return y;
}

int main() {
      int x = 3;
      int y = 5;
      
      std::cout << "\n\n\nX = " << x << ", Y = " << y << "\n";
      std::cout << "\nmin(x, y): " << min(x, y) << "\n";
      std::cout << "\nmin(100.0, 500.0): " << min(100.0, 500.0) << "\n\n\n";
      
      return 0;
}