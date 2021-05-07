#include "Person.h"

Person::Person(std::string name)
{
    this->name = name;
}
std::string Person::getName() const
{
    return name;
}