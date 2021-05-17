#include "./Header files/Utils.h"

std::string toUpperCase(const std::string &str)
{
    std::string newStr(str);
    for (size_t i = 0; i < newStr.length(); ++i)
    {
        newStr[i] = toupper(newStr[i]);
    }
    return newStr;
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
