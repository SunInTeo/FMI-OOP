#include "..\Header files\Vehicle.h"

Vehicle::Vehicle(const char *registration, const char *description, std::size_t space)
{
    MyString tempRegistration(registration);
    MyString tempDescription(description);

    licenseNumber = tempRegistration;
    descriptionAboutVehicle = tempDescription;

    numberOfParkingSpaces = space;
}
const char *Vehicle::registration() const
{
    return licenseNumber.c_str();
}
const char *Vehicle::description() const
{
    return descriptionAboutVehicle.c_str();
}
std::size_t Vehicle::space() const
{
    return numberOfParkingSpaces;
}
