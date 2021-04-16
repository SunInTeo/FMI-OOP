#ifndef GARAGE_H
#define GARAGE_H

#include "Vehicle.h"

class Garage
{
    Vehicle **vehicleArray;
    std::size_t capacity;
    std::size_t sizeTaken;
    std::size_t numberOfVehicles;

public:
    Garage() = delete;
    Garage(std::size_t size);
    ~Garage();

    void insert(Vehicle &v);
    void erase(const char *registration);

    const Vehicle &at(std::size_t pos) const;
    const Vehicle &operator[](std::size_t pos) const;

    bool empty() const;
    std::size_t size() const;
    void clear();

    const Vehicle *find(const char *registration) const;
};

#endif