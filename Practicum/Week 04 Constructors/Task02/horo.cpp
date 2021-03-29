#include <iostream>
#include <cstring>
#include "horo.h"
#include "helpers.h"

Horo::Horo(const char *_name, const double _tact, const char *_region)
{
    this->name = copyDynStr(_name);
    this->tact = _tact;
    this->region = copyDynStr(_region);
}

char *Horo::getName() const
{
    return this->name;
}

double Horo::getTact() const
{
    return this->tact;
}

char *Horo::getRegion() const
{
    return this->region;
}