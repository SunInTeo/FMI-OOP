#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>

class VolumeOverflow:public std::exception
{
    const char *what() const throw()
    {
        return "Volume Overflow";
    }
};

class WeightOverflow:public std::exception
{
    const char *what() const throw()
    {
        return "Weight Overflow";
    }
};

#endif