#include <iostream>
#include "dentist.h"

Dentist::Dentist(std::string name) : Doctor(name) {}

void Dentist::performSurgery()
{
    cout << "You went to the dentist." << endl;
    Doctor::performSurgery();
}