#include <iostream>
#include "GPU.h"

GPU::GPU(std::string brand) : ComponentType()
{
    this->brand = brand;
}

void GPU::printGPU()
{
    std::cout << "GPU -> " << "\n";
    std::cout << "Brand: " << brand << "\n";
    ComponentType::printComponentType();
}