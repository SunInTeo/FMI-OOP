#include "..\Header files\VehicleAllocator.h"

VehicleAllocator::VehicleAllocator(std::size_t size)
{
    myGarage = new Garage(size);
    vhclArray = nullptr;
    vehiclesAmount = 0;
}

VehicleAllocator::~VehicleAllocator()
{
    for (std::size_t i = 0; i < vehiclesAmount; ++i)
    {
        delete vhclArray[i];
    }
    delete[] vhclArray;
    delete myGarage;
}

Vehicle &VehicleAllocator::generateNewVehicle(const char *registration, const char *description, std::size_t space)
{
    Vehicle **buffer = new Vehicle *[vehiclesAmount + 1];
    for (std::size_t i = 0; i < vehiclesAmount; ++i)
    {
        buffer[i] = vhclArray[i];
    }
    Vehicle *newVhcl = new Vehicle(registration, description, space);
    buffer[vehiclesAmount] = newVhcl;

    delete[] vhclArray;
    vhclArray = buffer;
    ++vehiclesAmount;
    return *newVhcl;
}

void VehicleAllocator::addVehicleToMyGarage(Vehicle &v)
{
    myGarage->insert(v);
}

Vehicle *VehicleAllocator::getVehicleFromRegistration(const char *reg) const
{
    for (std::size_t i = 0; i < vehiclesAmount; ++i)
    {
        if (!strcmp(vhclArray[i]->registration(), reg))
        {
            return vhclArray[i];
        } 
    }

    return nullptr;
}

void VehicleAllocator::removeVehicleFromMyGarage(Vehicle &v)
{
    myGarage->erase(v.registration());
}

void VehicleAllocator::removeVehicleFromMyGarage(const char *registration)
{
    myGarage->erase(registration);
}

void VehicleAllocator::terminateVehicle(const char *registration)
{
    Vehicle *vhclToDel = getVehicleFromRegistration(registration);
    if (!vhclToDel)
    {
        return;
    }
    myGarage->erase(registration);
    std::size_t index = returnIndexOfVehicle(*vhclToDel);
    delete vhclToDel;
    if (index != vehiclesAmount - 1)
    {
        vhclArray[index] = vhclArray[vehiclesAmount - 1];
    }

    --vehiclesAmount;
}

std::size_t VehicleAllocator::returnIndexOfVehicle(Vehicle &v)
{
    std::size_t index = -1;
    for (std::size_t i = 0; i < vehiclesAmount; ++i)
    {
        if (!strcmp(vhclArray[i]->registration(), v.registration()))
        {
            index = i;
        }
    }
    if (index != -1)
    {
        return index;
    }

    throw std::invalid_argument("Vehicle doesn't exist in garage");
}

const void VehicleAllocator::printAllVehicles() const
{
    for (std::size_t i = 0; i < vehiclesAmount; ++i)
    {
        std::cout << vhclArray[i]->registration() << "/ " << vhclArray[i]->description() << "/ " << vhclArray[i]->space() << "\n";
    }
}

const void VehicleAllocator::printVehiclesFromMyGarage() const
{
    for (std::size_t i = 0; i < myGarage->size(); ++i)
    {
        std::cout << myGarage->at(i).registration() << "/ " << myGarage->at(i).description() << "/ " << myGarage->at(i).space() << "\n";
    }
}

std::size_t VehicleAllocator::getAllVehiclesCount()
{
    return vehiclesAmount;
}
std::size_t VehicleAllocator::getVehiclesInMyGarageCount()
{
    return myGarage->size();
}

void VehicleAllocator::cleanAllVehicles()
{
    for (std::size_t i = 0; i < vehiclesAmount; ++i)
    {
        delete vhclArray[i];
    }
    delete[] vhclArray;
    delete myGarage;
    vehiclesAmount = 0;
    vhclArray = new Vehicle *[vehiclesAmount];
}
void VehicleAllocator::cleanVehiclesInMyGarage()
{
    myGarage->clear();
}