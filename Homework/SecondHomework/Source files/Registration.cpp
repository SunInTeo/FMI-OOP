#include "../Header files/Registration.h"

bool Registration::isValid(const char *str)
{
    size_t len = strlen(str);

    if (len == 7 || len == 8)
    {
        if (str[0] < 'A' || str[0] > 'Z')
        {
            return false;
        }

        if (len == 8)
        {
            if (str[1] < 'A' || str[1] > 'Z')
            {
                return false;
            }
        }

        size_t index = (len == 8 ? 2 : 1);
        for (size_t i = index; i < len - 2; ++i)
        {
            if (str[i] < '0' || str[i] > '9')
            {
                return false;
            }
        }

        if (str[len - 2] < 'A' || str[len - 2] > 'Z')
        {
            return false;
        }
        if (str[len - 1] < 'A' || str[len - 1] > 'Z')
        {
            return false;
        }
    }
    else
    {
        return false;
    }

    return true;
}

Registration::Registration(const char *str)
{
    if (isValid(str))
    {
        strcpy(registrationNum, str);
    }
    else
    {
        throw std::invalid_argument("Invalid registration");
    }
}

const char *Registration::toCharArray() const
{
    return registrationNum;
}

Registration &Registration::operator=(const Registration &other)
{
    if (isValid(other.registrationNum))
    {
        strcpy(registrationNum, other.registrationNum);
    }
    else
    {
        throw std::invalid_argument("Cannot do that");
    }
    return *this;
}

Registration &Registration::operator=(const char *str)
{
    if (isValid(str))
    {
        strcpy(registrationNum, str);
    }
    else
    {
        throw std::invalid_argument("Cannot do that");
    }

    return *this;
}

bool Registration::operator==(const Registration &other) const
{
    bool areSame = true;
    for (size_t i = 0; i < strlen(other.registrationNum); ++i)
    {
        if (other.registrationNum[i] != registrationNum[i])
        {
            areSame = false;
        }
    }
    return areSame;
}

bool Registration::operator==(const char *str) const
{
    bool areSame = true;
    for (size_t i = 0; i < strlen(str); ++i)
    {
        if (str[i] != registrationNum[i])
        {
            areSame = false;
        }
    }
    return areSame;
}
