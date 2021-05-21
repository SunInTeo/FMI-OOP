#include "Car.h"

Car::Car(double maxSpeed, double currentSpeed, double price)
{
    this->maxSpeed = maxSpeed;
    this->currentSpeed = currentSpeed;
    this->price = price;

    if (currentSpeed > 0)
    {
        engine.start();
    }
}

void Car::startMovement()
{
    std::cout << "Car has started moving...\n";
}
void Car::stopMovement()
{
    std::cout << "Car has stopped moving...\n";
}

void Car::startEngine()
{
    std::cout << "Engine started...\n";

    engine.start();
}
void Car::stopEngine()
{
    std::cout << "Engine stopped...\n";

    engine.stop();
}
void Car::accelerate()
{
    std::cout << "Car is accelerating...\n";
}