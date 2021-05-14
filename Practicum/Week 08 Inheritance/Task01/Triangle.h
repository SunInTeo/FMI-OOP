#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
protected:
    double side1;
    double side2;
    double side3;

public:
    Triangle(double side1, double side2, double side3);

    void printTriangle();
};

#endif