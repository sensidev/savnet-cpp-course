#include "circle.h"
#include "cmath"

Circle::Circle(unsigned int r) {
    this->radius = r;
}

float Circle::getPerimeter() {
    return 2 * M_PI * radius;
}