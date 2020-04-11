#include "square.h"

Square::Square(float e) {
    this->edge_length = e;
}

float Square::getPerimeter() {
    return this->edge_length * 4;
}