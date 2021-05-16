#include <iostream>
#include "Computer.h"

int main ()
{
    Computer myComputer1("1024", "3090", "i7", "64");
    Computer myComputer2("512", "3070", "i7", "16");

    myComputer1.printComputerConfiguration();
    std::cout << std::endl;
    myComputer2.printComputerConfiguration();

    return 0;
}