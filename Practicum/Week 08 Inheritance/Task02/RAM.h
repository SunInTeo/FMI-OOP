#ifndef RAM_H
#define RAM_H

#include <string>
#include "ComponentType.h"

class RAM : public ComponentType
{
    std::string brand;

public:
    RAM(std::string brand);

    void printRAM();
};

#endif