#ifndef EXP_POLYMORPHISM_SQUARE_H
#define EXP_POLYMORPHISM_SQUARE_H


#include "shape.h"

class Square : public Shape {
private:
    float edge_length;
public:
    Square(float e);

    float getPerimeter();
};


#endif
