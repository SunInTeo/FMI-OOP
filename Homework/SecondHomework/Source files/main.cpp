#include <iostream>
#include "../Header files/CommandAllocator.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        CommandAllocator myCmdAlloc;
        myCmdAlloc.start();
    }
    else if (argc == 2)
    {
        CommandAllocator myCmdAlloc((std::string)argv[1]);
    }
    else
    {
        std::cerr << "Too many arguments!\n";
        return 1;
    }

    return 0;
}