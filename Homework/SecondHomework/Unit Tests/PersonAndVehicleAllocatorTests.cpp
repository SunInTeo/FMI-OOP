#include "../Header files/PersonAndVehicleAllocator.h"
#include "../Header files/Utils.h"
#include "../Header files/catch2.hpp"

TEST_CASE("Creating and removing a person check")
{
    PersonAndVehicleAllocator myAllocator;
    myAllocator.createPerson("Person1", "123");
    unsigned int uid = stringToInt("123");

    REQUIRE(myAllocator.doesExistP(uid));
    myAllocator.remove("123");
    REQUIRE(!myAllocator.doesExistP(uid));
}

TEST_CASE("Creating and removing a vehicle check")
{
    PersonAndVehicleAllocator myAllocator;
    myAllocator.createVehicle("AB1234CD", "Vehicle 1");

    Registration reg("AB1234CD");
    REQUIRE(myAllocator.doesExistV(reg));
    myAllocator.remove("AB1324CD");
    REQUIRE(!myAllocator.doesExistV(reg));
}

TEST_CASE("Acquiring and releasing vehicles check")
{
    PersonAndVehicleAllocator myAllocator;
    myAllocator.createPerson("Person 1", "123");
    myAllocator.createVehicle("AB1234CD", "Vehicle 1");
    Registration reg("AB1234CD");

    Person *person = myAllocator.getPersonByID(123);
    Vehicle *vehicle = myAllocator.getVehicleByID(reg);

    myAllocator.acquire("123", "AB1234CD");
    REQUIRE(person->doesOwn(reg));
    REQUIRE(vehicle->getOwnerPtr() == person);

    myAllocator.release("123", "AB1234CD");
    REQUIRE(!person->doesOwn(reg));
    REQUIRE(vehicle->getOwnerPtr() == nullptr);
}

TEST_CASE("Removing people check")
{
    PersonAndVehicleAllocator myAllocator;
    myAllocator.createPerson("Person 1", "123");
    myAllocator.createVehicle("AB1234CD", "Vehicle 1");
    myAllocator.createVehicle("AB5678CD", "Vehicle 2");
    Registration reg1("AB1234CD");
    Registration reg2("AB5678CD");

    myAllocator.acquire("123", "AB1234CD");
    myAllocator.acquire("123", "AB5678CD");

    myAllocator.remove("123");
    unsigned int uid = stringToInt("123");
    REQUIRE(!myAllocator.doesExistP(uid));

    Vehicle *vehicle1 = myAllocator.getVehicleByID(reg1);
    Vehicle *vehicle2 = myAllocator.getVehicleByID(reg2);
    REQUIRE(vehicle1->getOwnerPtr() == nullptr);
    REQUIRE(vehicle2->getOwnerPtr() == nullptr);
}
TEST_CASE("Removing vehicles check")
{
    PersonAndVehicleAllocator myAllocator;
    myAllocator.createPerson("Person 1", "123");
    myAllocator.createVehicle("AB1234CD", "Vehicle 1");
    myAllocator.createVehicle("AB5678CD", "Vehicle 2");
    Registration reg1("AB1234CD");
    Registration reg2("AB5678CD");

    myAllocator.acquire("123", "AB1234CD");
    myAllocator.acquire("123", "AB5678CD");

    myAllocator.remove("AB5678CD");
    REQUIRE(!myAllocator.doesExistV(reg2));

    Person *person = myAllocator.getPersonByID(123);
    REQUIRE(person->doesOwn(reg1));
    REQUIRE(!person->doesOwn(reg2));
}
TEST_CASE("Remove everything check")
{
    PersonAndVehicleAllocator myAllocator;
    myAllocator.createPerson("Person 1", "123");
    myAllocator.createVehicle("AB1234CD", "Vehicle 1");
    myAllocator.createVehicle("AB5678CD", "Vehicle 2");
    Registration reg1("AB1234CD");
    Registration reg2("AB5678CD");

    myAllocator.acquire("123", "AB1234CD");
    myAllocator.acquire("123", "AB5678CD");

    myAllocator.clear();
    unsigned int uid = stringToInt("123");
    REQUIRE(!myAllocator.doesExistP(uid));
    REQUIRE(!myAllocator.doesExistV(reg1));
    REQUIRE(!myAllocator.doesExistV(reg2));
}
