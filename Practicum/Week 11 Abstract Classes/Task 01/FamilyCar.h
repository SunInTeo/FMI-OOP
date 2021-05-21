#ifndef FAMILY_CAR_H
#define FAMILY_CAR_H

#include "Car.h"

class FamilyCar : public Car
{
public:
    FamilyCar(double maxSpeed, double currentSpeed, double price);

    void accelerate();
};

#endif