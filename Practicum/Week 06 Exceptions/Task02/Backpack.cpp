#include <iostream>
#include "Backpack.h"

using std::cout;
using std::endl;


void Backpack::copy(const Backpack &other)
{
    this->size = other.size;

    try
    {
        this->itemsArray = new Item[this->size + 1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    for(int i = 0; i < this->size; ++i)
    {
        this->itemsArray[i] = other.itemsArray[i];
    }

    this->maxVolume = other.maxVolume;
    this->maxWeight = other.maxWeight;

}

void Backpack::deallocate()
{
    if(this->itemsArray)
    {
        delete[] this->itemsArray;
    }
    this->itemsArray = nullptr;
    this->size = 0;
    this->maxVolume = 0;
    this->maxWeight = 0;
}

Backpack::Backpack()
{
    this->itemsArray = nullptr;
    this->size = 0;
    this->maxVolume = 0;
    this->maxWeight = 0;
}
Backpack::Backpack(double maxVolume, double maxWeight)
{
    this->itemsArray = nullptr;
    this->size = 0;
    this->maxVolume = maxVolume;
    this->maxWeight = maxWeight;
}
Backpack::Backpack(const Backpack &other)
{
    copy(other);
}
Backpack::~Backpack()
{
    deallocate();
}
Backpack &Backpack::operator=(const Backpack &other)
{
    if(this != &other)
    {
        deallocate();
        copy(other);
    }

    return *this;
}

void Backpack::add(const Item &item)
{
    try
    {
        if(item.getVolume() > this->maxVolume)
        {
            throw VolumeOverflow();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        if(item.getWeight() > this->maxWeight)
        {
            throw WeightOverflow();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Item *newItems;
    try
    {
        newItems = new Item[this->size + 1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    for(int i = 0; i < this->size; ++i)
    {
        newItems[i] = this->itemsArray[i];
    }
    if(this->itemsArray)
    {
        delete[] itemsArray;
    }
    
    this->itemsArray = newItems;
    this->itemsArray[this->size++] = item;
    this->maxWeight -= item.getWeight();
    this->maxVolume -= item.getVolume();
}

int Backpack::getSize() const
{
    return this->size;
}

double Backpack::leftVolume() const
{
    return this->maxVolume;
}

double Backpack::leftWeight() const
{   
    return this->maxWeight;
}

Item &Backpack::operator[](int index)
{
    try
    {
        if(index >= this->size)
        {
            throw std::out_of_range("Out of range");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return itemsArray[index];
}