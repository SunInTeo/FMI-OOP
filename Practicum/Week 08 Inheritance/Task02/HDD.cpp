#include <iostream>
#include "HDD.h"

HDD::HDD(std::string brand) : ComponentType()
{
    this->brand = brand;
}

void HDD::printHDD()
{
    std::cout << "Hard Drive -> " << "\n";
    std::cout << "Brand: " << brand << "\n";
    ComponentType::printComponentType();
}