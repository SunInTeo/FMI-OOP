#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "ColoredRectangle.h"
#include "Square.h"
#include "Triangle.h"

int main ()
{
    Rectangle myRectangle(4, 5);
    ColoredRectangle myColoredRectangle(9, 10, "Bloo");
    Square mySquare(5);
    Triangle myTriangle(3, 4, 5);

    myRectangle.printRectangle();
    std::cout << std::endl;
    myColoredRectangle.printColoredRectangle();
    std::cout << std::endl;
    mySquare.printSquare();
    std::cout << std::endl;
    myTriangle.printTriangle();

    return 0;
}