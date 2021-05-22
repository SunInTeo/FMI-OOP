#include "../Header files/Vehicle.h"
#include "../Header files/catch2.hpp"

TEST_CASE("Creating a person check")
{

    bool didThrow = false;
    try
    {
        std::string name = "Name Surname";
        unsigned int uid = 123;
        Person person(name, uid);
        REQUIRE(person.getName() == name);
        REQUIRE(person.getUid() == uid);
    }
    catch (const std::exception &e)
    {
        didThrow = true;
    }
    REQUIRE(!didThrow);
}

TEST_CASE("Other functions check")
{
    SECTION("acquire() +  doesOwn() + release() functions check (single vehicle)")
    {
        std::string name1 = "Name1 Surname1";
        unsigned int uid1 = 1;
        Person person1(name1, uid1);
        char regStr1[9] = "AB1234CD";
        Registration reg1(regStr1);
        std::string desc1 = "Vehicle 1";
        Vehicle vehicle1(reg1, desc1);
        REQUIRE(!person1.doesOwn(vehicle1.getReg()));
        person1.acquire(vehicle1);
        REQUIRE(person1.doesOwn(vehicle1.getReg()));
        REQUIRE(vehicle1.getOwnerRef().getUid() == person1.getUid());
    }

    SECTION("acquire() +  doesOwn() + release() functions check (multiple vehicles)")
    {
        std::string name1 = "Name1 Surname1";
        unsigned int uid1 = 1;
        Person person1(name1, uid1);

        char regStr1[9] = "AB1234CD";
        Registration reg1(regStr1);
        std::string desc1 = "Vehicle 1";
        Vehicle vehicle1(reg1, desc1);

        char regStr2[9] = "AB5678CD";
        Registration reg2(regStr2);
        std::string desc2 = "Vehicle 2";
        Vehicle vehicle2(reg2, desc2);

        char regStr3[9] = "AB9999CD";
        Registration reg3(regStr3);
        std::string desc3 = "Vehicle 3";
        Vehicle vehicle3(reg3, desc3);

        person1.acquire(vehicle1);
        REQUIRE(person1.doesOwn(vehicle1.getReg()));
        REQUIRE(vehicle1.getOwnerRef().getUid() == person1.getUid());

        person1.acquire(vehicle2);
        REQUIRE(person1.doesOwn(vehicle2.getReg()));
        REQUIRE(vehicle2.getOwnerRef().getUid() == person1.getUid());

        person1.acquire(vehicle3);
        REQUIRE(person1.doesOwn(vehicle3.getReg()));
        REQUIRE(vehicle3.getOwnerRef().getUid() == person1.getUid());

        person1.releaseAll();
        REQUIRE(!person1.doesOwn(vehicle1.getReg()));
        REQUIRE(!person1.doesOwn(vehicle2.getReg()));
        REQUIRE(!person1.doesOwn(vehicle3.getReg()));
    }

    SECTION("Calling function acquire() when a vehicle already has an owner")
    {
        std::string name1 = "Name1 Surname1";
        unsigned int uid1 = 1;
        Person person1(name1, uid1);

        std::string name2 = "Name2 Surname2";
        unsigned int uid2 = 2;
        Person person2(name2, uid2);

        char regStr1[9] = "AB1234CD";
        Registration reg1(regStr1);
        std::string desc1 = "Vehicle 1";
        Vehicle vehicle1(reg1, desc1);

        person1.acquire(vehicle1);
        REQUIRE(person1.doesOwn(vehicle1.getReg()));
        person2.acquire(vehicle1);
        REQUIRE(!person1.doesOwn(vehicle1.getReg()));
        REQUIRE(person2.doesOwn(vehicle1.getReg()));
    }

    SECTION("Calling function release() when a person doesn't own the requested vehicle")
    {
        std::string name1 = "Name1 Surname1";
        unsigned int uid1 = 1;
        Person person1(name1, uid1);

        std::string name2 = "Name2 Surname2";
        unsigned int uid2 = 2;
        Person person2(name2, uid2);

        char regStr1[9] = "AB1234CD";
        Registration reg1(regStr1);
        std::string desc1 = "Vehicle 1";
        Vehicle vehicle1(reg1, desc1);

        person1.acquire(vehicle1);
        REQUIRE(person1.doesOwn(vehicle1.getReg()));

        bool didThrow = false;
        try
        {
            person2.release(vehicle1.getReg());
        }
        catch (const std::exception &e)
        {
            didThrow = true;
        }
        REQUIRE(didThrow);
    }
}
