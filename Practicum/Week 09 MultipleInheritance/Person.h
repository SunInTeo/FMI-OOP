#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person
{
private:
    std::string name;

public:
    Person(std::string name);
    std::string getName() const;
};

#endif