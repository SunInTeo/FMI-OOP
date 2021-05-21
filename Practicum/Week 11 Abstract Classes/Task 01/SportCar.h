#ifndef SPORT_CAR_H
#define SPORT_CAR_H

#include "Car.h"

class SportCar : public Car
{
public:
    SportCar(double maxSpeed, double currentSpeed, double price);

    void accelerate();
};

#endif