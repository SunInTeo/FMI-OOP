#include <iostream>
#include "ComponentType.h"

unsigned ComponentType::generatedNumber = 123456;

ComponentType::ComponentType()
{
    serialNumber = ++generatedNumber;
}

void ComponentType::printComponentType()
{
    std::cout << "Serial number: " << serialNumber << "\n";
}