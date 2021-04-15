#include <iostream>
#include "..\Header files\Garage.h"

using std::cout;
using std::endl;
using std::size_t;

void Garage::copy(const Garage &other)
{
    Vehicle **buffer = new Vehicle *[other._capacity];

    for (size_t i = 0; i < other._numberOfVehicles; ++i)
    {
        buffer[i] = new Vehicle(*(other.vehicleArray[i]));
    }

    for (size_t i = 0; i < other._numberOfVehicles; ++i)
    {
        delete[] vehicleArray[i];
    }
    delete[] vehicleArray;

    vehicleArray = buffer;
    _numberOfVehicles = other._numberOfVehicles;
    _capacity = other._capacity;
    _sizeTaken = other._sizeTaken;
}
void Garage::deallocate()
{
}
void Garage::resize()
{
}

Garage::Garage(size_t size)
{
    _numberOfVehicles = 0;
    _sizeTaken = 0;
    _capacity = size;
    vehicleArray = new Vehicle *[_capacity];
}
Garage::Garage(const Garage &other)
{
    copy(other);
}
Garage::~Garage()
{
    for (std::size_t i = 0; i < _numberOfVehicles; ++i)
    {
        delete vehicleArray[i];
    }

    delete[] vehicleArray;
}
Garage &Garage::operator=(const Garage &other)
{
    if (this != &other)
    {
        copy(other);
    }

    return *this;
}
void Garage::insert(Vehicle& v)
{
    if(v.space() + _sizeTaken > _capacity)
    {
        throw std::out_of_range("There is not enough space for this vehicle");
    }

    bool doesExistInGarage = false;
    for(size_t i = 0; i < _numberOfVehicles; ++i)
    {
        if(!m_strcmp(vehicleArray[i]->registration(), v.registration()))
        {
            doesExistInGarage = true;
        }
    }

    if(doesExistInGarage)
    {
        throw std::invalid_argument("Vehicle already exists in the garage");
    }

    Vehicle *vhcl = new Vehicle(v.registration(), v.description(), v.space());
    vehicleArray[_numberOfVehicles++] = vhcl;
    _sizeTaken += v.space();
}