#include <iostream>
#include "RAM.h"

RAM::RAM(std::string brand) : ComponentType()
{
    this->brand = brand;
}

void RAM::printRAM()
{
    std::cout << "RAM" << "\n";
    std::cout << "Brand: " << brand << "\n";
    ComponentType::printComponentType();
}