#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : virtual public Person
{
private:
    std::size_t number;

public:
    Student(std::string name, std::size_t number);
    std::size_t getNumber() const;
};

#endif