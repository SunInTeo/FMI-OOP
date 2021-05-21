#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

class Vehicle
{
public:
    virtual void startMovement() = 0;
    virtual void stopMovement() = 0;
};

#endif