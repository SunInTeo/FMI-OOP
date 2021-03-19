#include <iostream>
#include <cmath>
#include "triangle.h"

using std::cin;
using std::cout;
using std::endl;

bool Triangle::validate(double a, double b, double c)
{
    return (a + b <= c || a + c <= b || b + c <= a);   
}

void Triangle::input()
{
    do
    {
        cout << "a = ";
        cin >> sideA;
        cout << "B = ";
        cin >> sideB;
        cout << "C = ";
        cin >> sideC;
    }while(validate(sideA, sideB, sideC) != 0 && (sideA > 0 && sideB > 0 && sideC > 0));
}

double Triangle::perimeter()
{
    return (sideA + sideB + sideC);
}

double Triangle::area()
{
    double area, p;

    p = (sideA + sideB + sideC) / 2;
    area = sqrt(p*(p-sideA)*(p-sideB)*(p-sideC));

    return area;
}