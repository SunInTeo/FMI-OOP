#ifndef COMPONENT_TYPE_H
#define COMPONENT_TYPE_H

#include <string>

class ComponentType
{
protected:
    static unsigned generatedNumber;
    unsigned serialNumber;

public:
    ComponentType();

    void printComponentType();
};

#endif