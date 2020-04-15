#include <iostream>
#include <string>

using namespace std;

class Square {
private:
    double side;
    double area;

    double calculate_area();

public:
    Square(double side);

    void set_side(double side);

    void print_me();
};

double Square::calculate_area() {
    return this->side * this->side;
}

Square::Square(double side) {
    this->side = side;
    this->area = calculate_area();
}

void Square::set_side(double side) {
    if (side >= 0) {
        this->side = side;
        this->area = calculate_area();
    }
}

void Square::print_me() {
    cout << "Square: side=" << this->side << " area=" <<
         this->area << endl;
}


int main() {
    Square s(4);

    s.print_me();

    s.set_side(2.0);
    s.print_me();

    s.set_side(-33.0);
    s.print_me();

    return 0;
}