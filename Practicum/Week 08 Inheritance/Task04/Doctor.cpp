#include "Doctor.h"

Doctor::Doctor(std::string name) : name(name)
{
    //this->name = name;
}

void Doctor::performSurgery()
{
    cout << "Surgery performermed by " << name << endl;
}