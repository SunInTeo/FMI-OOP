#include <iostream>
#include <cstring>
#include "Item.h"

using std::cout;
using std::endl;

void Item::copy(const Item &other)
{
    try
    {
        this->name = new char[strlen(other.name) + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    this->volume = other.volume;
    this->weight = other.weight;
}
void Item::deallocate()
{
    if (this->name)
    {
        delete[] this->name;
    }

    this->name = nullptr;
    this->volume = 0.0;
    this->weight = 0.0;
}
Item::Item()
{
    this->name = nullptr;
    this->volume = 0.0;
    this->weight = 0.0;
}
Item::Item(const char *name, const double volume, const double weight)
{
    try
    {
        this->name = new char[strlen(this->name) + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    strcpy(this->name, name);

    this->volume = volume;
    this->weight = weight;
}
Item::Item(const Item &other)
{
    copy(other);
}
Item::~Item()
{
    deallocate();
}

char *Item::getName() const { return this->name; }
double Item::getVolume() const { return this->volume; }
double Item::getWeight() const { return this->weight; }

Item &Item::operator=(const Item &other)
{
    if (this != &other)
    {
        deallocate();
        copy(other);
    }

    return *this;
}

bool Item::operator==(const Item &other) const
{
    return !strcmp(this->name, other.name) && this->volume == other.volume && this->weight == other.weight;
}

bool Item::operator>(const Item &other) const
{
    return (this->volume > other.volume) || (this->volume == other.volume && this->weight > other.weight);
}