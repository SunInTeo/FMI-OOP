#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Human
{
protected:
    std::string name;
    std::string family;
    unsigned int age;

public:
    Human(std::string name, std::string family, unsigned int age);

    void print();
};

#endif