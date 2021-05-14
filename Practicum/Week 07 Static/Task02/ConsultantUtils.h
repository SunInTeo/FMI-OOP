#ifndef UTILITIES_H
#define UTILITIES_H

#include "..\Task01\Computer.h"

class ConsultantUtils
{
public:
    static bool isGoodForGaming(const Computer &computer);
    static bool isGoodForTravel(const Computer &computer);
};

#endif