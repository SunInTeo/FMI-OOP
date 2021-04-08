#define CATCH_CONFIG_MAIN
#include "..\..\catch2\catch2.hpp"
#include "..\Solution\Parking.h"

TEST_CASE("Parking")
{
    Parking parking1;
    SECTION("Initialization check")
    {
        REQUIRE(parking1.getSize() == 0);
        REQUIRE(parking1.getCapacity() == 2);
    }

    Person ivan("Ivan", 10, true), georgi("Georgi", 19, false), spas("Spas", 19, true);
    Car car1(ivan, "BMW", "CA 1223 PB", GRAY), car2(georgi, "Opel", "OB 4356 BT", WHITE);

    parking1.addCar(car1);
    parking1.addCar(car2);

    SECTION("Adding cars check")
    {
        REQUIRE(parking1.getSize() == 2);
        REQUIRE(parking1.getCapacity() == 2);
    }

    Car car3(spas, "Bentley", "XX XXXX XX", RED);
    parking1.addCar(car3);

    SECTION("Resize check")
    {
        REQUIRE(parking1.getSize() == 3);
        REQUIRE(parking1.getCapacity() == 4);
    }

    parking1.removeCar(0);

    SECTION("Remove car check")
    {
        REQUIRE(parking1.getSize() == 2);
        REQUIRE(parking1.getCapacity() == 4);
    }

    parking1.removeCar(21);

    SECTION("Remove car with unexisting index check")
    {
        REQUIRE(parking1.getSize() == 2);
        REQUIRE(parking1.getCapacity() == 4);
    }

    parking1.addCar(car1);

    SECTION("Checking function getOwnerByLicensePlate")
    {
        SECTION("Correct data check")
        {
            REQUIRE(parking1.getOwnerByLicensePlate("CA 1223 PB") == ivan);
            REQUIRE(parking1.getOwnerByLicensePlate("OB 4356 BT") == georgi);
            REQUIRE(parking1.getOwnerByLicensePlate("XX XXXX XX") == spas);
        }
        SECTION("Invalid data check")
        {
            Person nullPerson;
            REQUIRE(parking1.getOwnerByLicensePlate("AA AAAA AA") == nullPerson);
        }
    }

    SECTION("Checking function getCarsByOwner")
    {
        Car *result;
        size_t sizeResult;

        SECTION("Find one car check")
        {
            result = parking1.getCarsByOwner(spas, sizeResult);
            REQUIRE(sizeResult == 1);
            REQUIRE(result[0] == car3);
            delete[] result;
        }

        Car newCar(ivan, "Aston Martin", "CT TTTT TT", RED);
        parking1.addCar(newCar);

        SECTION("Find two cars check")
        {
            result = parking1.getCarsByOwner(ivan, sizeResult);
            REQUIRE(sizeResult == 2);
            REQUIRE(result[0] == car1);
            REQUIRE(result[1] == newCar);
            delete[] result;
        }

        Person newPerson;

        SECTION("No cars check")
        {
            result = parking1.getCarsByOwner(newPerson, sizeResult);
            REQUIRE(sizeResult == 0);
            REQUIRE(result == nullptr);
        }
    }
}