#include <iostream>
#include <fstream>
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
        std::cout << "Opening file...\n";
        std::string tempStr(argv[1]);
        CommandAllocator myCmdAlloc(tempStr);
        myCmdAlloc.start();
    }
    else
    {
        std::cerr << "Too many arguments!\n";
        return 1;
    }

    return 0;
}