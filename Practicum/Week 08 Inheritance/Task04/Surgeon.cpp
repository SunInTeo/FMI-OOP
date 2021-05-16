#include "Surgeon.h"

Surgeon::Surgeon(std::string name) : Doctor(name) {}

void Surgeon::performSurgery()
{
    cout << "You went to a surgeon" << endl;
    Doctor::performSurgery();
}