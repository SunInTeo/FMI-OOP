#include <iostream>
#include "Triangle.h"

Triangle::Triangle(double side1, double side2, double side3) : Shape("Triangle")
{
    this->side1 = side1;
    this->side2 = side2;
    this->side3 = side3;
}

void Triangle::printTriangle()
{
    Shape::printShape();

    std::cout << "Side 1: " << side1 << "\n";
    std::cout << "Side 2: " << side2 << "\n";
    std::cout << "Side 3: " << side3 << "\n";
}