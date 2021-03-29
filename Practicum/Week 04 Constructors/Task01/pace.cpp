#include <iostream>
#include "pace.h"

using std::cin;
using std::cout;
using std::endl;

Pace::Pace()
{
    this->pace = 0;
    this->velocity = 0;
}

Pace::~Pace()
{
   cout << "removed\n"; 
}

Pace::Pace(double _minutes, double _seconds)
{
    this->pace = _minutes + _seconds / 60;
    this->velocity = 60 / pace;
}

Pace::Pace(double _velocity)
{
    this->velocity = _velocity;
    this->pace = 60 / velocity;
}

double Pace::getPace() const
{
    return this->pace;
}

double Pace::getVelocity() const
{
    return this->velocity;
}