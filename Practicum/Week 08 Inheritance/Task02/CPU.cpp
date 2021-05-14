#include <iostream>
#include "CPU.h"

CPU::CPU(std::string brand) : ComponentType()
{
    this->brand = brand;
}

void CPU::printCPU()
{
    std::cout << "CPU -> "<< "\n";
    std::cout << "Brand: " << brand << "\n";
    ComponentType::printComponentType();
}