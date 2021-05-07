#include "Student.h"

Student::Student(std::string name, std::size_t number) : Person(name)
{
    this->number = number;
}
std::size_t Student::getNumber() const
{
    return number;
}