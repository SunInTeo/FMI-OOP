#include <iostream>
#include <cstring>
#include "Parking.h"

using std::cout;
using std::endl;

void Parking::copy(const Parking &other)
{
    this->companyName = new (std::nothrow) char[strlen(other.companyName) + 1];
    if (!this->companyName)
    {
        cout << "Memory problem\n";
        return;
    }
    strcpy(this->companyName, other.companyName);

    this->owner = other.owner;
    this->capacity = other.capacity;

    this->cars = new(std::nothrow) Car[this->capacity];
    if (!this->cars)
    {
        cout << "Memory problem\n";
        return;
    }

    for (int i = 0; i < other.size; ++i)
    {
        this->cars[i] = other.cars[i];
    }
}

void Parking::deallocate()
{
    if (this->companyName)
    {
        delete[] this->companyName;
    }

    if (this->cars)
    {
        delete[] this->cars;
    }
}

void Parking::resize()
{
    this->capacity *= 2;

    Car *newCars = new (std::nothrow) Car[this->capacity];
    if (!newCars)
    {
        cout << "Memory problem\n";
        return;
    }

    for (int i = 0; i < this->size; ++i)
    {
        newCars[i] = this->cars[i];
    }
    delete[] this->cars;

    this->cars = newCars;
}

Parking::Parking() : owner()
{
    this->companyName = nullptr;
    this->capacity = 2;
    this->cars = new (std::nothrow) Car[this->capacity];
    if (!this->cars)
    {
        cout << "Memory problem\n";
        return;
    }
    this->size = 0;
}

Parking::Parking(const char *_companyName, const Person &_owner, const Car *_cars,
                 const size_t _size, const size_t _capacity)
{
    this->companyName = new (std::nothrow) char[strlen(_companyName) + 1];
    if (!this->companyName)
    {
        cout << "Memory problem\n";
        return;
    }
    strcpy(this->companyName, _companyName);

    this->owner = _owner;
    this->capacity = _capacity;

    this->cars = new(std::nothrow) Car[this->capacity];
    if (!this->cars)
    {
        cout << "Memory problem\n";
        return;
    }

    for (int i = 0; i < _size; ++i)
    {
        this->cars[i] = _cars[i];
    }
}

Parking::Parking(const Parking &other)
{
    copy(other);
}

Parking &Parking::operator=(const Parking &other)
{
    if (this != &other)
    {
        deallocate();
        copy(other);
    }

    return *this;
}

char *Parking::getCompanyName() const { return this->companyName; }
Person Parking::getOwner() const { return this->owner; }
Car *Parking::getCars() const { return this->cars; }
size_t Parking::getSize() const { return this->size; }
size_t Parking::getCapacity() const { return this->capacity; }

void Parking::setCompanyName(const char *_companyName)
{
    if (this->companyName)
    {
        delete[] this->companyName;
    }
    this->companyName = new (std::nothrow) char[strlen(_companyName) + 1];
    if (!this->companyName)
    {
        cout << "Memory problem\n";
        return;
    }
    strcpy(this->companyName, _companyName);
}

void Parking::setOwner(const Person &_owner)
{
    this->owner = _owner;
}

void Parking::setCars(const Car *_cars, const size_t _size)
{
    if (this->cars)
    {
        delete[] this->cars;
    }

    this->cars = (_size > this->capacity) ? (new (std::nothrow) Car[_size]) : (new (std::nothrow) Car[this->capacity]);
    if (!this->cars)
    {
        cout << "Memory problem\n";
        return;
    }

    for (int i = 0; i < _size; ++i)
    {
        this->cars[i] = _cars[i];
    }
}

void Parking::setCapacity(const size_t _capacity)
{
    this->capacity = _capacity;
}

void Parking::addCar(const Car &car)
{
    if (this->size == this->capacity)
    {
        resize();
    }

    for (int i = 0; i < this->size; ++i)
    {
        if (strcmp(cars[i].getLicensePlate(), car.getLicensePlate()) == 0)
        {
            cout << "A car with the same license plate already exists in the parking" << endl;
        }
    }

    this->cars[this->size] = car;
    ++this->size;
}

void Parking::removeCar(const int index)
{
    if (index >= this->size)
    {
        cout << "Invalid index." << endl;
        return;
    }

    for (int i = index; i < this->size - 1; ++i)
    {
        this->cars[i] = this->cars[i + 1];
    }

    --this->size;
}

void Parking::printAllCars()
{
    cout << "Size: " << this->size << endl;
    cout << "Capacity: " << this->capacity << endl;
    cout << ((double)this->size / (double)this->capacity) * 100 << "% full" << endl;

    for (int i = 0; i < this->size; ++i)
    {
        cout << "Car #" << i + 1 << "->" << endl;
        cars[i].printInfoCar();
        cout << "\n----------------------------------\n";
    }
}

Person Parking::getOwnerByLicensePlate(const char *licensePlate)
{
    Person result;
    for (int i = 0; i < this->size; ++i)
    {
        if (strcmp(licensePlate, cars[i].getLicensePlate()) == 0)
        {
            result = cars[i].getOwner();
        }
    }

    return result;
}

Car *Parking::getCarsByOwner(const char *name, size_t &count)
{
    // counting how many cars the person has
    for (int i = 0; i < this->size; ++i)
    {
        if (strcmp(cars[i].getOwner().getName(), name) == 0)
        {
            ++count;
        }
    }

    if (count == 0)
    {
        cout << "This persons owns 0 cars." << endl;
        return nullptr;
    }

    Car *result = new (std::nothrow) Car[count];
    if (!result)
    {
        cout << "Memory problem\n";
        return nullptr;
    }

    int index = 0;
    for (int i = 0; i < this->size; ++i)
    {
        if (strcmp(cars[i].getOwner().getName(), name) == 0)
        {
            result[index++] = cars[i];
        }
    }

    return result;
}

Parking::~Parking()
{
    deallocate();
}