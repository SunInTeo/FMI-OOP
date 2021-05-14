#include <iostream>
#include "Computer.h"

Computer::Computer(std::string myHDD, std::string myGPU, std::string myCPU, std::string myRAM)
                : myHDD(myHDD), myGPU(myGPU), myCPU(myCPU), myRAM(myRAM)
{
}

void Computer::printComputerConfiguration()
{
    myHDD.printHDD();
    myGPU.printGPU();
    myCPU.printCPU();
    myRAM.printRAM();
}