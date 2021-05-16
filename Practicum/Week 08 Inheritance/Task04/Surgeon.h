#ifndef SURGEON_H
#define SURGEON_H

#include "Doctor.h"

class Surgeon : public Doctor
{
public:
    Surgeon(std::string name);
    void performSurgery();
};

#endif