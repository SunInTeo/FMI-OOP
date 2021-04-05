#ifndef PARKING_H
#define PARKING_H

#include "Person.h"
#include "Car.h"

class Parking
{
    char *companyName;
    Person owner;
    Car *cars;
    size_t size;
    size_t capacity;

    void copy(const Parking &);
    void deallocate();
    void resize();

public:
    Parking();
    Parking(const char *, const Person &, const Car *,
            const size_t, const size_t);
    Parking(const Parking &);

    Parking &operator=(const Parking &);

    char *getCompanyName() const;
    Person getOwner() const;
    Car *getCars() const;
    size_t getSize() const;
    size_t getCapacity() const;

    void setCompanyName(const char *);
    void setOwner(const Person &);
    void setCars(const Car *_cars, const size_t);
    void setCapacity(const size_t);

    void addCar(const Car &);
    void removeCar(const int);

    void printAllCars();

    Person getOwnerByLicensePlate(const char *);
    Car *getCarsByOwner(const char *, size_t &);

    ~Parking();
};

#endif