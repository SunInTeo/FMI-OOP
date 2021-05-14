#ifndef CPU_H
#define CPU_H

#include <string>
#include "ComponentType.h"

class CPU : public ComponentType
{
    std::string brand;

public:
    CPU(std::string brand);

    void printCPU();
};

#endif