#ifndef HDD_H
#define HDD_H

#include "ComponentType.h"

class HDD : public ComponentType
{
    std::string brand;

public:
    HDD(std::string brand);

    void printHDD();
};

#endif