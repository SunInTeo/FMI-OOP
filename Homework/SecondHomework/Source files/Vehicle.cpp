#include "../Header files/Vehicle.h"

void Vehicle::copy(const Vehicle &other)
{
    myRegistration = other.myRegistration;
    description = other.description;
    owner = other.owner;
}

Vehicle::Vehicle(const Registration &myRegistration, std::string &description) : myRegistration(myRegistration), description(description)
{
    owner = nullptr;
}

Vehicle::Vehicle(const Vehicle &other) : myRegistration(other.myRegistration)
{
    copy(other);
}

Person &Vehicle::getOwner()
{
    return *owner;
}
Registration Vehicle::getReg() const
{
    return myRegistration;
}
std::string Vehicle::getDesc() const
{
    return description;
}

void Vehicle::print()
{
    std::cout << "{<" << myRegistration.toCharArray() << ">, " << description << "}";
}

void Vehicle::printVehicleAndOwner()
{
    Vehicle::print();
    if(owner != nullptr) 
    {
        owner->print();
    }
    else
    {
        std::cout << "No owner";
    } 
}

Vehicle &Vehicle::operator=(const Vehicle &other)
{
    if(this != &other)
    {
        copy(other);
    }

    return *this;
}

bool Vehicle::operator==(const Vehicle &other) const
{
    return !strcmp(myRegistration.toCharArray(), other.myRegistration.toCharArray());
}