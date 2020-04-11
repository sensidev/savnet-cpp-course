#include "triangle.h"

Triangle::Triangle(float e1, float e2, float e3) {
    this->edge_length1 = e1;
    this->edge_length2 = e2;
    this->edge_length3 = e3;
}

float Triangle::getPerimeter() {
    return this->edge_length1 + this->edge_length2 + this->edge_length3;
}