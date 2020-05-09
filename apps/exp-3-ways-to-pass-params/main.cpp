#include <string>
#include <iostream>

using namespace std;

class Point {
private:
    string name;
    int x;
    int y;

public:
    Point(string name, int x, int y) {
        this->name = name;
        this->x = x;
        this->y = y;
    }

    ~Point() {}

    void change() {
        this->x++;
        this->y++;
        this->name = "Other point " + to_string(this->x);
    }

    void print() {
        cout << this->name << "  - (" << x << ", " << y << ")" << endl;
    }
};

/**
 * Pass parameters by copy.
 * Use `heavy` object.
 */
void do_something_by_copy(Point the_point) {
    the_point.change();
    cout << "do something: ";
    the_point.print();
}

/**
 * Pass parameters by pointer.
 * Use `light` object.
 */
void do_something_by_pointer(Point *the_point_pointer) {
    the_point_pointer->change();
    cout << "do something: ";
    the_point_pointer->print();
}

/**
 * Pass parameters by reference.
 * Use `light` object.
 */
void do_something_by_ref(Point &the_point_pointer) {
    the_point_pointer.change();
    cout << "do something: ";
    the_point_pointer.print();
}


int main() {
    Point p("The point from main", 11, 22);

    do_something_by_copy(p);  // send `heavy` object.
    p.print();

    do_something_by_pointer(&p);  // send `light` object.
    p.print();

    do_something_by_ref(p);  // send `heavy` object.
    p.print();

    return 0;
}
