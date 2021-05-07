#ifndef LECTURER_H
#define LECTURER_H

#include "Person.h"

class Lecturer : virtual public Person
{
private:
    std::size_t salary;

public:
    Lecturer(std::string name, std::size_t salary);
    std::size_t getSalary() const;
};

#endif