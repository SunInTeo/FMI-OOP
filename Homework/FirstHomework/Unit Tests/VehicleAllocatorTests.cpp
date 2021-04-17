#include "..\..\catch2\catch2.hpp"
#include "..\Header files\VehicleAllocator.h"

// TO DO
// Check if the functions are working
TEST_CASE("Initialisation + generate func and adding vehicles to the garage check + destroy func check")
{
    VehicleAllocator vhclAlloc(10);
    REQUIRE(vhclAlloc.getAllVehiclesCount() == 0);
    REQUIRE(vhclAlloc.getVehiclesInMyGarageCount() == 0);

    Vehicle vhcl1 = vhclAlloc.generateNewVehicle("1234", "asd1", 2);
    Vehicle vhcl2 = vhclAlloc.generateNewVehicle("5678", "asd2", 2);
    Vehicle vhcl3 = vhclAlloc.generateNewVehicle("9999", "asd3", 2);
    REQUIRE(vhclAlloc.getAllVehiclesCount() == 3);
    REQUIRE(vhclAlloc.getVehiclesInMyGarageCount() == 0);

    vhclAlloc.addVehicleToMyGarage(vhcl1);
    vhclAlloc.addVehicleToMyGarage(vhcl2);
    REQUIRE(vhclAlloc.getAllVehiclesCount() == 3);
    REQUIRE(vhclAlloc.getVehiclesInMyGarageCount() == 2);

    Vehicle vhcl4 = vhclAlloc.generateNewVehicle("1111", "asd4", 123);
    bool throwedAnExc = false;
    try
    {
        vhclAlloc.addVehicleToMyGarage(vhcl4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        throwedAnExc = true;
    }
    REQUIRE(throwedAnExc);

    vhclAlloc.terminateVehicle("1234");
    vhclAlloc.terminateVehicle("5678");
    vhclAlloc.terminateVehicle("9999");
    vhclAlloc.terminateVehicle("1111");
    REQUIRE(vhclAlloc.getAllVehiclesCount() == 0);
    REQUIRE(vhclAlloc.getVehiclesInMyGarageCount() == 0);
}

TEST_CASE("Remove function check")
{
    VehicleAllocator vhclAlloc(10);
    REQUIRE(vhclAlloc.getAllVehiclesCount() == 0);
    REQUIRE(vhclAlloc.getVehiclesInMyGarageCount() == 0);

    Vehicle vhcl1 = vhclAlloc.generateNewVehicle("1234", "asd1", 2);
    Vehicle vhcl2 = vhclAlloc.generateNewVehicle("5678", "asd2", 2);
    Vehicle vhcl3 = vhclAlloc.generateNewVehicle("9999", "asd3", 2);
    REQUIRE(vhclAlloc.getAllVehiclesCount() == 3);
    REQUIRE(vhclAlloc.getVehiclesInMyGarageCount() == 0);

    vhclAlloc.addVehicleToMyGarage(vhcl1);
    vhclAlloc.addVehicleToMyGarage(vhcl2);
    REQUIRE(vhclAlloc.getAllVehiclesCount() == 3);
    REQUIRE(vhclAlloc.getVehiclesInMyGarageCount() == 2);

    vhclAlloc.addVehicleToMyGarage(vhcl3);
    REQUIRE(vhclAlloc.getAllVehiclesCount() == 3);
    REQUIRE(vhclAlloc.getVehiclesInMyGarageCount() == 3);

    vhclAlloc.removeVehicleFromMyGarage("1234");
    REQUIRE(vhclAlloc.getAllVehiclesCount() == 3);
    REQUIRE(vhclAlloc.getVehiclesInMyGarageCount() == 2);

    vhclAlloc.removeVehicleFromMyGarage(vhcl2);
    REQUIRE(vhclAlloc.getAllVehiclesCount() == 3);
    REQUIRE(vhclAlloc.getVehiclesInMyGarageCount() == 1);

    vhclAlloc.terminateVehicle("1234");
    vhclAlloc.terminateVehicle("5678");
    vhclAlloc.terminateVehicle("9999");
    REQUIRE(vhclAlloc.getAllVehiclesCount() == 0);
    REQUIRE(vhclAlloc.getVehiclesInMyGarageCount() == 0);
}

TEST_CASE("Clean vehicles from Garage and clean all vehicles check")
{
    VehicleAllocator vhclAlloc(10);
    REQUIRE(vhclAlloc.getAllVehiclesCount() == 0);
    REQUIRE(vhclAlloc.getVehiclesInMyGarageCount() == 0);

    Vehicle vhcl1 = vhclAlloc.generateNewVehicle("1234", "asd1", 2);
    Vehicle vhcl2 = vhclAlloc.generateNewVehicle("5678", "asd2", 2);
    Vehicle vhcl3 = vhclAlloc.generateNewVehicle("9999", "asd3", 2);
    REQUIRE(vhclAlloc.getAllVehiclesCount() == 3);
    REQUIRE(vhclAlloc.getVehiclesInMyGarageCount() == 0);

    vhclAlloc.addVehicleToMyGarage(vhcl1);
    vhclAlloc.addVehicleToMyGarage(vhcl2);
    vhclAlloc.addVehicleToMyGarage(vhcl3);
    REQUIRE(vhclAlloc.getAllVehiclesCount() == 3);
    REQUIRE(vhclAlloc.getVehiclesInMyGarageCount() == 3);

    vhclAlloc.cleanVehiclesInMyGarage();
    REQUIRE(vhclAlloc.getAllVehiclesCount() == 3);
    REQUIRE(vhclAlloc.getVehiclesInMyGarageCount() == 0);

    vhclAlloc.cleanAllVehicles();
    REQUIRE(vhclAlloc.getAllVehiclesCount() == 0);
    REQUIRE(vhclAlloc.getVehiclesInMyGarageCount() == 0);
}