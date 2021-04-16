#ifndef VEHICLE_ALLOCATOR_H
#define VEHICLE_ALLOCATOR_H

#include "Garage.h"

class VehicleAllocator
{
    Garage *myGarage;
    Vehicle **vhclArray;
    std::size_t vehiclesAmount;

    std::size_t returnIndexOfVehicle(Vehicle &v);
public:

    VehicleAllocator() = delete;
    VehicleAllocator(std::size_t size);
    ~VehicleAllocator();

    Vehicle &generateNewVehicle(const char *registration, const char *description, std::size_t space);
    Vehicle *getVehicleFromRegistration(const char *registration) const;

    void addVehicleToMyGarage(Vehicle &v);
    void removeVehicleFromMyGarage(Vehicle &v);
    void removeVehicleFromMyGarage(const char *registration);
    void terminateVehicle(const char *registration);    

    std::size_t getAllVehiclesCount();
    std::size_t getVehiclesInMyGarageCount();

    const void printAllVehicles() const;
    const void printVehiclesFromMyGarage() const;

    void cleanAllVehicles();
    void cleanVehiclesInMyGarage();
};

#endif