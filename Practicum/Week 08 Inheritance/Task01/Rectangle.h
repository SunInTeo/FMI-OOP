#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
protected:
    double width;
    double height;

    Rectangle(double width, double height, std::string type);

public:
    Rectangle(double width, double height);

    void printRectangle();
};

#endif