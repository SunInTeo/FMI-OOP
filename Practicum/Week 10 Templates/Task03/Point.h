#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
    double x;
    double y;

    void copy(const Point &point);

public:
    Point();
    Point(double x, double y);
    Point(const Point &point);

    Point &operator=(const Point &point);

    bool operator>(const Point &other) const;
    bool operator==(const Point &other) const;

    friend std::istream &operator>>(std::istream &in, Point &point);
    friend std::ostream &operator<<(std::ostream &out, const Point &point);
};

#endif