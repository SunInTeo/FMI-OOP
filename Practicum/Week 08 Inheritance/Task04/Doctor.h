#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Doctor
{
protected:
    std::string name;

public:
    Doctor(std::string name);

    void performSurgery();
};

#endif