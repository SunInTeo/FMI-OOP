#include <iostream>
#include "Shape.h"

Shape::Shape(std::string type)
{
    this->type = type;
}

void Shape::printShape()
{
    std::cout << "Type: " << type << "\n";
}