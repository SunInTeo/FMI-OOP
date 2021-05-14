#include ".\Task01\List.h"
#include ".\Task02\Order.h"
#include ".\Task03\Point.h"

int main()
{
    Order<Point> pointArray;

    Point point1(3,4), point2(1, 2), point3, point4(-2, -6);

    pointArray.add(point1);
    pointArray.add(point2);
    pointArray.add(point3);
    pointArray.add(point4);   

    pointArray.write("points.txt");

    Order<Point> copy;

    copy.read("points.txt");

    for (std::size_t i = 0; i < copy.getSize(); ++i)
    {
        std::cout << copy[i] << std::endl;
    }

    return 0;
}