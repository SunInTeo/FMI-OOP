#ifndef VEHICLE_H
#define VEHICLE_H

//#pragma once

#include <string>
#include <vector>
#include "./Registration.h"
class Person;
#include "./Person.h"

class Vehicle
{
private:
    friend class Person;

    Registration myRegistration;
    std::string description;
    Person *owner;

    void copy(const Vehicle &other);

public:
    Vehicle(const Registration &myRegistration, std::string &description);
    Vehicle(const Vehicle &other);

    Person &getOwnerRef() const;
    Person *getOwnerPtr() const;
    Registration getReg() const;
    std::string getDesc() const;

    void print();
    void printVehicleAndOwner();

    Vehicle &operator=(const Vehicle &other);
    bool operator==(const Vehicle &other) const;
};

#endif
