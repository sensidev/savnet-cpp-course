#ifndef EXP_POLYMORPHISM_TRIANGLE_H
#define EXP_POLYMORPHISM_TRIANGLE_H

#include "shape.h"

class Triangle : public Shape {
private:
    float edge_length1;
    float edge_length2;
    float edge_length3;
public:
    Triangle(float e1, float e2, float e3);
    float getPerimeter();
};


#endif
