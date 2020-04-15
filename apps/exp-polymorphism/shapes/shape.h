#ifndef EXP_POLYMORPHISM_SHAPE_H
#define EXP_POLYMORPHISM_SHAPE_H

// We declare stuff here.

typedef struct Point {
    int x;
    int y;
} Point_t;

class Shape {
private:
    Point_t p;  // do nothing with it, just demonstrate a way to define and use a new data type.
protected:

public:
    virtual float getPerimeter() = 0;
};

#endif
