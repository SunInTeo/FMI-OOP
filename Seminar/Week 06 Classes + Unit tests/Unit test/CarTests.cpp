#define CATCH_CONFIG_MAIN
#include <cstring>
#include "..\..\catch2\catch2.hpp"
#include "..\Solution\Car.h"

TEST_CASE("Car")
{
    Car car;

    SECTION("Default constructor check")
    {
        CHECK(car.getColor() == 0);
        CHECK(strcmp(car.getBrand(), "N/A") == 0);
        CHECK(strcmp(car.getLicensePlate(), "N/A") == 0);
    }
}

    