#include <iostream>
#include "ColoredRectangle.h"

ColoredRectangle::ColoredRectangle(double width, double height, std::string color)
    : Rectangle(width, height, "Coloured Rectangle")
{
    this->color = color;
}

void ColoredRectangle::printColoredRectangle()
{
    Rectangle::printRectangle();
    std::cout << "Color: " << color << "\n";
}