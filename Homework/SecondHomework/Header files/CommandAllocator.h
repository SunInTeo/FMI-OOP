#ifndef COMMAND_ALLOCATOR_H
#define COMMAND_ALLOCATOR_H

#include <fstream>

#include "./PersonAndVehicleAllocator.h"
#include "./Command.h"
#include "./Person.h"
#include "./Vehicle.h"
#include "./Utils.h"

class CommandAllocator
{
private:
    std::vector<Command> commmandsArray;

    PersonAndVehicleAllocator myAllocator;

    void read(std::string fileName);
    void save(std::string path);
    void execCommand(const Command &myCmd, bool &keepReading);

public:
    CommandAllocator();
    CommandAllocator(std::string path);

    void start();
};
 
#endif
