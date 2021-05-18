#include "../Header files/Utils.h"

#include <iostream>

std::string toUpperCase(std::string str)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 'a' - 'A';
        }
    }
    return str;
}

const unsigned int stringToInt(const std::string &str)
{
    unsigned int res = 0;
    for (std::size_t i = 0; i < str.size(); i++)
    {
        res += (str[i] - '0') * (pow(10, str.size() - i - 1));
    }
    return res;
}
