//#ifndef PERSON_H
//#define PERSON_H
#pragma once

#include <iostream>
#include <string>
#include <vector>
class Vehicle;

#include "./Vehicle.h"

class Person
{
private:
    std::string name;
    unsigned int uid;
    std::vector<Vehicle *> vehiclesArray;

public:
    Person(std::string name, unsigned int uid);

    void acquire(Vehicle &myVhcl);
    void release(const Registration &other);
    void releaseAll();

    bool doesOwn(const Registration &other);

    std::string getName() const;
    unsigned int getUid() const;

    void print();
    void printWithVehicles();
};

//#endif
