#include "../Header files/Registration.h"
#include "../Header files/catch2.hpp"

TEST_CASE("Creating and validating a registration check")
{

    SECTION("Correct registration(length = 8)")
    {
        bool isRegValid = true;
        try
        {
            Registration reg("AB1324CD");
        }
        catch (const std::exception &e)
        {
            isRegValid = false;
        }
        REQUIRE(isRegValid);
    }

    SECTION("Correct registration(length = 7)")
    {
        bool isRegValid = true;
        try
        {
            Registration reg("A1234BC");
        }
        catch (const std::exception &e)
        {
            isRegValid = false;
        }
        REQUIRE(isRegValid);
    }

    SECTION("Incorrect registration #1")
    {
        bool isRegValid = true;
        try
        {
            Registration reg1("AB1234C");
        }
        catch (const std::exception &e)
        {
            isRegValid = false;
        }
        REQUIRE(!isRegValid);
    }

    SECTION("Incorrect registration #2")
    {
        bool isRegValid = true;
        try
        {
            Registration reg("AB123456");
        }
        catch (const std::exception &e)
        {
            isRegValid = false;
        }
        REQUIRE(!isRegValid);
    }

    SECTION("Incorrect registration #3")
    {
        bool isRegValid = true;
        try
        {
            Registration reg("A1234BCD");
        }
        catch (const std::exception &e)
        {
            isRegValid = false;
        }
        REQUIRE(!isRegValid);
    }

    SECTION("Incorrect registration #4")
    {
        bool isRegValid = true;
        try
        {
            Registration reg("AB123CD");
        }
        catch (const std::exception &e)
        {
            isRegValid = false;
        }
        REQUIRE(!isRegValid);
    }

    SECTION("wrong, too many numbers")
    {
        bool isRegValid = true;
        try
        {
            Registration reg("AB123456CD");
        }
        catch (const std::exception &e)
        {
            isRegValid = false;
        }
        REQUIRE(!isRegValid);
    }
}

TEST_CASE("Overloaded operators check")
{

    SECTION("Operator == (Registration == Registration) and copy constructor check")
    {
        Registration reg1("AB1234CD");
        Registration reg2("AB1234CD");
        REQUIRE(reg1 == reg2);

        Registration reg3("AB1111CD");
        Registration reg4 = reg3;
        REQUIRE(reg3 == reg4);
    }
    SECTION("Operator !(Registration == Registration)")
    {
        Registration reg1("AB1234CD");
        Registration reg2("AB5678CD");
        REQUIRE(!(reg1 == reg2));
    }

    SECTION("Operator == (Registration == char*) and Operator = check")
    {
        Registration reg1("AB1234CD");
        char registration1[9] = "AB1234CD";
        REQUIRE(reg1 == registration1);

        char registration2[9] = "AB5678CD";
        Registration reg2 = registration2;
        REQUIRE(reg2 == registration2);
    }
    SECTION("Operator !(Registration == char*)")
    {
        Registration reg1("AB1234CD");
        char registration[9] = "AB5678CD";
        REQUIRE(!(reg1 == registration));
    }
}

TEST_CASE("Function toCharArray() check")
{
    Registration reg("AB1234CD");
    bool isSame = (reg == "AB1234CD") ? true:false;
    REQUIRE(isSame);
}
