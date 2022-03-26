#include <iostream>
using namespace std;

class Point {
private:
    int x_position;
    int y_position;

public:
    // getter functions (accessors)
    int get_x();
    int get_y();
    
    // setter function (mutator)
    void set_x(int);
    
    // member function
    void move_left(int);
};

int Point::get_x() {
    return x_position;
}

int Point::get_y() {
    return y_position;
}

void Point::set_x(int new_x) {
    x_position = new_x;
}

void Point::move_left(int delta) {
    x_position = x_position - delta;
}

int main() {
    Point p1;
    cout << "\n\n\nStarting at x = 9\n";
    p1.set_x(9);
    p1.move_left(2);
    cout << "\nAfter moving left: " << p1.get_x() << "\n\n\n";
    
    return 0;
}