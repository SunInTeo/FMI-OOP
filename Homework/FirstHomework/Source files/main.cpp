//#include <iostream>
#include "..\Header files\VehicleAllocator.h"

using std::cin;
using std::cout;
using std::endl;

const int MAX_STRING_SIZE = 100;

/*
Sample program showing creating/adding/removing vehicles
*/
int main()
{
    VehicleAllocator vhclAlloc(30);

    Vehicle vhcl1 = vhclAlloc.generateNewVehicle("1234", "asd1", 3);
    Vehicle vhcl2 = vhclAlloc.generateNewVehicle("5678", "asd2", 4);
    Vehicle vhcl3 = vhclAlloc.generateNewVehicle("9999", "asd3", 5);

    vhclAlloc.addVehicleToMyGarage(vhcl1);
    vhclAlloc.addVehicleToMyGarage(vhcl2);
    vhclAlloc.addVehicleToMyGarage(vhcl3);
    vhclAlloc.printVehiclesFromMyGarage();

    cout<<"\n---------------------------------------------\n";

    vhclAlloc.removeVehicleFromMyGarage(vhcl1);
    vhclAlloc.printVehiclesFromMyGarage();
    vhclAlloc.removeVehicleFromMyGarage(vhcl3);
    vhclAlloc.printVehiclesFromMyGarage();

    vhclAlloc.cleanAllVehicles();
    return 0;
}
