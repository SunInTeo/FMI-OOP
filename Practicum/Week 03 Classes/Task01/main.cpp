#include <iostream>
#include "triangle.h"



int main()
{
    Triangle tr1;

    tr1.input();
    std::cout << "P = " << tr1.perimeter() << std::endl;
    std::cout << "S = " << tr1.area();

    return 0;
}