#include "SportCar.h"

SportCar::SportCar(double maxSpeed, double currentSpeed, double price) : Car(maxSpeed, currentSpeed, price)
{
}

void SportCar::accelerate()
{
    std::cout << "Sport car is accelerating...\n";
}