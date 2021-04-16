#include "..\Header files\Garage.h"

using std::cout;
using std::endl;
using std::size_t;

Garage::Garage(size_t size)
{
    numberOfVehicles = 0;
    sizeTaken = 0;
    capacity = size;
    vehicleArray = new Vehicle *[capacity];
}

Garage::~Garage()
{
    delete[] vehicleArray;
}

void Garage::insert(Vehicle &v)
{
    if (v.space() + sizeTaken > capacity)
    {
        throw std::out_of_range("There is not enough space for this vehicle");
    }

    for (size_t i = 0; i < numberOfVehicles; ++i)
    {
        if (!m_strcmp(vehicleArray[i]->registration(), v.registration()))
        {
            throw std::invalid_argument("Vehicle already exists in the garage");
        }
    }

    vehicleArray[numberOfVehicles++] = &v;
    sizeTaken += v.space();
}

void Garage::erase(const char *registration)
{
    std::size_t index = capacity;
    for (std::size_t i = 0; i < numberOfVehicles; ++i)
    {
        if (!m_strcmp(vehicleArray[i]->registration(), registration))
        {
            index = i;
        }
    }

    if (index != capacity)
    {
        sizeTaken -= vehicleArray[index]->space();
        vehicleArray[index] = vehicleArray[numberOfVehicles - 1];
        --numberOfVehicles;
    }
}

const Vehicle &Garage::at(std::size_t pos) const
{
    if (pos >= numberOfVehicles)
    {
        throw std::out_of_range("Invalid position");
    }
    return *vehicleArray[pos];
}

const Vehicle &Garage::operator[](std::size_t pos) const
{
    assert(pos <= sizeTaken);
    return *vehicleArray[pos];
}

bool Garage::empty() const
{
    return !numberOfVehicles;
}
std::size_t Garage::size() const
{
    return numberOfVehicles;
}
void Garage::clear()
{
    for (std::size_t i = 0; i < numberOfVehicles; ++i)
    {
        vehicleArray[i] = nullptr;
    }
    numberOfVehicles = 0;
}

const Vehicle *Garage::find(const char *registration) const
{
    for (std::size_t i = 0; i < numberOfVehicles; ++i)
    {
        if (!m_strcmp(vehicleArray[i]->registration(), registration))
        {
            return vehicleArray[i];
        }
    }
    return nullptr;
}