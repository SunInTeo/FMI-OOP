#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include "../Task 02/Engine.h"

class Car : public Vehicle
{
private:
    double maxSpeed;
    double currentSpeed;
    double price;
    Engine engine;

public:
    Car(double maxSpeed, double currentSpeed, double price);

    void startMovement();
    void stopMovement();

    void startEngine();
    void stopEngine();

    virtual void accelerate();
};

#endif