#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(double width, double height) : Shape("Rectangle")
{
    this->width = width;
    this->height = height;
}

Rectangle::Rectangle(double width, double height, std::string type) : Shape(type)
{
    this->width = width;
    this->height = height;
}

void Rectangle::printRectangle()
{
    Shape::printShape();
    std::cout << "W: " << width << "\n";
    std::cout << "H: " << height << "\n";
}