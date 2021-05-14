#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
protected:
    std::string type;

public:
    Shape(std::string type);

    void printShape();
};

#endif