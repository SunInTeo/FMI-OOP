#ifndef GPU_H
#define GPU_H

#include <string>
#include "ComponentType.h"

class GPU : public ComponentType
{
    std::string brand;

public:
    GPU(std::string brand);

    void printGPU();
};

#endif