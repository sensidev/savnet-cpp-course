#ifndef EXP_POLYMORPHISM_CIRCLE_H
#define EXP_POLYMORPHISM_CIRCLE_H

#include "shape.h"

class Circle : public Shape {
private:
    unsigned int radius;
public:
    Circle(unsigned int r);
    float getPerimeter();
};


#endif
