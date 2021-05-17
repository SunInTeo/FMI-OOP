#include "../Header files/Person.h"

Person::Person(std::string name, unsigned int uid) : name(name), uid(uid)
{
}

void Person::acquire(Vehicle &myVhcl)
{
    if (myVhcl.owner != nullptr)
    {
        myVhcl.owner->release(myVhcl.getReg());
    }

    vehiclesArray.push_back(&myVhcl);
    myVhcl.owner = this;
}

void Person::release(const Registration &other)
{
    bool isFound = false;
    for (size_t i = 0; i < vehiclesArray.size(); ++i)
    {
        if (!strcmp(vehiclesArray.at(i)->getReg().toCharArray(), other.toCharArray()))
        {
            vehiclesArray.at(i)->owner = nullptr;
            vehiclesArray.erase(vehiclesArray.begin() + i);
            isFound = true;
        }
    }

    if (!isFound)
    {
        throw std::invalid_argument("No such vehicle owned by this person");
    }
}

void Person::releaseAll()
{
    for (size_t i = 0; i < vehiclesArray.size(); ++i)
    {
        vehiclesArray.at(i)->owner = nullptr;
    }

    vehiclesArray.clear();
}

bool Person::doesOwn(const Registration &other)
{
    for (size_t i = 0; i < vehiclesArray.size(); ++i)
    {
        if (!strcmp(vehiclesArray.at(i)->getReg().toCharArray(), other.toCharArray()))
        {
            return true;
        }
    }

    return false;
}

std::string Person::getName() const
{
    return name;
}
unsigned int Person::getUid() const
{
    return uid;
}

void Person::print()
{
    std::cout << name << " (" << uid << ")";
}

void Person::printWithVehicles()
{
    Person::print();
    if (vehiclesArray.size() != 0)
    {
        std::cout << "->\n ";
        for (std::size_t i = 0; i < vehiclesArray.size(); ++i)
        {
            vehiclesArray[i]->print();
        }
    }
}
