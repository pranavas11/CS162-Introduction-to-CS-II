#include <iostream>
using namespace std;

class Point{
private:
    int x_position;
    int y_position;

public:
    void move_left(int);
    int get_x();
    void set_x(int);
    int get_y();
};

void Point::move_left(int delta){
    x_position = x_position - delta;
}

int Point::get_x(){
    return x_position;
}

int Point::get_y(){
    return y_position;
}

void Point::set_x(int new_x){
    x_position = new_x;
}

//some other person using our library
int main(){
    Point p1;
    p1.set_x(9);
    p1.move_left(2);
    cout << p1.get_x() << endl;
    return 0;
}