#ifndef COLORED_RECTANGLE_H
#define COLORED_RECTANGLE_H

#include <string>
#include "Rectangle.h"

class ColoredRectangle : public Rectangle
{
protected:
    std::string color;

public:
    ColoredRectangle(double width, double height, std::string color);

    void printColoredRectangle();
};

#endif