/**
 * Exercise inspired from
 * https://www.freecodecamp.org/news/object-oriented-programming-concepts-21bb035f7260/
 */
#include <iostream>
#include <vector>

#include "shapes/triangle.h"
#include "shapes/square.h"
#include "shapes/circle.h"

using namespace std;

int main() {
    Triangle t1(1.1, 2.2, 3.3);
    Square s1(11.12);
    Circle c1(5);

    cout << "Triangle perimeter " << t1.getPerimeter() << endl;
    cout << "Square perimeter " << s1.getPerimeter() << endl;
    cout << "Circle perimeter (circumference) " << c1.getPerimeter() << endl;

    // Polymorphism - total perimeter exercise
    vector<Shape *> shapes;

    shapes.push_back(&t1);
    shapes.push_back(&s1);
    shapes.push_back(&c1);

    float total_perimeter = 0.0;

    // Foreach loop
    for (Shape *shape: shapes) {
        total_perimeter += shape->getPerimeter();
    }

// Alternative - index based loop
//    for (int i = 0; i < shapes.size(); i++) {
//        total_perimeter += shapes[i]->getPerimeter();
//    }

    cout << "Total perimeter of all shapes: " << total_perimeter << endl;

    return 0;
}