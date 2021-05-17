#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

class Command
{
private:
    std::string rawString;
    std::vector<std::string> arrString;

public:
    Command(std::string);

    std::string &operator[](std::size_t pos);
    const std::string &operator[](std::size_t pos) const;
    
    std::string getCommand();

    void print();
};

#endif
