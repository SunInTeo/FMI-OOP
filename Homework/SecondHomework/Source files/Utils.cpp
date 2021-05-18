#include "../Header files/Utils.h"

#include <iostream>

std::string toUpperCase(const std::string &str)
{
    std::string tempStr(str);
    for (size_t i = 0; i < tempStr.length(); ++i)
    {
        if (tempStr[i] >= 'a' && tempStr[i] <= 'z')
        {
            tempStr[i] -= 'a' - 'A';
        }
    }
    return tempStr;
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
