#include "Point.h"

void Point::copy(const Point &point)
{
    x = point.x;
    y = point.y;
}
Point::Point()
{
    x = 0.0;
    y = 0.0;
}
Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}
Point::Point(const Point &point)
{
    copy(point);
}
Point &Point::operator=(const Point &point)
{
    if (this != &point)
    {
        copy(point);
    }

    return *this;
}

bool Point::operator==(const Point &other) const
{
    return x == other.x && y == other.y;
}

bool Point::operator>(const Point &other) const
{
    return x > other.x || (x == other.x && y > other.y);
}

std::istream &operator>>(std::istream &in, Point &point)
{
    in >> point.x >> point.y;

    return in;
}

std::ostream &operator<<(std::ostream &out, const Point &point)
{
    out << point.x << " " << point.y;

    return out;
}