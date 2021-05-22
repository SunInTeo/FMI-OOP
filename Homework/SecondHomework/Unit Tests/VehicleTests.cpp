#include "../Header files/Vehicle.h"
#include "../Header files/catch2.hpp"

TEST_CASE("Creating a vehicle check")
{
    Registration tempReg("AB1234CD");
    std::string tempDesc = "Sample vehicle";
    Vehicle tempVhcl(tempReg, tempDesc);
    REQUIRE(tempVhcl.getReg() == tempReg);
    REQUIRE(tempVhcl.getDesc() == tempDesc);
    REQUIRE(tempVhcl.getOwnerPtr() == nullptr);
}

TEST_CASE("Overloaded operators check")
{
    SECTION("Operator(vehicle == vehicle) check")
    {
        Registration reg1("AB1234CD");
        std::string desc1 = "Sample Vehicle";
        Vehicle vhcl1(reg1, desc1);

        Registration reg2("AB1234CD");
        std::string desc2 = "Sample Vehicle";
        Vehicle vhcl2(reg2, desc2);

        REQUIRE(vhcl1 == vhcl2);
    }
    SECTION("Operator!(vehicle == vehicle) check")
    {
        Registration reg1("AB1234CD");
        std::string desc1 = "Sample Vehicle 1";
        Vehicle vhcl1(reg1, desc1);

        Registration reg2("AB5678CD");
        std::string desc2 = "Sample Vehicle 2";
        Vehicle vhcl2(reg2, desc2);

        REQUIRE(!(vhcl1 == vhcl2));
    }
}
