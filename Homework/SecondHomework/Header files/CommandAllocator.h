#ifndef COMMAND_ALLOCATOR_H
#define COMMAND_ALLOCATOR_H

#include <fstream>

#include "./PersonAndVehicleAllocator.h"
#include "./Command.h"
//#include "./Vehicle.h"

class CommandAllocator
{
private:
    std::vector<Command> commmandsArray;

    PersonAndVehicleAllocator myAllocator;

    void read(std::string fileName);
    void save(std::string path);
    void execCommand(const Command &myCmd, std::istream& istr);

public:
    CommandAllocator();
    CommandAllocator(std::string path);

    void start();
};
 
#endif
