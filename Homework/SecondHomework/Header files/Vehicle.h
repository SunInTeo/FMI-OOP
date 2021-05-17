#ifndef VEHICLE_H
#define VEHICLE_H

#include "./Registration.h"
#include "./Person.h"
#include <string>
#include <vector>

class Person;
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

    Person &getOwner();
    Registration getReg() const;
    std::string getDesc() const;

    void print();
    void printVehicleAndOwner();

    Vehicle &operator=(const Vehicle &other);
    bool operator==(const Vehicle &other) const;
};

#endif
