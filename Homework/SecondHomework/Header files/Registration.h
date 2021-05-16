#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <iostream>
#include <cstring>
#include <exception>

using std::size_t;

class Registration
{
private:
    char registrationNum[9];
    bool isValid(const char *str);

public:
    Registration() = delete;
    Registration(const char *str);

    const char *toString() const;

    Registration &operator=(const Registration &other);
    Registration &operator=(const char *str);
    bool operator==(const char *str) const;
};

#endif
