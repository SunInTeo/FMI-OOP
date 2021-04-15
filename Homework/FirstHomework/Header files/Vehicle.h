#ifndef VEHICLE_H
#define VEHICLE_H

#include "MyString.h"

class Vehicle
{
    MyString licenseNumber;
    MyString descriptionAboutVehicle;
    std::size_t numberOfParkingSpaces = 0;

public:
    Vehicle() = delete;
    Vehicle(const char *registration, const char *description, std::size_t space);
    const char* registration() const;
    const char* description() const;
    std::size_t space() const;
};

#endif