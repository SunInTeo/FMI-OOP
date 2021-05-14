#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include "ComponentType.h"
#include "HDD.h"
#include "GPU.h"
#include "CPU.h"
#include "RAM.h"

class Computer
{
    HDD myHDD;
    GPU myGPU;
    CPU myCPU;
    RAM myRAM;

public:
    Computer(std::string myHDD, std::string myGPU, std::string myCPU, std::string myRAM);
    
    void printComputerConfiguration();
};

#endif