#ifndef WASHINGMACHINE_H
#define WASHINGMACHINE_H

#include "Consts.h"

class WashingMachine
{
private:
    char manufacturer[MAX_STRING_LENGTH];
    char model[MAX_STRING_LENGTH];
    int massLaundry;
    double electricalConsumption;
    int waterConsumption;

public:
    WashingMachine();
    WashingMachine(const char *, const char *, const int,
                   const double, const int);

    bool operator>(const WashingMachine &);

    friend std::ostream &operator<<(std::ostream &out, const WashingMachine &);
    friend std::istream &operator>>(std::istream &in, WashingMachine &);
};

#endif
