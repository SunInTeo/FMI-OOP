#include <iostream>
#include <cstring>
#include "Car.h"

using std::cout;
using std::endl;

void Car::copy(const Car &other)
{
    this->owner = other.owner;

    this->brand = new (std::nothrow) char[strlen(other.brand) + 1];
    if (!this->brand)
    {
        cout << "Memory problem\n";
        return;
    }
    strcpy(this->brand, other.brand);

    this->licensePlate = new (std::nothrow) char[strlen(other.licensePlate) + 1];
    if (!this->licensePlate)
    {
        cout << "Memory problem\n";
        return;
    }
    strcpy(this->licensePlate, other.licensePlate);

    this->color = other.color;
}

void Car::deallocate()
{
    if (this->brand)
    {
        delete[] this->brand;
    }

    if (this->licensePlate)
    {
        delete[] this->licensePlate;
    }
}

Car::Car()
{
    this->brand = nullptr;
    this->licensePlate = nullptr;
    this->color = UNKNOWN;
}

Car::Car(const Person &_owner, const char *_brand, const char *_licensePlate, const Color _color)
{
    this->owner = _owner;

    this->brand = new (std::nothrow) char[strlen(_brand) + 1];
    if (!this->brand)
    {
        cout << "Memory problem\n";
        return;
    }
    strcpy(this->brand, _brand);

    this->licensePlate = new (std::nothrow) char[strlen(_licensePlate) + 1];
    if (!this->licensePlate)
    {
        cout << "Memory problem\n";
        return;
    }
    strcpy(this->licensePlate, _licensePlate);

    this->color = _color;
}

Car::Car(const Car &other)
{
    copy(other);
}

Car &Car::operator=(const Car &other)
{
    if (this != &other)
    {
        deallocate();
        copy(other);
    }

    return *this;
}

Person Car::getOwner() const { return this->owner; }
char *Car::getBrand() const { return this->brand; }
char *Car::getLicensePlate() const { return this->licensePlate; }
Color Car::getColor() const { return this->color; }

void Car::setOwner(const Person &_owner)
{
    this->owner = _owner;
}

void Car::setBrand(const char *_brand)
{
    if (this->brand)
    {
        delete[] this->brand;
    }

    this->brand = new(std::nothrow) char[strlen(_brand) + 1];
    if (!this->brand)
    {
        cout << "Memory problem\n";
        return;
    }
    strcpy(this->brand, _brand);
}

void Car::setLicensePlate(const char *_licensePlate)
{
    if (this->licensePlate)
    {
        delete[] this->licensePlate;
    }

    this->licensePlate = new(std::nothrow) char[strlen(_licensePlate) + 1];
    if (!this->licensePlate)
    {
        cout << "Memory problem\n";
        return;
    }
    strcpy(this->licensePlate, _licensePlate);
}

void Car::setColor(const Color _color)
{
    this->color = _color;
}

void Car::printInfoCar()
{
    cout << "Owner's ";
    this->owner.printInfo();
    cout << "Brand: " << this->brand << endl;
    cout << "License plate: " << this->licensePlate << endl;
    cout << "Color: ";
    switch (this->color)
    {
    case RED:
        cout << "Red";
        break;
    case BLUE:
        cout << "Blue";
        break;
    case BLACK:
        cout << "Black";
        break;
    case WHITE:
        cout << "White";
        break;
    case GRAY:
        cout << "Gray";
        break;
    default:
        cout << "Unknown";
        break;
    }

    cout << endl;
}

Car::~Car()
{
    deallocate();
}