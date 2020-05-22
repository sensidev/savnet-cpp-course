#include <iostream>

using namespace std;

struct Point {
    float *x_ptr;
    float *y_ptr;
};

void make(Point *p, float x = 10) {
    float *f = new float;

    *f = sizeof(*f) / sizeof(float) * 10;//4/4*10

    p->x_ptr = f;
    cout << *f << endl;

    cout << "Address: " << f << endl;
}

int main() {
    Point *point_ptr = new Point;

    make(point_ptr);

    float *x_ptr = (*point_ptr).x_ptr;
    cout << *x_ptr << endl;
    cout << "Address: " << x_ptr << endl;

    delete point_ptr->x_ptr;
    delete point_ptr->y_ptr;
    delete point_ptr;

    cout << "Extra info: " << endl;
    cout << "Size of a float: " << sizeof(float) << endl;

    return 0;
}