#include <iostream>
#include <cmath>
#include "triangle.h"

using std::cin;
using std::cout;
using std::endl;

bool Triangle::validate()
{
    return !(a + b > c && a + c > b && b + c > a && a > 0 && b > 0 && c > 0);
}

void Triangle::input()
{
    do
    {
        cout << "a = ";
        cin >> a;
        cout << "b = ";
        cin >> b;
        cout << "c = ";
        cin >> c;
    } while (this->validate());
}

double Triangle::perimeter()
{
    return (a + b + c);
}

double Triangle::area()
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}