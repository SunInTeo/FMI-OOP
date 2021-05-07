#include "Lecturer.h"

Lecturer::Lecturer(std::string name, std::size_t salary) : Person(name)
{
    this->salary = salary;
}
std::size_t Lecturer::getSalary() const
{
    return salary;
}