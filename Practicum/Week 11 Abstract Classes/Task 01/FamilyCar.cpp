#include "FamilyCar.h"

FamilyCar::FamilyCar(double maxSpeed, double currentSpeed, double price) : Car(maxSpeed, currentSpeed, price)
{
}

void FamilyCar::accelerate()
{
    std::cout << "Family car is accelerating...\n";
}