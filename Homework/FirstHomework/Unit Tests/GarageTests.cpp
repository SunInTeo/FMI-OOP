#include "..\..\catch2\catch2.hpp"
#include "..\Header files\Garage.h"

TEST_CASE("Insert function check")
{
    SECTION("Test with correct arguments")
    {
        Garage myGarage(3);
        Vehicle v1("1324", "asd1", 1);
        Vehicle v2("5678", "asd2", 1);
        myGarage.insert(v1);
        bool testPassed = false;
        try
        {
            myGarage.insert(v2);
        }
        catch (const std::exception &e)
        {
            testPassed = true;
        }
        REQUIRE(testPassed == false);
    }
    SECTION("Testing adding a car that exceeds the limits of our myGarageage")
    {
        Garage myGarage(3);
        Vehicle v1("1234", "asd1", 2);
        Vehicle v2("5678", "asd2", 2);
        myGarage.insert(v1);
        bool testPassed = true;
        try
        {
            myGarage.insert(v2);
        }
        catch (const std::exception &e)
        {
            testPassed = false;
        }
        REQUIRE(testPassed == false);
    }
    SECTION("Testing with an already existing car in the myGarageage")
    {
        Garage myGarage(2);
        Vehicle v1("1234", "asd1", 1);
        myGarage.insert(v1);
        bool testPassed = false;
        try
        {
            myGarage.insert(v1);
        }
        catch (const std::exception &e)
        {
            testPassed = true;
        }
        REQUIRE(testPassed == true);
    }
}

TEST_CASE("at() function check")
{
    Garage myGarage(10);
    Vehicle v1("1234", "asd1", 2);
    Vehicle v2("5678", "asd2", 2);
    Vehicle v3("9999", "asd3", 2);
    myGarage.insert(v1);
    myGarage.insert(v2);
    myGarage.insert(v3);

    REQUIRE(!strcmp(myGarage.at(0).registration(), "1234"));
    REQUIRE(!strcmp(myGarage.at(0).description(), "asd1"));

    REQUIRE(!strcmp(myGarage.at(1).registration(), "5678"));
    REQUIRE(!strcmp(myGarage.at(1).description(), "asd2"));

    REQUIRE(!strcmp(myGarage.at(2).registration(), "9999"));
    REQUIRE(!strcmp(myGarage.at(2).description(), "asd3"));

    bool testPassed = false;
    try
    {
        std::size_t temp = myGarage.at(3).space();
    }
    catch (std::out_of_range)
    {
        testPassed = true;
    }
    REQUIRE(testPassed == true);
}

TEST_CASE("Operator[] check")
{
    Garage myGarage(10);
    Vehicle v1("1234", "asd1", 2);
    Vehicle v2("5678", "asd2", 2);
    Vehicle v3("9999", "asd3", 2);
    myGarage.insert(v1);
    myGarage.insert(v2);
    myGarage.insert(v3);

    REQUIRE(!strcmp(myGarage[0].registration(), "1324"));
    REQUIRE(!strcmp(myGarage[0].description(), "asd1"));

    REQUIRE(!strcmp(myGarage[1].registration(), "5678"));
    REQUIRE(!strcmp(myGarage[1].description(), "asd2"));

    REQUIRE(!strcmp(myGarage[2].registration(), "9999"));
    REQUIRE(!strcmp(myGarage[2].description(), "asd3"));
}
TEST_CASE("clear() function check/ size() function check/ empty() function check")
{
    Garage myGarage(10);
    Vehicle v1("1234", "asd1", 2);
    Vehicle v2("5678", "asd2", 2);

    myGarage.insert(v1);
    myGarage.insert(v2);
    REQUIRE(myGarage.size() == 2);
    REQUIRE(myGarage.empty() == false);

    myGarage.clear();
    REQUIRE(myGarage.size() == 0);
    REQUIRE(myGarage.empty() == true);
}

TEST_CASE("erase() function check")
{
    Garage myGarage(20);
    Vehicle v1("1234", "asd1", 2);
    Vehicle v2("5678", "asd2", 2);
    Vehicle v3("9999", "asd3", 2);
    Vehicle v4("1111", "asd4", 2);

    myGarage.insert(v1);
    myGarage.insert(v2);
    myGarage.insert(v3);
    REQUIRE(myGarage.size() == 3);

    myGarage.erase("9999");
    REQUIRE(myGarage.size() == 2);

    myGarage.insert(v4);
    REQUIRE(myGarage.size() == 3);
}

TEST_CASE("Find() function check")
{
    Garage myGarage(20);
    Vehicle v1("1234", "asd1", 2);
    Vehicle v2("5678", "asd2", 2);
    Vehicle v3("9999", "asd3", 2);
    Vehicle v4("1111", "asd4", 2);
    myGarage.insert(v1);
    myGarage.insert(v2);
    myGarage.insert(v3);
    myGarage.insert(v4);

    const Vehicle *found1 = myGarage.find("1234");
    REQUIRE(!strcmp(found1->registration(), "1234"));

    const Vehicle *found2 = myGarage.find("9999");
    REQUIRE(!strcmp(found2->registration(), "9999"));

    const Vehicle *found3 = myGarage.find("5454");
    REQUIRE(found3 == nullptr);
}